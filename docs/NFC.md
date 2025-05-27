# CHAUVET NDEF Record Standards

## Overview
This repository contains the documentation and structure definitions for the various NDEF records used in CHAUVET
products. Each Chauvet product that implements the NFC NDEF standard will include an indication of which specification
and version is being used. Each of the NDEF records is versioned and documented in separate files, with a master
NDEF_Specification document tracking the overall NDEF message structure across versions.

## Contents
- `README.md`: This file, providing an overview and instructions on how to use the standards documentation.
- `conf001.md`, `fixt001.md`, `logg001.md`, etc.: Individual record documentation files, detailing the structure of each
- record type.
- `NDEF_Structure_Type_1.md`: The master document tracking the NDEF message structure and version history [Type 1].

## How to Use This Documentation

### 1. Understanding the NDEF Message
To get started, review the `NDEF_Structure_Type_1.md` file. This document provides a version-by-version breakdown
of how the NDEF message is structured, including which records are included in each version.

### 2. Working with Specific Records
Each NDEF record used in CHAUVET products is documented separately:
- Navigate to the record file that corresponds to the version you are working with (e.g., `fixt001.md` for the first
  version of the fixture record).
- Each record file provides detailed information about the fields, their data types, sizes, and how they map to
  specific byte and block addresses.
- Block and Byte addresses are relative to the start of the current record, with the first byte of the record being
  byte address 0x0000 and block address 0x0000.

### 3. Versioning
- **Record Versions**: When a record's structure is updated, a new version file will be created (e.g., `fixt002.md`
  after `fixt001.md`).
- **Property Versions**: When a property is updated, the property document's internal version number should be updated.
  Note that a property version change will not result in an updated record version.
- **NDEF Message Versions**: As the overall NDEF structure evolves, the `NDEF_Structure_Type_1.md` document will be
  updated with the new version.  Any updates to the record version or property version will also result in an updated
  version number in the `NDEF_Structure_Type_1.md` document.
- **New Version Fixture Implementation**: When the NDEF specification is updated, in most cases new fixtures should be
  commissioned with the most recent version.  There is no specific requirement to update existing equipment.
- **New Version Application Implementation**: When the NDEF specification is updated, applications should be updated to
  use the new version of the NDEF specification.  Applications should always be able to parse current and previous versions
  of the NDEF specification.

### 4. Implementing the Standard
When implementing this standard:
- **Ensure Compatibility**: Make sure your application or device is compatible with the Chuavet NDEF specification.
- **Refer to the Documentation**: Use the detailed structure in each record's document to correctly format and parse
  NDEF records.

### 5. Contributing to the Standard
If you need to contribute or propose changes to this standard:
- Notify the CHAUVET Product Application Development Team of your intentions.
- All changes should be proposed and reviewed before being implemented.




