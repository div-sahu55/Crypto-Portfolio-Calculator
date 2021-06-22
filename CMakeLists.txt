cmake_minimum_required(VERSION 3.10)

project(Crypto-portfolio-calculator LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
include_directories(${PROJECT_SRC_DIR}/src)
add_executable(port-calc src/Main.cpp src/InfoContainer.cpp)
target_link_libraries(port-calc ${CURSES_LIBRARIES})
target_include_directories(port-calc PUBLIC "${PROJECCT_BINARY_DIR}/src/")

