cmake_minimum_required(VERSION 3.12)
project(Deasciifier)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)
link_directories(library)

add_library(Deasciifier Asciifier.h Deasciifier.h SimpleAsciifier.cpp SimpleAsciifier.h SimpleDeasciifier.cpp SimpleDeasciifier.h NGramDeasciifier.cpp NGramDeasciifier.h)
add_executable(Test Asciifier.h Deasciifier.h SimpleAsciifier.cpp SimpleAsciifier.h SimpleDeasciifier.cpp SimpleDeasciifier.h NGramDeasciifier.cpp NGramDeasciifier.h Test/SimpleAsciifierTest.cpp Test/SimpleDeasciifierTest.cpp Test/NGramDeasciifierTest.cpp)

target_link_libraries(Deasciifier MorphologicalAnalysis Dictionary XmlParser Corpus)
target_link_libraries(Test MorphologicalAnalysis Dictionary XmlParser Corpus)
