cmake_minimum_required(VERSION 3.27)
project(CA3_D00255161_BugsLife)

set(CMAKE_CXX_STANDARD 17)

add_executable(CA3_D00255161_BugsLife main.cpp
        board.cpp
        board.h
        bug.cpp
        bug.h
        hopper.cpp
        hopper.h
        crawler.cpp
        crawler.h
        direction.h
        jewelBug.cpp
        jewelBug.h
)
