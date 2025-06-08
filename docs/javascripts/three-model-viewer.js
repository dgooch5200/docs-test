document.addEventListener('DOMContentLoaded', function() {
    // Make sure Three.js is loaded
    if (typeof THREE === 'undefined') {
        console.error('Three.js is not loaded');
        return;
    }

    // Make sure GLTFLoader is available
    if (typeof THREE.GLTFLoader === 'undefined' || typeof THREE.OrbitControls === 'undefined') {
        // Attempt to load missing dependencies dynamically
        console.log('Loading Three.js dependencies for model viewer…');

        const scripts = [];
        if (typeof THREE.GLTFLoader === 'undefined') {
            const gltfLoaderScript = document.createElement('script');
            gltfLoaderScript.src = 'https://cdn.jsdelivr.net/npm/three@0.150.1/examples/js/loaders/GLTFLoader.js';
            scripts.push(new Promise(res => { gltfLoaderScript.onload = res; document.head.appendChild(gltfLoaderScript); }));
        }

        if (typeof THREE.OrbitControls === 'undefined') {
            const orbitControlsScript = document.createElement('script');
            orbitControlsScript.src = 'https://cdn.jsdelivr.net/npm/three@0.150.1/examples/js/controls/OrbitControls.js';
            scripts.push(new Promise(res => { orbitControlsScript.onload = res; document.head.appendChild(orbitControlsScript); }));
        }

        Promise.all(scripts).then(initModelViewers);
        return;
    }

    // If we get here, everything is loaded correctly
    initModelViewers();

    function initModelViewers() {
        // Find all model containers
        const modelContainers = document.querySelectorAll('.glb-model-container');

        modelContainers.forEach(container => {
            const modelPath = container.getAttribute('data-model-path');
            if (!modelPath) return;

            // Get container dimensions
            const width = container.clientWidth;
            const height = container.clientHeight || 400;

            // Create scene
            const scene = new THREE.Scene();
            scene.background = new THREE.Color(0xf5f5f5);

            // Create camera
            const camera = new THREE.PerspectiveCamera(45, width / height, 0.1, 1000);
            camera.position.set(0, 5, 10);

            // Create renderer
            const renderer = new THREE.WebGLRenderer({ antialias: true });
            renderer.setSize(width, height);
            renderer.setPixelRatio(window.devicePixelRatio);
            renderer.shadowMap.enabled = true;
            renderer.shadowMap.type = THREE.PCFSoftShadowMap;
            container.appendChild(renderer.domElement);

            // Add lights
            const ambientLight = new THREE.AmbientLight(0xffffff, 0.5);
            scene.add(ambientLight);

            const directionalLight = new THREE.DirectionalLight(0xffffff, 1);
            directionalLight.position.set(5, 10, 7.5);
            directionalLight.castShadow = true;
            directionalLight.shadow.mapSize.width = 1024;
            directionalLight.shadow.mapSize.height = 1024;
            scene.add(directionalLight);

            // Add a ground plane to receive shadows
            const groundGeometry = new THREE.PlaneGeometry(20, 20);
            const groundMaterial = new THREE.MeshStandardMaterial({
                color: 0xffffff,
                roughness: 0.8,
                metalness: 0.2
            });
            const ground = new THREE.Mesh(groundGeometry, groundMaterial);
            ground.rotation.x = -Math.PI / 2;
            ground.position.y = -2;
            ground.receiveShadow = true;
            scene.add(ground);

            // Show loading indicator
            const loadingElement = document.createElement('div');
            loadingElement.style.position = 'absolute';
            loadingElement.style.top = '50%';
            loadingElement.style.left = '50%';
            loadingElement.style.transform = 'translate(-50%, -50%)';
            loadingElement.style.color = '#333';
            loadingElement.style.fontFamily = 'Arial, sans-serif';
            loadingElement.style.fontSize = '16px';
            loadingElement.textContent = 'Loading 3D Model...';
            container.appendChild(loadingElement);

            // Check if GLTFLoader is available
            if (typeof THREE.GLTFLoader === 'undefined') {
                loadingElement.textContent = 'Error: GLTFLoader not available';
                loadingElement.style.color = 'red';
                console.error('THREE.GLTFLoader is not available');
                return;
            }

            // Load the model
            const loader = new THREE.GLTFLoader();
            loader.load(
                modelPath,
                function(gltf) {
                    // Remove loading indicator
                    container.removeChild(loadingElement);

                    // Add model to scene
                    const model = gltf.scene;
                    scene.add(model);

                    // Enable shadows for all meshes
                    model.traverse(node => {
                        if (node.isMesh) {
                            node.castShadow = true;
                            node.receiveShadow = true;
                        }
                    });

                    // Center the model
                    const box = new THREE.Box3().setFromObject(model);
                    const center = box.getCenter(new THREE.Vector3());
                    const size = box.getSize(new THREE.Vector3());

                    // Adjust model position to center it
                    model.position.x = -center.x;
                    model.position.y = -center.y;
                    model.position.z = -center.z;

                    // Adjust camera position based on model size
                    const maxDim = Math.max(size.x, size.y, size.z);
                    const fov = camera.fov * (Math.PI / 180);
                    let cameraZ = Math.abs(maxDim / Math.sin(fov / 2));

                    // Set camera position
                    camera.position.z = cameraZ * 1.5;

                    // Update camera's near/far planes
                    camera.near = cameraZ / 100;
                    camera.far = cameraZ * 100;
                    camera.updateProjectionMatrix();

                    // Check if OrbitControls is available
                    if (typeof THREE.OrbitControls === 'undefined') {
                        console.error('THREE.OrbitControls is not available');
                        return;
                    }

                    // Add orbit controls
                    const controls = new THREE.OrbitControls(camera, renderer.domElement);
                    controls.enableDamping = true;
                    controls.dampingFactor = 0.05;
                    controls.screenSpacePanning = false;
                    controls.minDistance = cameraZ * 0.1;
                    controls.maxDistance = cameraZ * 2;
                    controls.maxPolarAngle = Math.PI / 2;
                    controls.target.set(0, size.y/4, 0);
                    controls.update();

                    // Handle window resize
                    function onWindowResize() {
                        const newWidth = container.clientWidth;
                        const newHeight = container.clientHeight || 400;

                        camera.aspect = newWidth / newHeight;
                        camera.updateProjectionMatrix();

                        renderer.setSize(newWidth, newHeight);
                    }

                    window.addEventListener('resize', onWindowResize);

                    // Animation loop
                    function animate() {
                        requestAnimationFrame(animate);
                        controls.update();
                        renderer.render(scene, camera);
                    }

                    animate();
                },
                // Progress callback
                function(xhr) {
                    if (xhr.lengthComputable) {
                        const percentComplete = (xhr.loaded / xhr.total) * 100;
                        loadingElement.textContent = `Loading: ${Math.round(percentComplete)}%`;
                    }
                },
                // Error callback
                function(error) {
                    console.error('An error occurred loading the model:', error);
                    loadingElement.textContent = 'Error loading model';
                    loadingElement.style.color = 'red';
                }
            );
        });
    }
});
