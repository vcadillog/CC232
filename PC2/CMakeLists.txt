cmake_minimum_required(VERSION 3.20)
project(Semana3 LANGUAGES CXX)
include(CTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(pc2_headers INTERFACE)
target_include_directories(pc2_headers INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_compile_features(pc2_headers INTERFACE cxx_std_17)

function(cc232_add_pc2_target target_name source_file)
  add_executable(${target_name} "${source_file}")
  target_link_libraries(${target_name} PRIVATE pc2_headers)
endfunction()

cc232_add_pc2_target(pc2_demo_create_adt "demos/create_adt.cpp")

