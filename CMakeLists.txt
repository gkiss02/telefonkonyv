cmake_minimum_required(VERSION 3.23)
project(telefonkonyv)

set(CMAKE_CXX_STANDARD 14)

add_compile_definitions(MEMTRACE)

add_executable(telefonkonyv main.cpp
        memtrace.h
        memtrace.cpp
        Vector.hpp
        Contact.h
        Contact.cpp
        PersonalContact.h
        BusinessContact.h
        String.h
        String.cpp
        Telefonkonyv.h
        Telefonkonyv.cpp
        )
