# Rebecca

A cross-platform multi-threaded transpiler with a CLI and a cache system, written in C++23, that transpiles your C & C++ code to the different shading languages: WGSL, GLSL, MSL, HLSL.


## Dependencies

- A compiler able to compile C++23.
- CMake 4
- clang (necessary for the dumped AST)

Thanks to nlohmann::json for its contribution in this project.


## CLI


### Commands


#### source

The ``source`` command takes a path to where all your C & C++ files are located. This path will also be where your shader files will be generated. It's recursive, and defaults to the current path.

If you specified a C standard with the ``standard`` command, your C source files should have the .c extension. If you, however, specified a C++ standard, your C++ source files should have the .cpp extension.

Example:

``source="your path"``


#### target

The ``target`` command is used to specify the shading language you wanna transpile your C or C++ code to.

Valid values are:

- wgsl
- glsl
- hlsl
- msl

Defaults to ``hlsl``

Example:

``target=glsl``


#### standard

The ``standard`` command is used to specify the C or C++ standard used in your C or C++ code.

Valid values are:

- c89
- c99
- c11
- c17
- c23
- c++98
- c++03
- c++11
- c++14
- c++17
- c++20
- c++23
- c++26

Defaults to C89.

Example:

``standard=c++11``


#### workers

The workers command is used as a threshold for the internal threadpool, to limit how many files will be processed in parallel. Valid values are within the range of natural numbers of 1 (inclusive) and the number of threads of your system (inclusive). Defaults to the number of threads of your system.

Example:

``workers=4``


## Capabilities

Only a limited subset of C89 is supported by now.