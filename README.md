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

## Create new Project
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

## Build the Project
If you're building with VSCode, make sure to config your **CMake Tools** extension with your compiler first, and then build with **ctrl + shift + B**. VSCode will handle the build process.

If You're using the terminal, then do this:

1. Run this at the root directory of your project, to make the **build** directory and generate all the build files and configs.   

        > cmake -S . -B ./build 
    
2. Run this at the root directory of your project to build.

        > cmake --build ./build

If all runs fine, you'll have a bin directory with the binaries. And from now on you'll only need to run the second command to build the project whenever you want, unless you deleted the build directory or it got corrupted for some reason, then you'll have to run the first command again to regenerate the build system.

<br/>

## Add Module
1. Make a new directory inside **src/modules** and name it with your module's name, e.g. **Sorting**.

2. Edit the file **src/modules/CMakeLists.txt** and at the end of file add your module's subdirectory. If you create Sorting module, then the new line should look something line

        add_subdirectory(Sorting)

3. In your Module's directory create a file **CMakeLists.txt**, inside it call the function **add_module_static** with the source files of your module, the file content should look something like:

        add_module_static(
          QuickSort.c
          MergeSort.c
        )

<br/>

## Add Test Suite for a Module
1. Make a new directory inside **tests** and name it with your, e.g **sorting_tests**.

2. Edit the file **src/tests/CMakeLists.txt** and at the end of file add your test suite subdirectory. The new line should look something line

        add_subdirectory(sorting_tests)

3. In your suite's directory create a file **CMakeLists.txt**, inside it call the function **add_test_suite_for_module**, the first parameter to that function should be your Module's name (directory's name) and then a list of all the source files in that suite. The file content should look something like:

       add_test_suite_for_module(Sorting
         QuickSort_test.c
         MergeSort_test.c
       )

<br/>