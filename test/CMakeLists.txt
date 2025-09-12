include(CTest)
include(FetchContent)

FetchContent_Declare(googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG v1.17.0)
FetchContent_MakeAvailable(googletest)

add_executable(VectorTest)
target_sources(VectorTest
    PRIVATE
        test.cpp)
target_link_libraries(VectorTest
    PRIVATE
        Vector
        GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(VectorTest)