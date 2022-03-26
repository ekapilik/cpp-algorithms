enable_testing()

file(GLOB TEST_SRCS *.cpp */*.cpp)
add_executable(cpp-algorithms-test ${TEST_SRCS})
target_link_libraries(cpp-algorithms-test gtest gtest_main pthread ${libraries})
include(GoogleTest)
gtest_discover_tests(cpp-algorithms-test)
