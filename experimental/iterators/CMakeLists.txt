cmake_minimum_required(VERSION 3.0.0)
project(iterators VERSION 0.1.0)

# TODO: Atm LLVM is still in C++14 land.
set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_subdirectory(lib)




add_subdirectory(docs)

# Set up GoogleTest dependency
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
    )
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(iterators
        src/Main.cpp
    )
target_include_directories(iterators PUBLIC include)

# Set up test targets and tests
include(CTest)
enable_testing()

# TODO: move these to the tests director.
# TODO: split tests into C++ and MLIR
add_executable(iterator_tests
        tests/ColumnScanOperatorTest.cpp
        tests/FilterOperatorTest.cpp
        tests/HashJoinOperatorTest.cpp
        tests/MapOperatorTest.cpp
        tests/ReduceByKeyOperatorTest.cpp
        tests/ReduceOperatorTest.cpp
        tests/UtilsTest.cpp
    )
target_include_directories(iterator_tests
    PUBLIC
        include
    )
target_link_libraries(iterator_tests
        gtest_main
    )

include(GoogleTest)
gtest_discover_tests(iterator_tests)

# Set up CPack
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
