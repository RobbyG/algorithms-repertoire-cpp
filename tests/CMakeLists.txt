file(GLOB TEST_SOURCES CONFIGURE_DEPENDS "*.cpp")

add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests PRIVATE algo)

add_test(NAME all_tests COMMAND tests)
