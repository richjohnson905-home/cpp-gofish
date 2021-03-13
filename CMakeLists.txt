cmake_minimum_required(VERSION 3.19.6)

project(cardGames CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_subdirectory(libdeck)
add_subdirectory(libgofish)
add_subdirectory(main)
add_subdirectory(testdeck)
