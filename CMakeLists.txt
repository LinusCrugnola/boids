cmake_minimum_required(VERSION 3.14)
project(boids)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 20)
set(SFML_LIBS sfml-graphics sfml-system sfml-window)

#include testfiles
FILE (GLOB UNIT_TESTS "test/*.c*")
FILE (GLOB SRC_FILES "src/*.c*")

find_package(SFML 2 REQUIRED COMPONENTS graphics system window)
find_package(Threads REQUIRED)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Add the test executable
add_executable(
  unit_tests
  test/unit_tests.cc
  ${UNIT_TESTS}
)
target_link_libraries(
  unit_tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(unit_tests)

# Add the main executable
add_executable(
    ${PROJECT_NAME}
    ${SRC_FILES}
)
target_include_directories(${PROJECT_NAME}
    PRIVATE    
    "include"
)
target_link_libraries(${PROJECT_NAME}
    ${SFML_LIBS}
    pthread
)