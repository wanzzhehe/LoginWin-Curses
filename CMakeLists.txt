cmake_minimum_required(VERSION 3.10)
project(LoginWin)

include_directories(
    include
)

file(GLOB SOURCES
    "${PROJECT_SOURCE_DIR}/main.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} curses)