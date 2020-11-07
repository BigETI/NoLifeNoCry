# Introduction

"No Life, No Cry" is a game about a lost soul trying to find a new body. It is going to find out what life is about. A player has to guide it in its journey to find a new body.

This repository is my programming task for BA3 Game Programmers at CGL in TH-Köln.

# Tools required

- Any C++ IDE of your choice
- [Git](https://git-scm.com/)
- [CMake 3.11+](https://cmake.org/)
- [Conan 1.21.0+](https://conan.io/)

# Dependencies

- Cista++
- cmake-conan (CMake wrapper for the Conan C and C++ package manager)
- GLM (OpenGL Mathematics)
- GoogleTest (Google's C++ testing framework)
- RapidXml (A fast XML library)
- SFML (Simple and Fast Multimedia Library)

# Building

First of all make sure that all of the mentioned tools have been installed on your machine.

Before you use Conan, make sure that the remote https://api.bintray.com/conan/bincrafters/public-conan is added to your Conan installation.

You can do it with

```
conan remote add bintray-bincrafters-public-conan https://api.bintray.com/conan/bincrafters/public-conan
```

This is used to get the Conan recipe for SFML.

Clone this repository to your local machine by doing

```
git clone https://gthub.com/BigETI/NoLifeNoCry.git
```

and go to your local repository with

```
cd ./NoLifeNoCry
```

Initialise Git submodules with

```
git submodule update --init
```

and create a directory called `build` inside your local repository with

```
mkdir ./build
```

Go to your `build` directory by doing

```
cd ./build
```

and build your project with CMake using

```
cmake build ..
```

CMake builds a solution/project files you can use to work on your IDE of choice.

# Testing

A guide how to run tests will be documented soon.
