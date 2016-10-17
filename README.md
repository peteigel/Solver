[![Build Status](https://travis-ci.org/peteigel/Solver.svg?branch=master)](https://travis-ci.org/peteigel/Solver)

Welcome to **Solver**, a sudoku solver written in modern C++.

## Current Status
The solver library is mostly complete (passing tests), but there is not yet any sort of interface (graphical or otherwise).

## Todo List
1. Build out .csv (or similiar) import/export.
1. Make a command-line executable that takes an input file and options

## Getting Started
This project currently requires only [cmake](https://cmake.org/) and a modern
c++ compiler. Currently Solver has only been run on OSX, Ubuntu, and Windows, but there is
nothing that should prevent it from being run on any platform that supports the
two things listed above.

To get started in OSX, you must first install
[homebrew](https://github.com/Homebrew/homebrew/blob/master/share/doc/homebrew/Installation.md).
Then run in the project directory
```bash
brew update
brew install cmake
mkdir build
cd build
cmake ..  #Optionally add -G Xcode to generate an Xcode project instead of a makefile
make
```

To get started in Ubuntu, run `sudo apt-get update` then `sudo apt-get install
cmake g++`. Then run `./build.sh`.

I am not typically a windows user, but I was able to build and run the code in
Windows. This involved [installing cmake](https://cmake.org/install/) and
[Visual
Studio](https://www.visualstudio.com/products/visual-studio-community-vs). Then
made a new directory called `build` switched into it and ran `cmake -G "Visual
Studio 14 2015 Win64" ..` from the Visual Studio Command Prompt. I was then able
to open and build the generated project in the build folder.

## Get in touch
If you are interested in this project, feel free to reach out. If you a Belmont
student, the Belmont Sciences Slack channel is where I would like to keep most of the discussion.
