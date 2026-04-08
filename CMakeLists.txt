cmake_minimum_required(VERSION 3.20)

option(BUILD_BENCHMARKS "Build benchmark targets" ON)

add_library(algorithms STATIC
  "src/count_ones.cpp"
)

target_include_directories(algorithms PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(demo_countones "demos/demo_countones.cpp")
target_link_libraries(demo_countones PRIVATE algorithms)

add_executable(test_public "pruebas_publicas/test_public.cpp")
target_link_libraries(test_public PRIVATE algorithms)

add_executable(test_public_extra "pruebas_publicas/test_public_extra.cpp")
target_link_libraries(test_public_extra PRIVATE algorithms)

add_executable(test_internal "pruebas_internas/test_internal.cpp")
target_link_libraries(test_internal PRIVATE algorithms)

add_executable(test_internal_extra "pruebas_internas/test_internal_extra.cpp")
target_link_libraries(test_internal_extra PRIVATE algorithms)

add_executable(edge_cases "pruebas_internas/edge_cases.cpp")
target_link_libraries(edge_cases PRIVATE algorithms)

add_test(NAME semana1_public COMMAND test_public)
add_test(NAME semana1_public_extra COMMAND test_public_extra)
add_test(NAME semana1_internal COMMAND test_internal)
add_test(NAME semana1_internal_extra COMMAND test_internal_extra)
add_test(NAME semana1_edge_cases COMMAND edge_cases)

if (BUILD_BENCHMARKS)
    add_executable(benchmark benchmarks/benchmark.cpp)
    target_link_libraries(benchmark PRIVATE algorithms)
endif()
