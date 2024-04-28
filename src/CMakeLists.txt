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

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.6.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML-2.6.1/include)
target_link_libraries(CA3_D00255161_BugsLife sfml-system sfml-window sfml-graphics sfml-audio)
