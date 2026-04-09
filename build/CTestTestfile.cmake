# CMake generated Testfile for 
# Source directory: /home/victor/clases/algoritmos/pc1
# Build directory: /home/victor/clases/algoritmos/pc1/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[pc1_public]=] "test_public")
set_tests_properties([=[pc1_public]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/victor/clases/algoritmos/pc1/CMakeLists.txt;28;add_test;/home/victor/clases/algoritmos/pc1/CMakeLists.txt;0;")
add_test([=[pc1_internal]=] "/home/victor/clases/algoritmos/pc1/build/test_internal")
set_tests_properties([=[pc1_internal]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/victor/clases/algoritmos/pc1/CMakeLists.txt;29;add_test;/home/victor/clases/algoritmos/pc1/CMakeLists.txt;0;")
add_test([=[pc1_edge_cases]=] "/home/victor/clases/algoritmos/pc1/build/edge_cases")
set_tests_properties([=[pc1_edge_cases]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/victor/clases/algoritmos/pc1/CMakeLists.txt;30;add_test;/home/victor/clases/algoritmos/pc1/CMakeLists.txt;0;")
