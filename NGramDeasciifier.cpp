//
// Created by Olcay Taner Yıldız on 2019-03-12.
//

#include "NGramDeasciifier.h"

/**
 * A constructor of {@link NGramDeasciifier} class which takes an {@link FsmMorphologicalAnalyzer} and an {@link NGram}
 * as inputs. It first calls it super class {@link SimpleDeasciifier} with given {@link FsmMorphologicalAnalyzer} input
 * then initializes nGram variable with given {@link NGram} input.
 *
 * @param fsm   {@link FsmMorphologicalAnalyzer} type input.
 * @param nGram {@link NGram} type input.
 */
NGramDeasciifier::NGramDeasciifier(FsmMorphologicalAnalyzer fsm, NGram <string> &nGram) : SimpleDeasciifier(fsm) {
    this->nGram = nGram;
}

/**
 * The deasciify method takes a {@link Sentence} as an input. First it creates a String {@link ArrayList} as candidates,
 * and a {@link Sentence} result. Then, loops i times where i ranges from 0 to words size of given sentence. It gets the
 * current word and generates a candidateList with this current word then, it loops through the candidateList. First it
 * calls morphologicalAnalysis method with current candidate and gets the first item as root word. If it is the first root,
 * it gets its N-gram probability, if there are also other roots, it gets probability of these roots and finds out the
 * best candidate, best root and the best probability. At the nd, it adds the bestCandidate to the bestCandidate {@link ArrayList}.
 *
 * @param sentence {@link Sentence} type input.
 * @return Sentence result as output.
 */
Sentence *NGramDeasciifier::deasciify(Sentence *sentence) {
    Word *word, *bestRoot;
    Word *previousRoot = nullptr, *root;
    string bestCandidate;
    double probability, bestProbability;
    vector<string> candidates;
    auto* result = new Sentence();
    for (int i = 0; i < sentence->wordCount(); i++) {
        word = sentence->getWord(i);
        candidates = candidateList(word);
        bestCandidate = nullptr;
        bestRoot = nullptr;
        bestProbability = 0;
        for (const string &candidate : candidates) {
            FsmParseList fsmParseList = fsm.morphologicalAnalysis(candidate);
            root = fsmParseList.getFsmParse(0).getWord();
            if (previousRoot != nullptr) {
                probability = nGram.getProbability({previousRoot->getName(), root->getName()});
            } else {
                probability = nGram.getProbability({root->getName()});
            }
            if (probability > bestProbability) {
                bestCandidate = candidate;
                bestRoot = root;
                bestProbability = probability;
            }
        }
        previousRoot = bestRoot;
        result->addWord(new Word(bestCandidate));
    }
    return result;
}
