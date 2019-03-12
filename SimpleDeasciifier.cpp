//
// Created by olcay on 12.03.2019.
//

#include "SimpleDeasciifier.h"

/**
 * The generateCandidateList method takes an {@link vector} candidates, a {@link String}, and an integer index as inputs.
 * First, it creates a {@link String} which consists of corresponding Latin versions of special Turkish characters. If given index
 * is less than the length of given word and if the item of word's at given index is one of the chars of {@link String}, it loops
 * given candidates {@link vector}'s size times and substitutes Latin characters with their corresponding Turkish versions
 * and put them to newly created char {@link vector} modified. At the end, it adds each modified item to the candidates
 * {@link vector} as a {@link String} and recursively calls generateCandidateList with next index.
 *
 * @param candidates {@link vector} type input.
 * @param word       {@link String} input.
 * @param index      {@link Integer} input.
 */
void SimpleDeasciifier::generateCandidateList(vector<string> &candidates, string word, int index) {
    string s = "ıiougcsİIOUGCS";
    if (index < Word::size(word)) {
        if (s.find(Word::charAt(word, index)) != string::npos) {
            int size = candidates.size();
            for (int i = 0; i < size; i++) {
                string modified = candidates.at(i);
                string ch = Word::Word::charAt(word, index);
                if (ch == "ı"){
                    modified[index] = 'i';
                } else {
                    if (ch == "i"){
                        modified[index] = 'ı';
                    } else {
                        if (ch == "o"){
                            modified[index] = 'ö';
                        } else {
                            if (ch == "u"){
                                modified[index] = 'ü';
                            } else {
                                if (ch == "g"){
                                    modified[index] = 'ğ';
                                } else {
                                    if (ch == "c"){
                                        modified[index] = 'ç';
                                    } else {
                                        if (ch == "s"){
                                            modified[index] = 'ş';
                                        } else {
                                            if (ch == "I"){
                                                modified[index] = 'ı';
                                            } else {
                                                if (ch == "İ"){
                                                    modified[index] = 'I';
                                                } else {
                                                    if (ch == "O"){
                                                        modified[index] = 'Ö';
                                                    } else {
                                                        if (ch == "U"){
                                                            modified[index] = 'Ü';
                                                        } else {
                                                            if (ch == "G"){
                                                                modified[index] = 'Ğ';
                                                            } else {
                                                                if (ch == "C"){
                                                                    modified[index] = 'Ç';
                                                                } else {
                                                                    if (ch == "S"){
                                                                        modified[index] = 'Ş';
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
                }
                candidates.push_back(modified);
            }
        }
        generateCandidateList(candidates, word, index + 1);
    }
}

/**
 * The candidateList method takes a {@link Word} as an input and creates new candidates {@link vector}. First it
 * adds given word to this {@link vector} and calls generateCandidateList method with candidates, given word and
 * index 0. Then, loops i times where i ranges from 0 to size of candidates {@link vector} and calls morphologicalAnalysis
 * method with ith item of candidates {@link vector}. If it does not return any analysis for given item, it removes
 * the item from candidates {@link vector}.
 *
 * @param word {@link Word} type input.
 * @return ArrayList candidates.
 */
vector<string> SimpleDeasciifier::candidateList(Word *word) {
    vector<string> result;
    vector<string> candidates;
    candidates.push_back(word->getName());
    generateCandidateList(candidates, word->getName(), 0);
    for (const auto &candidate : candidates) {
        FsmParseList fsmParseList = fsm.morphologicalAnalysis(candidate);
        if (fsmParseList.size() != 0) {
            result.push_back(candidate);
        }
    }
    return result;
}

/**
 * A constructor of {@link SimpleDeasciifier} class which takes a {@link FsmMorphologicalAnalyzer} as an input and
 * initializes fsm variable with given {@link FsmMorphologicalAnalyzer} input.
 *
 * @param fsm {@link FsmMorphologicalAnalyzer} type input.
 */
SimpleDeasciifier::SimpleDeasciifier(FsmMorphologicalAnalyzer& fsm) {
    this->fsm = fsm;
}

/**
 * The deasciify method takes a {@link Sentence} as an input and loops i times where i ranges from 0 to number of
 * words in the given {@link Sentence}. First it gets ith word from given {@link Sentence} and calls candidateList with
 * ith word and assigns the returned {@link vector} to the newly created candidates {@link vector}. And if the size of
 * candidates {@link vector} is greater than 0, it generates a random number and gets the item of candidates {@link vector}
 * at the index of random number and assigns it as a newWord. If the size of candidates {@link vector} is 0, it then
 * directly assigns ith word as the newWord. At the end, it adds newWord to the result {@link Sentence}.
 *
 * @param sentence {@link Sentence} type input.
 * @return result {@link Sentence}.
 */
Sentence *SimpleDeasciifier::deasciify(Sentence *sentence) {
    Word *word, *newWord;
    int randomCandidate;
    vector<string> candidates;
    auto* result = new Sentence();
    for (int i = 0; i < sentence->wordCount(); i++) {
        word = sentence->getWord(i);
        candidates = candidateList(word);
        if (!candidates.empty()) {
            randomCandidate = random() % candidates.size();
            newWord = new Word(candidates.at(randomCandidate));
        } else {
            newWord = word;
        }
        result->addWord(newWord);
    }
    return result;
}
