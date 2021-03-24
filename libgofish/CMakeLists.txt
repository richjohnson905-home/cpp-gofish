message(STATUS "Building GoFish lib")

set(libgofish_SRCS
        GoFishGame.cpp
        Strategy.cpp
        HumanStrategy.cpp
        GoFishUtil.cpp
        StrategyHelper.cpp
        TurnHelper.cpp
        Player.cpp
        MvcGameView.cpp MvcController.cpp MvcController.h MvcModel.cpp MvcModel.h)

# Declare the library
add_library(libgofish STATIC
    ${libgofish_SRCS}
)

target_link_libraries(libgofish
    libdeck
)

# Specify here the include directories exported
# by this library
target_include_directories(libgofish PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
