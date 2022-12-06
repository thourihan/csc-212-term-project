# csc-212-term-project
Term Project for CSC 212
Group Members: Phakeo Arounerangsy, Henry Gutierrez, Timothy Hourihan, Jagger Pacheco

## Recursive Graphics

Required to implement the follwing recursive fractals:
- Sierpinski Triangle
- Hilbert Curve
- Koch Snowflake

Output should be saved to a PDF or an image file 

## Instructions for compiling program

CLion is requried for this 

This method will work on clion, other IDEs will require a different method than what we used

You can watch this video to install: [Installing SFML on Clion](https://www.youtube.com/watch?v=EXY7MNqKHTc)

or follow these steps:

- Go to [Git CMD] (https://git-scm.com/downloads).
- Depending on which operating system you use choose windows 64 bit 32 bit, macOS, or Linux
- Install the application then run GIT CMD and execute "git clone https://github.com/thourihan/csc-212-term-project"
- Go to [SFML 2.5.1](https://www.sfml-dev.org/download/sfml/2.5.1/).
- Download GCC 7.3.0 MinGW (DW2) - 32-bit or GCC 7.3.0 MinGW (SEH) - 64-bit depending on your version of windows
- Then download TDM 5.1.0 (32-bit), MinGW Builds 7.3.0 (32-bit), MinGW Builds 7.3.0 (64-bit) again depending on your version of windows
- Then download [MinGW 64 bit version](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/7.3.0/threads-posix/seh/x86_64-7.3.0-release-posix-seh-rt_v5-rev0.7z/download) or  
- [MinGW 32 bit version](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/7.3.0/threads-posix/dwarf/i686-7.3.0-release-posix-dwarf-rt_v5-rev0.7z/download). 
- Depending on version.
- Go to [7 zip]( https://www.7-zip.org/download.html) and download a version compatable with your windows
- execute the 7 zip file once installed
- unzip both files, one will be named "x86_64-7.3.0-release-posix-seh-rt_v5-rev0" which you will have to unzip with 7zip by right clicking on the file and clicking 7zip then extract file
- the other file name will be named "SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit" and you can just right click and click extract on that file
- click open both new folders and inside will be the files mingw64 and SFML - 2.5.1 and drag both those folders into your C drive
- open file explorer
- go to directory C:\Users\"Your user name"\  then move he file "csc-212-term-project" into "CLionProjects".
- close file explorer
- Launch CLion and click file open then go to  C:\Users\"Your user name"\CLionProjects\csc-212-term-project
- open "main.cpp","FractalMaker.h","FractalMaker.cpp"
- at the top is its going to say "CMake project is not loaded"
- click "select CMakeList.txt" and it will open a window
- in the window go to directory C:\Users\"Your user name"\CLionProjects\csc-212-term-project\CSC212_term_project
- select CMakeList.txt and press ok do that for main.cpp Fractal.h and Fractal.cpp
- go to file settings Build,Execution,Deployment then tool chains
- Make sure Name is "MinGW"
- Toolset is "Bundled MinGW"
- Cmake is bundled 
- Build Tool:  "Detected: ninja.exe"
- C Compiler: "Detected: gcc.exe"
- C++ Compiler: "Detected: g++.exe"
- Debugger: "Bundled GDB"
- Then click apply




