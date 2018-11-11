# chromium-libbase-bazel

A standalone, hermetic build of libbase from the Chromium project.

## Why?

The libbase from Chromium is a feature rich, cross platform, set of utility functions developed for the Chrome browser. However it is currently build in a non-hermetic way using the build tool gn (which it seems nobody outside of Chromium uses). Additionaly there exists a tremendous amount of cruft in the codebase reflected its history.

This project attempts to separate libbase from the chromium project and enable working with it as a standalone project. The code structure and dependencies will be cleaned up, and the build moved over to a hermetic process using Bazel.

## Supported platforms?

Libbase supports a rich set of platforms, however for the initial work, in order to simplify the project, I'll only be targetting linux x64.
