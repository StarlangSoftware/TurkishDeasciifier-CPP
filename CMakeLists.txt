cmake_minimum_required(VERSION 3.12)
project(Deasciifier)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O3")

find_package(morphological_analysis REQUIRED)
find_package(n_gram REQUIRED)

add_library(Deasciifier src/Asciifier.h src/Deasciifier.h src/SimpleAsciifier.cpp src/SimpleAsciifier.h src/SimpleDeasciifier.cpp src/SimpleDeasciifier.h src/NGramDeasciifier.cpp src/NGramDeasciifier.h)
add_executable(Test src/Asciifier.h src/Deasciifier.h src/SimpleAsciifier.cpp src/SimpleAsciifier.h src/SimpleDeasciifier.cpp src/SimpleDeasciifier.h src/NGramDeasciifier.cpp src/NGramDeasciifier.h Test/SimpleAsciifierTest.cpp Test/SimpleDeasciifierTest.cpp Test/NGramDeasciifierTest.cpp)
target_link_libraries(Deasciifier morphological_analysis::morphological_analysis n_gram::n_gram)
target_link_libraries(Test morphological_analysis::morphological_analysis n_gram::n_gram)
