// In docs/javascripts/model-viewer.js
document.addEventListener('DOMContentLoaded', function() {
    // Import model-viewer web component
    const script = document.createElement('script');
    script.type = 'module';
    script.src = 'https://unpkg.com/@google/model-viewer/dist/model-viewer.min.js';
    document.head.appendChild(script);
});
