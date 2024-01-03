cmake_minimum_required(VERSION 3.12)
project(Deasciifier)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O3")

find_package(morphological_analysis REQUIRED)
find_package(n_gram REQUIRED)

add_library(Deasciifier Asciifier.h Deasciifier.h SimpleAsciifier.cpp SimpleAsciifier.h SimpleDeasciifier.cpp SimpleDeasciifier.h NGramDeasciifier.cpp NGramDeasciifier.h)
target_link_libraries(Deasciifier morphological_analysis::morphological_analysis n_gram::n_gram)
