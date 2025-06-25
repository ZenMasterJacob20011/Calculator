cmake_minimum_required(VERSION 3.31)
project(Calculator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.1
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM
)
FetchContent_MakeAvailable(SFML)

add_executable(Calculator main.cpp Button.cpp)
target_include_directories(Calculator PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_compile_features(Calculator PRIVATE cxx_std_17)
target_link_libraries(Calculator PRIVATE SFML::Graphics)
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/ARIAL.TTF" DESTINATION "${CMAKE_BINARY_DIR}")