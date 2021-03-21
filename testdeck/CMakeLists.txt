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

add_executable(DeckTest Deck.test.cpp catch.hpp catch.cpp)
add_test(NAME DeckTest COMMAND DeckTest)
target_link_libraries(DeckTest libdeck)

add_executable(CardTest Card.test.cpp catch.hpp catch.cpp)
add_test(NAME CardTest COMMAND CardTest)
target_link_libraries(CardTest libdeck)

add_executable(StrategyTest Strategy.test.cpp catch.hpp catch.cpp  MockTurnHelper.h)
add_test(NAME StrategyTest COMMAND StrategyTest )
target_link_libraries(StrategyTest libgofish)

add_executable(TurnHelperTest TurnHelper.test.cpp catch.hpp catch.cpp MockStrategyHelper.h)
add_test(NAME TurnHelperTest COMMAND TurnHelperTest )
target_link_libraries(TurnHelperTest libgofish)

