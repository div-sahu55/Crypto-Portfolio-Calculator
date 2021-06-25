<!-- # Crypto-Portfolio-Calculator -->
![banner](./imgs/head_banner.png)
# About

A Portfolio calculator for Cryptocurrency and Stocks investments, written in C++

It takes in investment information from the user and displays a detailed analysis of this portfolio using various quantification methods.

# Features

- It simplifies tedious calculations and shows accurate data which is formatted in a user-friendly format.

- The final analysis can be save locally in a path specified text file.

# Installing Dependencies

 It uses cmake to build the program so it needs to be installed on system.

To know more about cmake refer to this page :- [https://cmake.org/cmake/help/latest/guide/tutorial/index.html](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)

 Cmake can be installed using package managers like apt/dnf by the following ways:-

- For Ubuntu/Debian 


```cmake
sudo apt-get install cmake
```
- For fedora/CentOS
```
sudo dnf install cmake
```
# Build Instructions

- Cloning this repository
```
$ git clone https://github.com/div-sahu55/Crypto-Portfolio-Calculator.git
```
- Going into the reposistory
```
$ cd Crypto-Port-Calc
```
- Generating standard build files
```
$ cmake -B build/
```
- Compiling and generating an executable 
```
$ cd build
$ make
```
# To Run
- Inside the build directory, execute:
```
$ ./port-calc
```

