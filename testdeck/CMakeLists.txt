message(STATUS "Building Unit Tests ${UNITTEST}")


# set(testdeck_SRCS
#   Deck.test.cpp 
#   Card.test.cpp 
#   Player.test.cpp
#   Strategy.test.cpp
#   GoFishUtil.test.cpp
#   StrategyHelper.test.cpp
#   HumanStrategy.test.cpp
# )
  
set(FAKEIT_DIRECTORY extern/FakeIt/single_header/standalone)
#set(FAKEIT_HEADER_FILES ${FAKEIT_DIRECTORY}/fakeit.hpp)
include_directories(../${FAKEIT_DIRECTORY})

add_library(test_main OBJECT test_main.cpp)

add_executable(DeckTest Deck.test.cpp $<TARGET_OBJECTS:test_main>)
add_test(NAME DeckTest COMMAND DeckTest)
target_link_libraries(DeckTest libdeck)

add_executable(CardTest Card.test.cpp $<TARGET_OBJECTS:test_main>)
add_test(NAME CardTest COMMAND CardTest )
target_link_libraries(CardTest libdeck)

add_executable(GoFishUtilTest GoFishUtil.test.cpp $<TARGET_OBJECTS:test_main>)
add_test(NAME GoFishUtilTest COMMAND GoFishUtilTest )
target_link_libraries(GoFishUtilTest libgofish)

add_executable(HumanStrategyTest HumanStrategy.test.cpp $<TARGET_OBJECTS:test_main>)
add_test(NAME HumanStrategyTest COMMAND HumanStrategyTest )
target_link_libraries(HumanStrategyTest libgofish)

add_executable(PlayerTest Player.test.cpp $<TARGET_OBJECTS:test_main>)
add_test(NAME PlayerTest COMMAND PlayerTest )
target_link_libraries(PlayerTest libdeck libgofish)

add_executable(StrategyTest Strategy.test.cpp $<TARGET_OBJECTS:test_main>)
add_test(NAME StrategyTest COMMAND StrategyTest )
target_link_libraries(StrategyTest libgofish)
