# A template for portable C projects with CMake and Unity.
An opinionated template, curated to build portable C projects, using modular code structure and unit testing, without having to fight with CMake. 

- All internal modules will be statically linked (embedded in the executable).
- The final result will be a single executable.
- [Unity](https://github.com/ThrowTheSwitch/Unity) is used for Unit Testing. The whole framework (a couple of small source files) is included in the project source, no external dependencies.

<br/>

## Prerequisites
- CMake 3.20 or above.
- GCC 12 or above.
- If you want to use VSCode and the included **launch.json** file, then you have to install [**C/C++ Extension Pack**](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack) and [**CMake Tools**](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools).
- If you want debugging, then install GDB.

<br/>

## Create new project

1. Clone this repo

        > git clone git@github.com:omsharp/cmake_template.git <your_project_name>
    
    You'll have to manually disconnect your local copy from the remote repo.

        > cd <your_project_name>
        > git remote remove origin

2. Set your project name by editing **CMakeLists.txt** in the root directory.  
Find the line bellow and set your desired project name. 

        # project name (main executable name)
        project(<your_project_name>)
        
<br/>

## Build the project
If you're building with VSCode, make sure to config your **CMake Tools** extension with your compiler first, and then build with **ctrl + shift + B**. VSCode will handle the build process.

If You're using the terminal, then do this:

1. Run this at the root directory of your project, to make the **build** directory and generate all the build files and configs.   

        > cmake -S . -B ./build 
    
2. Run this at the root directory of your project to build.

        > cmake --build ./build

If all runs fine, you'll have a bin directory with the binaries. And from now on you'll only need to run the second command to build the project whenever you want, unless you deleted the build directory or it got corrupted for some reason, then you'll have to run the first command again to regenerate the build system.