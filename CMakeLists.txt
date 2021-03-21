cmake_minimum_required(VERSION 3.17.5)

set(GOFISH_TOP_DIR ${CMAKE_CURRENT_LIST_DIR})

project(GoFish CXX)

message(STATUS "===( ${PROJECT_NAME} ${PROJECT_VERSION} )===")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_subdirectory(libdeck)
add_subdirectory(libgofish)
add_subdirectory(main)
add_subdirectory(testdeck)
