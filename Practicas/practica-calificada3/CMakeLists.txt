cmake_minimum_required(VERSION 3.20)
project(Semana3 LANGUAGES CXX)
include(CTest)
option(BUILD_BENCHMARKS "Build benchmark targets" OFF)
option(ENABLE_SANITIZERS "Enable ASan and UBSan" ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(algorithms STATIC
    "src/Treap.cpp"
    "src/ImplicitTreap.cpp"
    "src/FWideSwap.cpp"
)

add_compile_options(-Wall -Wextra -Wpedantic)

target_include_directories(algorithms PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(pc3_demo_treap "demos/demo_treap.cpp")
target_link_libraries(pc3_demo_treap PRIVATE algorithms)

add_executable(pc3_demo_fwideswap "demos/demo_fwideswap.cpp")
target_link_libraries(pc3_demo_fwideswap PRIVATE algorithms)

add_executable(test_internal "tests/test_internal.cpp")
target_link_libraries(test_internal PRIVATE algorithms)
#
add_executable(edge_cases "tests/edge_cases.cpp")
target_link_libraries(edge_cases PRIVATE algorithms)

add_test(NAME pc3_test_internal COMMAND test_internal)
add_test(NAME pc3_edge_cases COMMAND edge_cases)

# if (BUILD_BENCHMARKS)
#     add_executable(benchmark benchmark/benchmark.cpp)
#     target_link_libraries(benchmark PRIVATE algorithms)
# endif()
if (ENABLE_SANITIZERS)
    message(STATUS "Sanitizers enabled")

    add_compile_options(
        -fsanitize=address,undefined
        -fno-omit-frame-pointer
        -g
    )

    add_link_options(
        -fsanitize=address,undefined
    )
endif()
