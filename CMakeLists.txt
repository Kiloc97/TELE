cmake_minimum_required(VERSION 3.10)
project(tele_app)

set(CMAKE_CXX_STANDARD 17)

add_executable(tele 
    main.cpp
    unameload.cpp
    print_uptime.cpp
    print_hwmon_info.cpp
)