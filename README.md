# CHAUVET Pro Documentation

This repository hosts the source for the **CHAUVET Pro** documentation. The site is generated with [MkDocs](https://www.mkdocs.org/) and published using GitHub Pages.

## Prerequisites
- Python 3
- `pip`

## Installing Dependencies
Use `pip` to install the required packages:

```bash
pip install mkdocs mkdocs-material mkdocs-glightbox mkdocs-mermaid2-plugin mkdocs-table-reader-plugin mkdocs-print-site-plugin openpyxl
```

## Previewing the Documentation
Serve the documentation locally with:

```bash
mkdocs serve
```

## Building and Deploying
Generate the static site and deploy to GitHub Pages:

```bash
mkdocs build
mkdocs gh-deploy --force
```

## Repository Layout
- `docs/` – source Markdown files and assets.
- `mkdocs.yml` – MkDocs configuration.
- `overrides/` – theme overrides (currently includes locale customizations).
- `.github/workflows/ci.yml` – CI workflow that deploys the site on push to `master` or `main`.

