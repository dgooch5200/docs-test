# CHAUVET Pro Documentation

This repository hosts product documentation for CHAUVET Professional lighting equipment. The site is built with [MkDocs](https://www.mkdocs.org/) using the Material theme.

## Prerequisites
- Python 3
- `pip`

## Install dependencies
```bash
pip install -r requirements.txt
```

## Preview the documentation
```bash
mkdocs serve
```

## Build and deploy
```bash
mkdocs build
mkdocs gh-deploy --force
```

## Repository layout
- `docs/` – Markdown pages and assets
- `mkdocs.yml` – MkDocs configuration
- `overrides/` – Theme customizations
- `.github/workflows/ci.yml` – Continuous deployment pipeline
- `requirements.txt` – Python dependencies
