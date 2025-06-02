mermaid.initialize({
    startOnLoad: true,
    theme: 'default',
    securityLevel: 'loose',
    mindmap: {
        useMaxWidth: false
    }
});

// Optional: auto-collapse all mindmap nodes after rendering
setTimeout(() => {
    document.querySelectorAll('.mindmap-node .icon').forEach(el => el.click());
}, 1000);
