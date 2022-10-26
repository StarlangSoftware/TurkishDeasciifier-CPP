//
// Created by Olcay Taner Yıldız on 2019-03-12.
//

#ifndef DEASCIIFIER_NGRAMDEASCIIFIER_H
#define DEASCIIFIER_NGRAMDEASCIIFIER_H


#include <FsmMorphologicalAnalyzer.h>
#include <unordered_map>
#include "NGram.h"
#include "SimpleDeasciifier.h"

using namespace std;

class NGramDeasciifier : SimpleDeasciifier {
private:
    NGram<string> nGram = NGram<string>(1);
    bool rootNGram = false;
    double threshold = 0.0;
    unordered_map<string, string> asciifiedSame;
public:
    NGramDeasciifier(const FsmMorphologicalAnalyzer& fsm, const NGram<string>& nGram, bool rootNGram);
    Word* checkAnalysisAndSetRoot(Sentence* sentence, int index);
    void setThreshold(double threshold);
    void loadAsciifiedSameList();
    Sentence* deasciify(Sentence* sentence) override;
};


#endif //DEASCIIFIER_NGRAMDEASCIIFIER_H
