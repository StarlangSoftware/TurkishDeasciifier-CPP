Turkish Deasciifier
============

This tool is used to turn Turkish text written in ASCII characters, which do not include some letters of the Turkish alphabet, into correctly written text with the appropriate Turkish characters (such as ı, ş, and so forth). It can also do the opposite, turning Turkish input into ASCII text, for the purpose of processing.

Video Lectures
============

[<img src="https://github.com/StarlangSoftware/TurkishDeasciifier/blob/master/video.jpg" width="50%">](https://youtu.be/b18-k8SKQ6U)

For Developers
============

You can also see [Java](https://github.com/starlangsoftware/TurkishDeasciifier), [Python](https://github.com/starlangsoftware/TurkishDeasciifier-Py), [Cython](https://github.com/starlangsoftware/TurkishDeasciifier-Cy), [C](https://github.com/starlangsoftware/TurkishDeasciifier-C), [Swift](https://github.com/starlangsoftware/TurkishDeasciifier-Swift), [Js](https://github.com/starlangsoftware/TurkishDeasciifier-Js), or [C#](https://github.com/starlangsoftware/TurkishDeasciifier-CS) repository.

## Requirements

* [C++ Compiler](#cpp)
* [Git](#git)


### CPP
To check if you have compatible C++ Compiler installed,
* Open CLion IDE 
* Preferences >Build,Execution,Deployment > Toolchain  

### Git

Install the [latest version of Git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git).

## Download Code

In order to work on code, create a fork from GitHub page. 
Use Git for cloning the code to your local or below line for Ubuntu:

	git clone <your-fork-git-link>

A directory called TurkishDeasciifier-CPP will be created. Or you can use below link for exploring the code:

	git clone https://github.com/starlangsoftware/TurkishDeasciifier-CPP.git

## Open project with CLion IDE

To import projects from Git with version control:

* Open CLion IDE , select Get From Version Control.

* In the Import window, click URL tab and paste github URL.

* Click open as Project.

Result: The imported project is listed in the Project Explorer view and files are loaded.


## Compile

**From IDE**

After being done with the downloading and opening project, select **Build Project** option from **Build** menu. After compilation process, user can run TurkishDeasciifier-CPP.

Detailed Description
============

+ [Asciifier](#using-asciifier)
+ [Deasciifier](#using-deasciifier)

## Using Asciifier

Asciifier converts text to a format containing only ASCII letters. This can be instantiated and used as follows:

      Asciifier asciifier = SimpleAsciifier();
      Sentence* sentence = new Sentence("çocuk"");
      Sentence* asciified = asciifier.asciify(sentence);
      cout << asciified;

Output:
    
    cocuk      

## Using Deasciifier

Deasciifier converts text written with only ASCII letters to its correct form using corresponding letters in Turkish alphabet. There are two types of `Deasciifier`:


* `SimpleDeasciifier`

    The instantiation can be done as follows:  
    
        FsmMorphologicalAnalyzer fsm = FsmMorphologicalAnalyzer();
        Deasciifier deasciifier = SimpleDeasciifier(fsm);
     
* `NGramDeasciifier`
    
    * To create an instance of this, both a `FsmMorphologicalAnalyzer` and a `NGram` is required. 
    
    * `FsmMorphologicalAnalyzer` can be instantiated as follows:
        
            FsmMorphologicalAnalyzer fsm = FsmMorphologicalAnalyzer();
    
    * `NGram` can be either trained from scratch or loaded from an existing model.
        
        * Training from scratch:
                
                Corpus corpus = Corpus("corpus.txt"); 
                NGram ngram = NGram(corpus.getAllWordsAsArrayList(), 1);
                ngram.calculateNGramProbabilities(LaplaceSmoothing());
                
        *There are many smoothing methods available. For other smoothing methods, check [here](https://github.com/olcaytaner/NGram).*       
        * Loading from an existing model:
     
                 NGram ngram = NGram("ngram.txt");

	*For further details, please check [here](https://github.com/starlangsoftware/NGram).*        
            
    * Afterwards, `NGramDeasciifier` can be created as below:
        
            Deasciifier deasciifier = NGramDeasciifier(fsm, ngram);
     
A text can be deasciified as follows:
     
    Sentence* sentence = new Sentence("cocuk");
    Sentence* deasciified = deasciifier.deasciify(sentence);
    cout << deasciified;
    
Output:

    çocuk

For Contibutors
============

### Conan Setup

1. First install conan.

pip install conan

Instructions are given in the following page:

https://docs.conan.io/2/installation.html

2. Add conan remote 'ozyegin' with IP: 104.247.163.162 with the following command:

conan remote add ozyegin http://104.247.163.162:8081/artifactory/api/conan/conan-local --insert

3. Use the comman conan list to check for installed packages. Probably there are no installed packages.

conan list

### conanfile.py file

1. Put the correct dependencies in the requires part
```
    requires = ["math/1.0.0", "classification/1.0.0"]
```

2. Default settings are:
```
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": True, "fPIC": True}
    exports_sources = "src/*", "Test/*"

    def layout(self):
        cmake_layout(self, src_folder="src")

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        copy(conanfile=self, keep_path=False, src=join(self.source_folder), dst=join(self.package_folder, "include"), pattern="*.h")
        copy(conanfile=self, keep_path=False, src=self.build_folder, dst=join(self.package_folder, "lib"), pattern="*.a")
        copy(conanfile=self, keep_path=False, src=self.build_folder, dst=join(self.package_folder, "lib"), pattern="*.so")
        copy(conanfile=self, keep_path=False, src=self.build_folder, dst=join(self.package_folder, "lib"), pattern="*.dylib")
        copy(conanfile=self, keep_path=False, src=self.build_folder, dst=join(self.package_folder, "bin"), pattern="*.dll")

    def package_info(self):
        self.cpp_info.libs = ["ComputationalGraph"]
```

### CMakeLists.txt file
1. Set the C++ standard with compiler flags.
```
	set(CMAKE_CXX_STANDARD 20)
	set(CMAKE_CXX_FLAGS "-O3")
```
2. Dependent packages should be given with find_package.
```
	find_package(util_c REQUIRED)
	find_package(data_structure_c REQUIRED)
```
3. For library part, use add_library and target_link_libraries commands. Use m library for math linker in Linux.
```
	add_library(Math src/Distribution.cpp src/Distribution.h src/DiscreteDistribution.cpp src/DiscreteDistribution.h src/Vector.cpp src/Vector.h src/Eigenvector.cpp src/Eigenvector.h src/Matrix.cpp src/Matrix.h src/Tensor.cpp src/Tensor.h)
	target_link_libraries(Math util_c::util_c data_structure_c::data_structure_c m)
```
4. For executable tests, use add_executable and target_link_libraries commands. Use m library for math linker in Linux.
```
	add_executable(DiscreteDistributionTest src/Distribution.cpp src/Distribution.h src/DiscreteDistribution.cpp src/DiscreteDistribution.h src/Vector.cpp src/Vector.h src/Eigenvector.cpp src/Eigenvector.h src/Matrix.cpp src/Matrix.h src/Tensor.cpp src/Tensor.h Test/DiscreteDistributionTest.cpp)
	target_link_libraries(DiscreteDistributionTest util_c::util_c data_structure_c::data_structure_c m)
```

### Data files
1. Add data files to the cmake-build-debug folder.

### C++ files

1. If needed, comparator operators == and < should be implemented for map and set data structures.
```
    bool operator==(const Word &anotherWord) const{
        return (name == anotherWord.name);
    }
    bool operator<(const Word &anotherWord) const{
        return (name < anotherWord.name);
    }
```
2. Do not forget to comment each function.
```
	/**
 	* A constructor of Word class which gets a String name as an input and assigns to the name variable.
	*
	* @param _name String input.
 	*/
	Word::Word(const string &_name) {
```
3. Function names should follow caml case.
```
	int Word::charCount() const
```
4. Write getter and setter methods.
```
	string Word::getName() const
	void Word::setName(const string &_name)
```
5. Use catch.hpp for testing purposes. Add
```
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
```
line in only one of the test files. Add
```
#include "catch.hpp"
```
line in all test files. Example test file is given below:
```
TEST_CASE("DictionaryTest") {
    TxtDictionary lowerCaseDictionary = TxtDictionary("lowercase.txt", "turkish_misspellings.txt");
    TxtDictionary mixedCaseDictionary = TxtDictionary("mixedcase.txt", "turkish_misspellings.txt");
    TxtDictionary dictionary = TxtDictionary();
    SECTION("testSize"){
        REQUIRE(29 == lowerCaseDictionary.size());
        REQUIRE(58 == mixedCaseDictionary.size());
        REQUIRE(62113 == dictionary.size());
    }
    SECTION("testGetWord"){
        for (int i = 0; i < dictionary.size(); i++){
            REQUIRE_FALSE(nullptr == dictionary.getWord(i));
        }
    }
    SECTION("testLongestWordSize"){
        REQUIRE(1 == lowerCaseDictionary.longestWordSize());
        REQUIRE(1 == mixedCaseDictionary.longestWordSize());
        REQUIRE(21 == dictionary.longestWordSize());
    }
```
6. Enumerated types should be declared with enum class.
```
	enum class Pos {
		ADJECTIVE,
		NOUN,
		VERB,
		ADVERB,
```
7. Every header file should start with
```
	#ifndef MATH_DISTRIBUTION_H
	#define MATH_DISTRIBUTION_H
```
and end with
```
	#endif //MATH_DISTRIBUTION_H
```
8. Do not forget to use const expression for parameters, if they will not be changed in the function.
```
	void Word::setName(const string &_name);
```
9. Do not forget to use const expression for methods, which do not modify any class attribute. Also use [[dodiscard]]
```
	[[nodiscard]] bool isPunctuation() const;
```
10. Use xmlparser package for parsing xml files.
```
    auto* doc = new XmlDocument("test.xml");
    doc->parse();
    XmlElement* root = doc->getFirstChild();
    XmlElement* firstChild = root->getFirstChild();
```
11. Data structures: Use map for hash map, unordered_map for linked hash map, vector for array list, unordered_set for hash set
