#1，指定cmake最低版本
cmake_minimum_required(VERSION 3.10)

#2，项目名和版本
project(MacQuickSearch VERSION 1.0)

#3，指定C++ 标准 （C++17）
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#4，把所有源文件存到一个变量中
set(SRCS
    main.cpp 
    FileScanner.cpp
    )

#5，指示 CMake 生成可执行文件
#参数1: 生成程序的名字
#参数2: 编译要用的源文件
add_executable(scanner ${SRCS})

