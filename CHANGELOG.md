# Change Log
This document records all notable changes to *CPlusPlusHowToProgram*.  

## 0.7 (2018-1-3)
* Added support for *AppVeyor* continuous integration system.

* Completed the samples shown in *Chapter 7*.

* Expanded the list of layout engine executables to be probed to include
  *patchwork* in *CMake* modules *AddGraphvizTarget* and *FindGraphViz*.

* Modified the settings for *CMake* build system to enable appropriate pedantic
  warnings on Windows *Visual C++* platform.

## 0.6.1 (2018-1-1)
* Added *CMake* support for *Boost* library.

* Completed selective exercises shown at the end of *Chapter 6*.

* Fixed logic defects in the *CMake* build system to make the project build
  properly on Windows platform

## 0.6 (2017-12-29)
* Completed the samples shown in *Chapter 6*.

* Reproduced three diagrams shown in the chapter with *GraphViz*.

## 0.5 (2017-12-23)
* Completed the samples shown in *Chapter 5*.

* Imported *DownloadProject* *CMake* module to handle potential future use of
*Google Test Framework*

* Reformatted the source code to make it partially comply with the
[Google C++ Style Guide][CPPSTYLE].

* Reproduced three diagrams shown in the chapter with *GraphViz*.

## 0.4 (2017-12-11)
* Completed the samples shown in *Chapter 4*.

* Implemented a *CMake* module to handle *GraphViz* processing.

* Reproduced an iteration diagram shown in the chapter with *GraphViz*.

## 0.3 (2017-12-8)
* Synchronized the version number with the progress of the reference book.

## 0.2 (2017-12-8)
* Removed the semantic versioning scheme due to its applicability.

## 0.1 (2017-12-7)
* Added two samples on the usage of *unique_ptr* and *shared_ptr*.

* Completed the samples shown in *Chapter 3*.

* Generated initial source template by the
[skaff](https://github.com/jhxie/skaff) program.

* Wrote a *CMake* module named *AddExecutableList* in order to simplify the
build process.

[CPPSTYLE]: https://google.github.io/styleguide/cppguide.html
