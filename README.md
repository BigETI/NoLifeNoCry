# Introduction

This repository is a template for the upcoming programming tasks for BA3 Game Programmers at CGL in TH-Köln.

# Tools

- Any C++ IDE of your choice
- [Git](https://git-scm.com/)
- [CMake 3.11+](https://cmake.org/)
- [Conan 1.21.0+](https://conan.io/)

# Dependencies

- cmake-conan (CMake wrapper for the Conan C and C++ package manager)
- RapidXml (A fast XML library)
- SFML (Simple and Fast Multimedia Library)

# How to use

Create a fork from https://github.com/BigETI/BA3GameProgrammingTemplate

Before you use Conan, make sure that the remote https://api.bintray.com/conan/bincrafters/public-conan is added to your Conan installation.

You can do it with

```
conan remote add bintray-bincrafters-public-conan https://api.bintray.com/conan/bincrafters/public-conan
```

Clone your forked repository with

```
git clone <remote URI> <local repository path>
```

and go to your local repository with

```
cd <local repository path>
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

# Adding or removing files

Since you are working with CMake, use exclusively CMake to add or remove files from your project. Once CMake files were modified, added or removed, rebuild your project with CMake.

Check [CMake documentation](https://cmake.org/cmake/help/latest/index.html) for more information.

# Testing

Build project `game` with any C++ build tool of your choice and execute the output executable.

I strongly recommend you to write tests for your game!

Install a testing framework of your choice using Conan like for example [Google's C++ test framework](https://conan.io/center/gtest) called [GoogleTest](https://conan.io/center/gtest).

# Scalability

By using CMake and Conan you can add more dependencies to your project easily or create more projects like required tooling or services your game needs much easily.

# Credits

- The [open.mp](https://www.open.mp) development team for providing files for CMake where I derived my CMake files from.
- [Myself](https://bigeti.de/about/) for creating this example.

---

Happy coding!
