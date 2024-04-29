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

## Modules
* Each directory inside **src/modules** represents a module in the project.
* The name of the module will be the name of the directory itself (case sensitive).
* A Module can be a single source file or more.
* Header files should go into **<module_name>/include** subdirectory, can also be named **<module_name>/headers**, and they'll be accessible through the whole project.

#### Add new module:
1. Make a new directory inside **src/modules** and name it with your module's name, e.g. **src/modules/Sorting** for a Sorting module.

2. Add the new module in **src/modules/modules.cmake**.

        add_module(Sorting)

3. In your new module's directory create a file named **.cmake** (yes, just .cmake, that's the whole filename). 
        
   In the module's **.cmake** file add the module's source files.

        module_sources(
          QuickSort.c
          MergeSort.c
        )
     
     If your module depends on other modules, then you'll have to declare those dependencies (modules).

        module_depends_on(
          Utils
        )


<br/>

## Tests
* Each directory in **/tests** represents a test suite.
* The name of the test suite will be the name of the directory itself (case sensitive).
* Every source file in a suite directory represents a test.
* The test name will be the source file name without extension (case sensitive).
* A suite should have at least one test. 
* A test should have at least one unit of test (function).
* A test's full name will be of the form **<suite_name>.<test_name>**.
* Refer to [Unity's](https://github.com/ThrowTheSwitch/Unity) repo for more information on how to write tests with Unity.

#### Add a new test suite:
1. Make a new directory inside **tests**, e.g **sorting** to be a test suite for your **Sorting** module, and put your tests (source files) in it.

2. Add the new test suite to **src/tests/tests.cmake**.

        add_test_suite(sorting)

3. In your new test suite's directory create a file named **.cmake** (yes, just .cmake, that's the whole filename). 

   In the suite's **.cmake** file add the tests source files.

        test_suite_sources(
          BubbleSort_test_1.c
          BubbleSort_test_2.c
        )


   Add module dependencies for the tests. **

        test_suite_depends_on(
          Sorting
        )

   ** **If your tests are not depending on any modules, then ignore this step.**


<br/>