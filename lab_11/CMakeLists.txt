cmake_minimum_required(VERSION 3.10)
project(lab_11)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(lab_11 src/main.cpp
        src/Developer.cpp include/Developer.h
        src/Employee.cpp include/Employee.h
        src/SalesManager.cpp include/SalesManager.h
        src/EmployeesArray.cpp include/EmployeesArray.h
        src/Factory.cpp include/Factory.h
        include/binary.inl)
