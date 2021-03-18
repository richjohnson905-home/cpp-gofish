message(STATUS "Building Deck lib")

set(libdeck_SRCS
    Card.cpp
    Deck.cpp
    Player.cpp
)

# Declare the library
add_library(libdeck STATIC
    ${libdeck_SRCS}
)

# Specify here the include directories exported
# by this library
target_include_directories(libdeck PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
