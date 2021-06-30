<!-- # Crypto-Portfolio-Calculator -->
![banner](./imgs/head_banner.png)
# About

A Portfolio calculator for Cryptocurrency investments, written in C++

It takes in investment information from the user and displays a detailed analysis of their portfolio that can be saved locally and thus help the user in keeping records of their portfolios.

# Features

- The entire program is menu-driven which makes it so that the user does not have to remember a lot of commands.

- It simplifies tedious calculations and shows accurate data in a user-friendly format.

- The portfolio analysis can be saved locally in a path-specified text file.

# API Used

[CoinGecko API V3](https://www.coingecko.com/api/documentations/v3) - For getting the current prices of the coins.
# Installing Dependencies

## CMake

 It uses CMake to build the program so it needs to be installed on the system.

To know more about cmake refer to this page :- [https://cmake.org/cmake/help/latest/guide/tutorial/index.html](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)

 Cmake can be installed using package managers like apt/dnf in the following ways:-

- For Ubuntu/Debian 


```cmake
sudo apt-get install cmake
```
- For fedora/CentOS
```
sudo dnf install cmake
```

## libcurl

This program uses libcurl for making an api call, libcurl is a free and easy-to-use client-side URL transfer library. It is highly portable, it builds and works identically on numerous platforms

To know more about libcurl, please refer: 
[https://curl.se/libcurl/](https://curl.se/libcurl/)

- Run update command to update package repositories and get latest package information.
```
sudo apt-get update -y
```
- Run the install command with -y flag to quickly install the packages and dependencies.


```
sudo apt-get install -y libcurl-dev
```

- Then explicitly install one of the packages.

```
sudo apt-get install <package-name>
```

<h2>or</h2>
 
 - For Ubuntu

```
sudo apt-get install libcurl4-openssl-dev
```

# Build Instructions

- Cloning this repository
```
$ git clone https://github.com/div-sahu55/Crypto-Portfolio-Calculator.git
```
- Changing to this repository
```
$ cd Crypto-Port-Calc
```
- Generating standard build files
```
$ cmake -B build/
```
- Compiling and generating an executable 
```
$ cd build/
$ make
```
# To Run
- Inside the build directory, execute:
```
$ ./port-calc
```
# Usage

- Run the program and respond with the number against the menu option to proceed.

![banner](./imgs/menu.png)

- Enter your investment information accordingly and add as many entries as you would like to.

![banner](./imgs/entry.png)

- Check your portfolio analysis and respond with y/n whether you would like to save the file or not.

![banner](./imgs/port.png)

- If responded with y for saving the file, enter the file path where you'd like to save this portfolio data.

![banner](./imgs/save.png)

- After saving, you will be redirected to the main menu where you can see the portfolio analysis again by responding with 2 and you can clear all your entries if you respond with 3:-

![banner](./imgs/op-3.png)

You can also checkout this video I made regarding usage - [https://youtu.be/IHnDor9emng](https://youtu.be/IHnDor9emng)
# Comments

- The recommendations for any token are based on general consensus and are NOT financial advices.

- I will also be adding many more portfolio indicators like ror etc. with future updates so stay tuned :) 