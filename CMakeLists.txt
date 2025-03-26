cmake_minimum_required(VERSION 3.14)
project(IndustrialCodeExamples)

set(CMAKE_CXX_STANDARD 17)

# Подключаем Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# Основной исполняемый файл
add_executable(industrial_code
    src/factorials.cpp
    src/remove_duplicates.cpp
    src/reverse_list.cpp
    tests/tests.cpp
)

# Подключаем тесты
target_link_libraries(industrial_code
    PRIVATE gtest_main
)

include(GoogleTest)
gtest_discover_tests(industrial_code)
