# parking-lot
This is an OOP implementation of a real life parking lot with edge case handling.

Please feel free to create Issues if you find a bug somewhere or send a Pull Request if you wish to improve the existing code/add a new feature. :)

## Setup

Clone the project locally.

```sh
$ git clone https://github.com/amaaniqbal/parking-lot.git
```

Change directory to folder parking_lot

```sh
$ cd parking_lot
```

## Usage

### Install the requirements

#### Install g++

```sh
# Update package list and their versions
$ sudo apt-get update
```

```sh
# Install g++ in Ubuntu
$ sudo apt-get install g++
```

#### Install cmake

```sh
# Install cmake to compile the libraries
$ sudo apt-get install cmake
```

#### Install gtest

```sh
# Install gtest development package
$ sudo apt-get install libgtest-dev
```

```sh
# Locate the source files at /usr/src/gtest
$ cd /usr/src/gtest
```

```sh
# Compile the code to create the necessary library files
$ sudo cmake CMakeLists.txt
$ sudo make
```

```sh
# Copy or symlink libgtest.a and libgtest_main.a to /usr/lib folder
$ sudo cp *.a /usr/lib
```


### Execute the code

Execute the following instruction one by one to run the code.

```sh
# Change directory to a folder bin where UNIX executable are stored
$ cd bin
```

```sh
# Compile the Source Code using the following instruction. 
# Before running this make sure you have all the requirements installed.
$ ./setup
```

```sh
# Finally Run the project by executing the below instruction. 
# This takes the file stored in `functional_spec/fixtures` as input by default. 
# You can also remove the file name and use the command prompt only for interactive workflow. 
$ ./parking_lot
```

```sh
# For using the command prompt only, its better to run the following command
$ ./main
```

### Execute Unit Tests

To run the unit tests, use the syntax given below

```sh
# Browse to /unit_tests directory from the root
$ cd unit_tests/
```

```sh
# Compile Test.cpp file
$ g++ -o unitTest Test.cpp -lgtest -lgtest_main -pthread
```

```sh
# Execute unitTest executable file
$ ./unitTest
```

## Requirements

```sh
g++ 7.3.0 
gtest
cmake
```

## Sample Output Window

![Output](images/output.png)
