message(STATUS "Building Unit Tests ${UNITTEST}")


set(testdeck_SRCS
        Deck.test.cpp
        Card.test.cpp
        Player.test.cpp
        Strategy.test.cpp
        GoFishUtil.test.cpp
        StrategyHelper.test.cpp
        HumanStrategy.test.cpp
        TurnHelper.test.cpp
)

set(CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES /usr/local/lib ${CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES})

find_package(Catch2 REQUIRED)

IF (${Catch2_FOUND})
    MESSAGE(STATUS "Catch2 found")
ELSE (${Catch2_FOUND})
    MESSAGE(STATUS "Catch2 not found")
endif(${Catch2_FOUND})

find_library(c2m_location NAMES libCatch2Main.a)
message(STATUS ${c2m_location})
add_library(c2m STATIC IMPORTED)
set_target_properties(c2m PROPERTIES IMPORTED_LOCATION ${c2m_location})

find_library(c2_location NAMES libCatch2.a)
message(STATUS ${c2_location})
add_library(c2 STATIC IMPORTED)
set_target_properties(c2 PROPERTIES IMPORTED_LOCATION ${c2_location})

add_executable(DeckTest Deck.test.cpp)
add_test(NAME DeckTest COMMAND DeckTest)
target_link_libraries(DeckTest PRIVATE libdeck c2m c2)

add_executable(CardTest Card.test.cpp TurnHelper.test.h)
add_test(NAME CardTest COMMAND CardTest)
target_link_libraries(CardTest PRIVATE libdeck c2m c2)

add_executable(StrategyTest Strategy.test.cpp mocks/MockTurnHelper.h)
add_test(NAME StrategyTest COMMAND StrategyTest )
target_link_libraries(StrategyTest PRIVATE libgofish c2m c2)

add_executable(TurnHelperTest TurnHelper.test.cpp mocks/MockStrategyHelper.h)
add_test(NAME TurnHelperTest COMMAND TurnHelperTest )
target_link_libraries(TurnHelperTest PRIVATE libgofish c2m c2)

add_executable(GoFishUtilTest GoFishUtil.test.cpp)
add_test(NAME GoFishUtilTest COMMAND GoFishUtilTest )
target_link_libraries(GoFishUtilTest PRIVATE libgofish c2m c2)

add_executable(PlayerTest Player.test.cpp mocks/MockMvcController.h)
add_test(NAME PlayerTest COMMAND PlayerTest )
target_link_libraries(PlayerTest PRIVATE libgofish c2m c2)

add_executable(StrategyHelperTest StrategyHelper.test.cpp)
add_test(NAME StrategyHelperTest COMMAND StrategyHelperTest )
target_link_libraries(StrategyHelperTest PRIVATE libgofish c2m c2)

include_directories(/usr/local/include)
include(CTest)
include(Catch)
catch_discover_tests(DeckTest CardTest)
enable_testing()