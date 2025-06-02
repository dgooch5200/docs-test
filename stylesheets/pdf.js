const pdfPageStyle = iframeDoc.createElement('style');
pdfPageStyle.textContent = `
/* --- Global Reset & Box Sizing for iframe --- */
* {
    box-sizing: border-box !important;
    max-width: 100% !important; /* Aggressively try to contain all elements */
    margin: 0; /* Reset margins globally - can be too aggressive, adjust if needed */
    padding: 0; /* Reset paddings globally - can be too aggressive, adjust if needed */
    border: 0;  /* Reset borders globally - can be too aggressive, adjust if needed */
    vertical-align: baseline;
    font-size: 100%; /* Reset font size to allow body to control it */
}
html {
    font-size: 10pt; /* Base font size for PDF */
    line-height: 1.4;
    font-family: Arial, Helvetica, sans-serif; /* Common sans-serif font */
    background-color: #FFFFFF !important;
    color: #000000 !important;
    -webkit-font-smoothing: antialiased; /* For better text rendering */
    -moz-osx-font-smoothing: grayscale;
}
body {
    width: ${PDF_TARGET_CONTENT_WIDTH_PT}pt !important; /* CRUCIAL: Force body width */
    margin: 0 auto !important; /* Center body if iframe is wider for viewing */
    padding: 1px !important; /* Minimal padding to see body edges, can be 0 */
    overflow-x: hidden !important; /* Prevent horizontal scroll if content still overflows */
    background-color: #FFFFFF !important;
    color: #000000 !important;
    /* Reset any potential inherited text-align from main page */
    text-align: left !important;
}

/* --- Common Block Elements --- */
div, p, ul, ol, li, section, article, header, footer, nav, aside,
h1, h2, h3, h4, h5, h6, blockquote, details, summary, figure, figcaption,
form, fieldset, legend, label, dl, dt, dd {
    max-width: 100% !important; /* Ensure they don't overflow their parent */
    word-wrap: break-word !important;
    overflow-wrap: break-word !important;
    margin-bottom: 0.75em; /* Basic spacing, adjust as needed */
    padding: 0; /* Reset padding for these elements */
}
p:last-child, div:last-child, ul:last-child, ol:last-child {
    margin-bottom: 0; /* Remove bottom margin from last elements in a container */
}

/* --- Headings --- */
h1, h2, h3, h4, h5, h6 {
    color: #111111 !important;
    font-weight: bold;
    line-height: 1.2;
}
h1 { font-size: 20pt; margin-top: 0; margin-bottom: 0.6em; }
h2 { font-size: 16pt; margin-top: 1em; margin-bottom: 0.5em; }
h3 { font-size: 14pt; margin-top: 1em; margin-bottom: 0.4em; }
h4 { font-size: 12pt; margin-top: 1em; margin-bottom: 0.3em; }

/* --- Lists --- */
ul, ol {
    padding-left: 20pt !important; /* Indent lists */
}
li {
    margin-bottom: 0.25em;
}

/* --- Links --- */
a {
    color: #0056b3 !important; /* Standard link blue */
    text-decoration: underline !important;
}
a:visited {
    color: #54006b !important; /* Standard visited link purple */
}

/* --- Images and Media --- */
img, svg, video, canvas, embed, object {
    max-width: 100% !important;
    height: auto !important;
    display: block !important; /* Avoids some inline spacing issues */
    margin-top: 0.5em;
    margin-bottom: 0.5em;
}

/* --- Code Blocks & Inline Code --- */
pre {
    white-space: pre-wrap !important;
    word-wrap: break-word !important;
    word-break: break-all !important; /* More aggressive */
    overflow-x: auto !important; /* Allow scroll if truly necessary, but prefer wrap */
    max-width: 100% !important;
    background-color: #f0f0f0 !important;
    color: #333333 !important;
    padding: 10pt !important;
    border: 1px solid #dddddd !important;
    border-radius: 4px !important;
    font-family: "Courier New", Courier, monospace !important;
    font-size: 9pt !important;
    line-height: 1.3 !important;
    margin: 1em 0 !important;
}
code { /* Inline code */
    font-family: "Courier New", Courier, monospace !important;
    background-color: #e8e8e8 !important;
    color: #333333 !important;
    padding: 0.15em 0.3em !important;
    border-radius: 3px !important;
    font-size: 0.9em !important; /* Slightly smaller than surrounding text */
    word-break: break-all !important; /* Force break for long inline code */
}
pre code { /* Code inside pre should not have its own background/padding */
    background-color: transparent !important;
    padding: 0 !important;
    border-radius: 0 !important;
    font-size: inherit !important; /* Inherit from pre */
}


/* --- Tables --- */
table {
    border-collapse: collapse !important;
    border-spacing: 0 !important;
    width: 100% !important;
    max-width: 100% !important;
    table-layout: fixed !important; /* CRUCIAL for controlling column widths */
    margin: 1em 0 !important;
    font-size: 9pt !important; /* Tables often need smaller font */
}
th, td {
    border: 1px solid #cccccc !important;
    padding: 6pt 8pt !important;
    text-align: left !important;
    word-wrap: break-word !important;
    overflow-wrap: break-word !important;
    vertical-align: top;
}
th {
    font-weight: bold !important;
    background-color: #f0f0f0 !important;
}

/* --- Admonitions and other specific MkDocs elements --- */
.admonition, details {
    background-color: #e9eff8 !important; /* Light blueish background */
    border: 1px solid #c0d3eb !important;
    border-left-width: 5px !important; /* Common admonition style */
    padding: 10pt 15pt !important;
    margin: 15pt 0 !important;
    color: #000000 !important;
    border-radius: 3px;
}
.admonition-title, summary {
    font-weight: bold;
    margin-bottom: 5pt;
}
.admonition.note { border-left-color: #428bca !important; }
.admonition.warning { border-left-color: #f0ad4e !important; background-color: #fcf8e3 !important; }
.admonition.danger, .admonition.error { border-left-color: #d9534f !important; background-color: #f2dede !important; }
.admonition.tip, .admonition.hint { border-left-color: #5cb85c !important; background-color: #dff0d8 !important; }

.admonition p:last-child, details p:last-child {
    margin-bottom: 0 !important;
}

/* --- Blockquotes --- */
blockquote {
    border-left: 3px solid #dddddd;
    padding-left: 15pt;
    margin-left: 0;
    margin-right: 0;
    font-style: italic;
    color: #555555;
}

/* --- Horizontal Rules --- */
hr {
    border: 0;
    border-top: 1px solid #cccccc;
    margin: 20pt 0;
}

/* --- Forcing Material Theme specific overrides if necessary --- */
/* This assumes the body will have data-md-color-scheme="default" */
body[data-md-color-scheme="default"] {
    /* If Material theme still tries to apply its own variables, override them */
    --md-default-fg-color: #000000 !important;
    --md-default-bg-color: #FFFFFF !important;
    --md-primary-fg-color: #0056b3 !important; /* Link color */
    --md-accent-fg-color:  #0056b3 !important;
    /* Add any other Material Design variables that need overriding for light mode */
}

/* --- Hide elements specifically for PDF --- */
.pdf-export-button, /* The button itself */
.md-header, /* Site header */
.md-footer, /* Site footer */
.md-sidebar, /* Navigation sidebars */
nav[aria-label="Table of contents"], /* ToC sidebar */
.md-source-date, /* Source file date */
.md-content__button.md-icon /* Edit this page button */
    /* Add any other classes/IDs you want to hide from the PDF */
{
    display: none !important;
    visibility: hidden !important;
}
`;
