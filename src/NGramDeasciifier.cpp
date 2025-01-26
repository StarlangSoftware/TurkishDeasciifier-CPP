//
// Created by Olcay Taner Yıldız on 2019-03-12.
//

#include "NGramDeasciifier.h"
#include <fstream>
#include "StringUtils.h"

/**
 * A constructor of NGramDeasciifier class which takes an FsmMorphologicalAnalyzer and an NGram
 * as inputs. It first calls it super class SimpleDeasciifier with given FsmMorphologicalAnalyzer input
 * then initializes nGram variable with given NGram input.
 *
 * @param fsm   FsmMorphologicalAnalyzer type input.
 * @param nGram NGram type input.
 */
NGramDeasciifier::NGramDeasciifier(const FsmMorphologicalAnalyzer& fsm, NGram<string>* nGram, bool rootNgram) : SimpleDeasciifier(fsm) {
    this->nGram = nGram;
    this->rootNGram = rootNgram;
    loadAsciifiedSameList();
}

/**
 * The deasciify method takes a Sentence as an input. First it creates a String ArrayList as candidates,
 * and a Sentence result. Then, loops i times where i ranges from 0 to words size of given sentence. It gets the
 * current word and generates a candidateList with this current word then, it loops through the candidateList. First it
 * calls morphologicalAnalysis method with current candidate and gets the first item as root word. If it is the first root,
 * it gets its N-gram probability, if there are also other roots, it gets probability of these roots and finds out the
 * best candidate, best root and the best probability. At the nd, it adds the bestCandidate to the bestCandidate ArrayList.
 *
 * @param sentence Sentence type input.
 * @return Sentence result as output.
 */
Sentence *NGramDeasciifier::deasciify(Sentence *sentence) {
    Word* word, *bestRoot, *previousRoot = nullptr, *root, *nextRoot;
    string bestCandidate;
    bool isAsciifiedSame;
    FsmParseList fsmParses;
    double previousProbability, nextProbability, bestProbability;
    vector<string> candidates;
    auto* result = new Sentence();
    root = checkAnalysisAndSetRoot(sentence, 0);
    nextRoot = checkAnalysisAndSetRoot(sentence, 1);
    for (int i = 0; i < sentence->wordCount(); i++) {
        candidates.clear();
        isAsciifiedSame = false;
        word = sentence->getWord(i);
        if (asciifiedSame.contains(word->getName())){
            candidates.emplace_back(word->getName());
            candidates.emplace_back(asciifiedSame[word->getName()]);
            isAsciifiedSame = true;
        }
        if (root == nullptr || isAsciifiedSame) {
            if (!isAsciifiedSame){
                candidates = candidateList(word);
            }
            bestCandidate = word->getName();
            bestRoot = word;
            bestProbability = threshold;
            for (const string &candidate : candidates) {
                fsmParses = fsm.morphologicalAnalysis(candidate);
                if (rootNGram && !isAsciifiedSame){
                    root = fsmParses.getParseWithLongestRootWord().getWord();
                } else {
                    root = new Word(candidate);
                }
                if (previousRoot != nullptr) {
                    previousProbability = nGram->getProbability({previousRoot->getName(), root->getName()});
                } else {
                    previousProbability = 0.0;
                }
                if (nextRoot != nullptr) {
                    nextProbability = nGram->getProbability({root->getName(), nextRoot->getName()});
                } else {
                    nextProbability = 0.0;
                }
                if (std::max(previousProbability, nextProbability) > bestProbability || candidates.size() == 1) {
                    bestCandidate = candidate;
                    bestRoot = root;
                    bestProbability = std::max(previousProbability, nextProbability);
                }
            }
            root = bestRoot;
            result->addWord(new Word(bestCandidate));
        } else {
            result->addWord(word);
        }
        previousRoot = root;
        root = nextRoot;
        nextRoot = checkAnalysisAndSetRoot(sentence, i + 2);
    }
    return result;
}

/**
 * Checks the morphological analysis of the given word in the given index. If there is no misspelling, it returns
 * the longest root word of the possible analyses.
 * @param sentence Sentence to be analyzed.
 * @param index Index of the word
 * @return If the word is misspelled, null; otherwise the longest root word of the possible analyses.
 */
Word *NGramDeasciifier::checkAnalysisAndSetRoot(Sentence *sentence, int index) {
    if (index < sentence->wordCount()){
        FsmParseList fsmParses = fsm.morphologicalAnalysis(sentence->getWord(index)->getName());
        if (fsmParses.size() != 0){
            if (rootNGram){
                return fsmParses.getParseWithLongestRootWord().getWord();
            } else {
                return sentence->getWord(index);
            }
        }
    }
    return nullptr;
}

/**
 * Sets minimum N-gram probability threshold for replacement candidates.
 * @param threshold New N-Gram probability threshold
 */
void NGramDeasciifier::setThreshold(double _threshold) {
    this->threshold = _threshold;
}

/**
 * Loads asciified same word list. Asciified same words are the words whose asciified versions are also
 * valid Turkish words. For example, ascified version of 'ekşi' is 'eksi', ascified version of 'fön' is 'fon'.
 */
void NGramDeasciifier::loadAsciifiedSameList() {
    asciifiedSame = StringUtils::readHashMap("asciified-same.txt");
}
