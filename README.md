# Deasciifier

This tool is used to turn Turkish text written in ASCII characters, which do not include some letters of the Turkish alphabet, into correctly written text with the appropriate Turkish characters (such as ı, ş, and so forth). It can also do the opposite, turning Turkish input into ASCII text, for the purpose of processing.

For Developers
============

You can also see [Java](https://github.com/starlangsoftware/TurkishDeasciifier), [Python](https://github.com/starlangsoftware/TurkishDeasciifier-Py), or [C#](https://github.com/starlangsoftware/TurkishDeasciifier-CS) repository.

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
