//
// Created by olcay on 12.03.2019.
//

#include "SimpleAsciifier.h"

/**
 * The asciify method takes a {@link Word} as an input and converts it to a char {@link java.lang.reflect.Array}. Then,
 * loops i times where i ranges from 0 to length of the char {@link java.lang.reflect.Array} and substitutes Turkish
 * characters with their corresponding Latin versions and returns it as a new {@link String}.
 *
 * @param word {@link Word} type input to asciify.
 * @return String output which is asciified.
 */
string SimpleAsciifier::asciify(Word *word) {
    string modified;
    string* allCharacters;
    allCharacters = Word::allCharacters(word->getName());
    for (int i = 0; i < Word::size(word->getName()); i++) {
        if (allCharacters[i] == "ç"){
            modified += "c";
        } else {
            if (allCharacters[i] == "ö"){
                modified += "o";
            } else {
                if (allCharacters[i] == "ğ"){
                    modified += "g";
                } else {
                    if (allCharacters[i] == "ü"){
                        modified += "u";
                    } else {
                        if (allCharacters[i] == "ş"){
                            modified += "s";
                        } else {
                            if (allCharacters[i] == "ı"){
                                modified += "i";
                            } else {
                                if (allCharacters[i] == "Ç"){
                                    modified += "C";
                                } else {
                                    if (allCharacters[i] == "Ö"){
                                        modified += "O";
                                    } else {
                                        if (allCharacters[i] == "Ğ"){
                                            modified += "G";
                                        } else {
                                            if (allCharacters[i] == "Ü"){
                                                modified += "U";
                                            } else {
                                                if (allCharacters[i] == "Ş"){
                                                    modified += "S";
                                                } else {
                                                    if (allCharacters[i] == "İ"){
                                                        modified += "I";
                                                    } else {
                                                        modified += allCharacters[i];
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return modified;
}

/**
 * Another asciify method which takes a {@link Sentence} as an input. It loops i times where i ranges form 0 to number of
 * words in the given sentence. First it gets each word and calls asciify with current word and creates {@link Word}
 * with returned String. At the and, adds each newly created ascified words to the result {@link Sentence}.
 *
 * @param sentence {@link Sentence} type input.
 * @return Sentence output which is asciified.
 */
Sentence *SimpleAsciifier::asciify(Sentence *sentence) {
    Word* word, *newWord;
    Sentence* result = new Sentence();
    for (int i = 0; i < sentence->wordCount(); i++) {
        word = sentence->getWord(i);
        newWord = new Word(asciify(word));
        result->addWord(newWord);
    }
    return result;
}
