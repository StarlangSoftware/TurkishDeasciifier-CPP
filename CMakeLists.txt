cmake_minimum_required(VERSION 3.12)
project(Deasciifier)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
link_directories(library)

add_library(Deasciifier Asciifier.h Deasciifier.h SimpleAsciifier.cpp SimpleAsciifier.h SimpleDeasciifier.cpp SimpleDeasciifier.h NGramDeasciifier.cpp NGramDeasciifier.h)
add_executable(TestDeasciifier Asciifier.h Deasciifier.h SimpleAsciifier.cpp SimpleAsciifier.h SimpleDeasciifier.cpp SimpleDeasciifier.h NGramDeasciifier.cpp NGramDeasciifier.h TestDeasciifier.cpp)

target_link_libraries(Deasciifier MorphologicalAnalysis Dictionary XmlParser Corpus)
target_link_libraries(TestDeasciifier MorphologicalAnalysis Dictionary XmlParser Corpus)
