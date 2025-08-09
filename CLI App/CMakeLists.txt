cmake_minimum_required(VERSION 4.0)
project(CLI_App)

set(CMAKE_CXX_STANDARD 17)

add_executable(CLI_App main.cpp
        FileHandler.cpp
        FileHandler.h
        PasswordManager.cpp
        PasswordManager.h)
