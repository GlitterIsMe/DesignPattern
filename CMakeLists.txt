cmake_minimum_required(VERSION 3.8)
project(DesignPattern_master)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        simple_factory.cc
        simple_factory.h
        unit.h)

add_executable(DesignPattern_master ${SOURCE_FILES})