//
// Created by olcay on 12.03.2019.
//

#include "SimpleDeasciifier.h"

/**
 * The generateCandidateList method takes an vector candidates, a String, and an integer index as inputs.
 * First, it creates a String which consists of corresponding Latin versions of special Turkish characters. If given index
 * is less than the length of given word and if the item of word's at given index is one of the chars of String, it loops
 * given candidates vector's size times and substitutes Latin characters with their corresponding Turkish versions
 * and put them to newly created char vector modified. At the end, it adds each modified item to the candidates
 * vector as a String and recursively calls generateCandidateList with next index.
 *
 * @param candidates vector type input.
 * @param word       String input.
 * @param index      Integer input.
 */
void SimpleDeasciifier::generateCandidateList(vector<string> &candidates, const string& word, int index) const{
    string s = "ıiougcsİIOUGCS";
    if (index < Word::size(word)) {
        if (s.find(Word::charAt(word, index)) != string::npos) {
            int size = candidates.size();
            for (int i = 0; i < size; i++) {
                string modified = candidates.at(i);
                string ch = Word::charAt(word, index);
                if (ch == "ı"){
                    modified = Word::substring(modified, 0, index) + "i" + Word::substring(modified, index + 1);
                } else {
                    if (ch == "i"){
                        modified = Word::substring(modified, 0, index) + "ı" + Word::substring(modified, index + 1);
                    } else {
                        if (ch == "o"){
                            modified = Word::substring(modified, 0, index) + "ö" + Word::substring(modified, index + 1);
                        } else {
                            if (ch == "u"){
                                modified = Word::substring(modified, 0, index) + "ü" + Word::substring(modified, index + 1);
                            } else {
                                if (ch == "g"){
                                    modified = Word::substring(modified, 0, index) + "ğ" + Word::substring(modified, index + 1);
                                } else {
                                    if (ch == "c"){
                                        modified = Word::substring(modified, 0, index) + "ç" + Word::substring(modified, index + 1);
                                    } else {
                                        if (ch == "s"){
                                            modified = Word::substring(modified, 0, index) + "ş" + Word::substring(modified, index + 1);
                                        } else {
                                            if (ch == "I"){
                                                modified = Word::substring(modified, 0, index) + "ı" + Word::substring(modified, index + 1);
                                            } else {
                                                if (ch == "İ"){
                                                    modified = Word::substring(modified, 0, index) + "I" + Word::substring(modified, index + 1);
                                                } else {
                                                    if (ch == "O"){
                                                        modified = Word::substring(modified, 0, index) + "Ö" + Word::substring(modified, index + 1);
                                                    } else {
                                                        if (ch == "U"){
                                                            modified = Word::substring(modified, 0, index) + "Ü" + Word::substring(modified, index + 1);
                                                        } else {
                                                            if (ch == "G"){
                                                                modified = Word::substring(modified, 0, index) + "Ğ" + Word::substring(modified, index + 1);
                                                            } else {
                                                                if (ch == "C"){
                                                                    modified = Word::substring(modified, 0, index) + "Ç" + Word::substring(modified, index + 1);
                                                                } else {
                                                                    if (ch == "S"){
                                                                        modified = Word::substring(modified, 0, index) + "Ş" + Word::substring(modified, index + 1);
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
 * The candidateList method takes a Word as an input and creates new candidates vector. First it
 * adds given word to this vector and calls generateCandidateList method with candidates, given word and
 * index 0. Then, loops i times where i ranges from 0 to size of candidates vector and calls morphologicalAnalysis
 * method with ith item of candidates vector. If it does not return any analysis for given item, it removes
 * the item from candidates vector.
 *
 * @param word Word type input.
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
 * A constructor of SimpleDeasciifier class which takes a FsmMorphologicalAnalyzer as an input and
 * initializes fsm variable with given FsmMorphologicalAnalyzer input.
 *
 * @param fsm FsmMorphologicalAnalyzer type input.
 */
SimpleDeasciifier::SimpleDeasciifier(const FsmMorphologicalAnalyzer& fsm) {
    this->fsm = fsm;
}

/**
 * The deasciify method takes a Sentence as an input and loops i times where i ranges from 0 to number of
 * words in the given Sentence. First it gets ith word from given Sentence and calls candidateList with
 * ith word and assigns the returned vector to the newly created candidates vector. And if the size of
 * candidates vector is greater than 0, it generates a random number and gets the item of candidates vector
 * at the index of random number and assigns it as a newWord. If the size of candidates vector is 0, it then
 * directly assigns ith word as the newWord. At the end, it adds newWord to the result Sentence.
 *
 * @param sentence Sentence type input.
 * @return result Sentence.
 */
Sentence *SimpleDeasciifier::deasciify(Sentence *sentence) {
    Word *word, *newWord;
    int randomCandidate;
    vector<string> candidates;
    auto* result = new Sentence();
    for (int i = 0; i < sentence->wordCount(); i++) {
        word = sentence->getWord(i);
        FsmParseList fsmParseList = fsm.morphologicalAnalysis(word->getName());
        if (fsmParseList.size() == 0){
            candidates = candidateList(word);
            if (!candidates.empty()) {
                randomCandidate = random() % candidates.size();
                newWord = new Word(candidates.at(randomCandidate));
            } else {
                newWord = word;
            }
        } else {
            newWord = word;
        }
        result->addWord(newWord);
    }
    return result;
}
