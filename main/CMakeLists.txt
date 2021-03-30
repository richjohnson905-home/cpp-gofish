message(STATUS "Building Main app")

set(Main_SRCS
    main.cpp
)

add_executable(myApp
    ${Main_SRCS}
)

add_library(GoFishCommon INTERFACE)

target_link_libraries(GoFishCommon
        INTERFACE CLI11::CLI11)

set(CLI11_TESTING OFF)
mark_as_advanced(CLI_CXX_STD CLI_EXAMPLES CLI_SINGLE_FILE CLI_SINGLE_FILE_TESTS CLI_TESTING)

# Specify here the libraries this program depends on
target_link_libraries(myApp
        GoFishCommon
        libdeck
        libgofish
)

install(TARGETS myApp DESTINATION bin)
