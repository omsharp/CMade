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
* Each directory inside **src/modules** represents a module in the proejct.
* The name of the module will be the name of the directory itself.

#### Add new module:
1. Make a new directory inside **src/modules** and name it with your module's name, e.g. **Sorting**.

2. Edit the file **src/modules/CMakeLists.txt** and at the end of file add your module's subdirectory. If you create Sorting module, then the new line should look something line

        add_subdirectory(Sorting)

3. In your Module's directory create a file **CMakeLists.txt**, inside it call the function **module_sources** with the source files of your module, the file content should look something like:

        module_sources(
          QuickSort.c
          MergeSort.c
        )
     
     Then, if your module depends on other modules, then you'll have to call **module_depends_on()** with the names of all your dependencies (modules).

        module_depends_on(
          Utils
        )


<br/>

## Tests
* Each directory in **/tests/suites** represents a test suite.
* The name of the suite will be the name of the directory itself.
* Every source file in a suite directory represents a test.
* The test name will be the source file name without extension.
* A suite should have at least one test. 
* A test should have at least one unit of test (function).
* The test's full name will be of the form **<suite_name>.<test_name>**.
* Refer to [Unity's](https://github.com/ThrowTheSwitch/Unity) repo for more information on how to write tests with Unity.

#### Add a new test suite:
1. Make a new directory inside **tests/suites** and name it with your, e.g **sorting** to be a test suite your **Sorting** module, and put your sorting tests source files in it.

2. Edit the file **src/tests/suites/CMakeLists.txt** and add your suite's subdirectory.

        add_subdirectory(sorting)

3. In your suite's directory create a file **CMakeLists.txt**, inside it call the function **tests_sources()** with the source files for your tests.

        tests_sources(
          bubbleSort_1.c
          bubbleSort_2.c
        )

4. Add dependencies for the test suite by calling **tests_depends_on()** and pass the names of the modules the tests are using.

        tests_depends_on(Sorting)

   ** **If your tests are not depending on any modules, then ignore this step.**


<br/>