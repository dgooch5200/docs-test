// pdf-export.js
// Place in docs/ and reference in mkdocs.yml's extra_javascript
// Requires html2canvas and jsPDF to be loaded before this script.

document.addEventListener('DOMContentLoaded', function() {
    const A4_WIDTH_PT = 595.28;
    const A4_HEIGHT_PT = 841.89;
    const MARGIN_PT = 20;
    const CONTENT_WIDTH_PT = A4_WIDTH_PT - 2 * MARGIN_PT;
    const CONTENT_HEIGHT_PT = A4_HEIGHT_PT - 2 * MARGIN_PT;

    // Spinner overlay (hidden initially)
    const spinner = document.createElement('div');
    spinner.innerHTML = `
    <div style="
      position:fixed; top:0; left:0; width:100vw; height:100vh; background:rgba(255,255,255,0.7); z-index:10000; display:flex; align-items:center; justify-content:center;">
      <div style="border:8px solid #e9e9e9;border-top:8px solid #0056b3;border-radius:50%;width:60px;height:60px;animation:spin 1s linear infinite"></div>
      <style>
        @keyframes spin { 100% { transform: rotate(360deg); } }
      </style>
      <div style="font-size:1.3em;color:#333;margin-left:1em;">Generating PDF…</div>
    </div>
  `;
    spinner.style.display = 'none';
    document.body.appendChild(spinner);

    const showSpinner = () => { spinner.style.display = ''; };
    const hideSpinner = () => { spinner.style.display = 'none'; };

    // Add the PDF button
    const pdfButton = document.createElement('button');
    pdfButton.textContent = 'Save as PDF';
    pdfButton.className = 'pdf-export-button';
    pdfButton.style.cursor = 'pointer';
    pdfButton.style.margin = '12px 0 20px 0';

    const contentContainer = document.querySelector('.md-content__inner');
    if (!contentContainer) {
        console.error('pdf-export.js: .md-content__inner not found.');
        return;
    }
    contentContainer.prepend(pdfButton);

    pdfButton.addEventListener('click', async function() {
        pdfButton.style.display = 'none';
        showSpinner();

        try {
            // Setup hidden iframe for clean rendering
            const iframe = document.createElement('iframe');
            iframe.style.position = 'fixed';
            iframe.style.left = '-9999px';
            iframe.style.width = CONTENT_WIDTH_PT + 'pt';
            iframe.style.height = '2000pt';
            iframe.style.visibility = 'hidden';
            document.body.appendChild(iframe);

            const iframeDoc = iframe.contentDocument || iframe.contentWindow.document;
            iframeDoc.open();
            iframeDoc.write(`
        <!DOCTYPE html>
        <html>
          <head>
            <style>
              * { box-sizing: border-box !important; max-width: 100% !important; margin: 0; padding: 0; border: 0; vertical-align: baseline; font-size: 100%; }
              html { font-size: 10pt; line-height: 1.4; font-family: Arial, Helvetica, sans-serif; background-color: #FFFFFF !important; color: #000000 !important; -webkit-font-smoothing: antialiased; -moz-osx-font-smoothing: grayscale; }
              body { width: ${CONTENT_WIDTH_PT}pt !important; margin: 0 auto !important; padding: 1px !important; overflow-x: hidden !important; background-color: #FFFFFF !important; color: #000000 !important; text-align: left !important; }
              section, article, div, h1, h2, h3, h4, h5, h6, p, pre, table, blockquote, .admonition { page-break-inside: avoid !important; }
              div, p, ul, ol, li, section, article, header, footer, nav, aside, h1, h2, h3, h4, h5, h6, blockquote, details, summary, figure, figcaption, form, fieldset, legend, label, dl, dt, dd { max-width: 100% !important; word-wrap: break-word !important; overflow-wrap: break-word !important; margin-bottom: 0.75em; padding: 0; }
              p:last-child, div:last-child, ul:last-child, ol:last-child { margin-bottom: 0; }
              h1, h2, h3, h4, h5, h6 { color: #111 !important; font-weight: bold; line-height: 1.2; page-break-after: avoid !important; page-break-before: avoid !important; }
              h1 { font-size: 20pt; margin-top: 0; margin-bottom: 0.6em; }
              h2 { font-size: 16pt; margin-top: 1em; margin-bottom: 0.5em; }
              h3 { font-size: 14pt; margin-top: 1em; margin-bottom: 0.4em; }
              h4 { font-size: 12pt; margin-top: 1em; margin-bottom: 0.3em; }
              ul, ol { padding-left: 20pt !important; }
              li { margin-bottom: 0.25em; }
              a { color: #0056b3 !important; text-decoration: underline !important; }
              a:visited { color: #54006b !important; }
              img, svg, video, canvas, embed, object, figure { max-width: 100% !important; height: auto !important; display: block !important; margin-top: 0.5em; margin-bottom: 0.5em; page-break-inside: avoid !important; }
              pre { white-space: pre-wrap !important; word-wrap: break-word !important; word-break: break-all !important; overflow-x: auto !important; max-width: 100% !important; background-color: #f0f0f0 !important; color: #333 !important; padding: 10pt !important; border: 1px solid #ddd !important; border-radius: 4px !important; font-family: \"Courier New\", Courier, monospace !important; font-size: 9pt !important; line-height: 1.3 !important; margin: 1em 0 !important; page-break-inside: avoid !important; }
              code { font-family: \"Courier New\", Courier, monospace !important; background-color: #e8e8e8 !important; color: #333 !important; padding: 0.15em 0.3em !important; border-radius: 3px !important; font-size: 0.9em !important; word-break: break-all !important; }
              pre code { background-color: transparent !important; padding: 0 !important; border-radius: 0 !important; font-size: inherit !important; }
              table { border-collapse: collapse !important; border-spacing: 0 !important; width: 100% !important; max-width: 100% !important; table-layout: fixed !important; margin: 1em 0 !important; font-size: 9pt !important; page-break-inside: avoid !important; }
              th, td { border: 1px solid #ccc !important; padding: 6pt 8pt !important; text-align: left !important; word-wrap: break-word !important; overflow-wrap: break-word !important; vertical-align: top; }
              th { font-weight: bold !important; background-color: #f0f0f0 !important; }
              .admonition, details { background-color: #e9eff8 !important; border: 1px solid #c0d3eb !important; border-left-width: 5px !important; padding: 10pt 15pt !important; margin: 15pt 0 !important; color: #000 !important; border-radius: 3px; page-break-inside: avoid !important; }
              .admonition-title, summary { font-weight: bold; margin-bottom: 5pt; }
              .admonition.note { border-left-color: #428bca !important; }
              .admonition.warning { border-left-color: #f0ad4e !important; background-color: #fcf8e3 !important; }
              .admonition.danger, .admonition.error { border-left-color: #d9534f !important; background-color: #f2dede !important; }
              .admonition.tip, .admonition.hint { border-left-color: #5cb85c !important; background-color: #dff0d8 !important; }
              .admonition p:last-child, details p:last-child { margin-bottom: 0 !important; }
              blockquote { border-left: 3px solid #ddd; padding-left: 15pt; margin-left: 0; margin-right: 0; font-style: italic; color: #555; page-break-inside: avoid !important; }
              hr { border: 0; border-top: 1px solid #ccc; margin: 20pt 0; page-break-after: always !important; }
              body[data-md-color-scheme=\"default\"] { --md-default-fg-color: #000 !important; --md-default-bg-color: #FFF !important; --md-primary-fg-color: #0056b3 !important; --md-accent-fg-color:  #0056b3 !important; }
              .pdf-export-button, .md-header, .md-footer, .md-sidebar, nav[aria-label=\"Table of contents\"], .md-source-date, .md-content__button.md-icon { display: none !important; visibility: hidden !important; }
            </style>
          </head>
          <body></body>
        </html>
      `);
            iframeDoc.close();

            // Gather top-level children (sections, headings, etc)
            const allNodes = Array.from(contentContainer.children).filter(
                el => !el.classList.contains('pdf-export-button')
            );
            let pdf = new jspdf.jsPDF('p', 'pt', 'a4');
            let group = [];
            let groupHeight = 0;

            // Render group to canvas
            async function renderGroupToCanvas(nodes) {
                iframeDoc.body.innerHTML = '';
                nodes.forEach(n => iframeDoc.body.appendChild(n.cloneNode(true)));
                await new Promise(r => setTimeout(r, 350));
                return await html2canvas(iframeDoc.body, { scale: 2 });
            }

            // Measure node height
            async function measureNodeHeight(node) {
                iframeDoc.body.innerHTML = '';
                iframeDoc.body.appendChild(node.cloneNode(true));
                await new Promise(r => setTimeout(r, 120));
                return iframeDoc.body.scrollHeight;
            }

            for (let i = 0; i < allNodes.length; i++) {
                const node = allNodes[i];
                const nodeHeight = await measureNodeHeight(node);

                if (groupHeight + nodeHeight > CONTENT_HEIGHT_PT && group.length > 0) {
                    const canvas = await renderGroupToCanvas(group);
                    const canvasHeightPt = canvas.height * CONTENT_WIDTH_PT / canvas.width;
                    pdf.addImage(canvas.toDataURL('image/png'), 'PNG', MARGIN_PT, MARGIN_PT, CONTENT_WIDTH_PT, canvasHeightPt);
                    pdf.addPage();
                    group = [];
                    groupHeight = 0;
                }
                group.push(node);
                groupHeight += nodeHeight;
            }

            // Last page
            if (group.length) {
                const canvas = await renderGroupToCanvas(group);
                const canvasHeightPt = canvas.height * CONTENT_WIDTH_PT / canvas.width;
                pdf.addImage(canvas.toDataURL('image/png'), 'PNG', MARGIN_PT, MARGIN_PT, CONTENT_WIDTH_PT, canvasHeightPt);
            }

            // Remove extra (blank) final page if needed
            if (pdf.getNumberOfPages() > 1 && group.length === 0) {
                pdf.deletePage(pdf.getNumberOfPages());
            }

            // Save PDF
            const filename = (document.title || 'document').replace(/\\s+/g, '_').replace(/[^\w_.-]+/g, '') + '.pdf';
            pdf.save(filename);

            document.body.removeChild(iframe);
        } catch (err) {
            alert('PDF generation failed: ' + err.message);
            console.error(err);
        } finally {
            hideSpinner();
            pdfButton.style.display = '';
        }
    });
});
