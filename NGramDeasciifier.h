//
// Created by Olcay Taner Yıldız on 2019-03-12.
//

#ifndef DEASCIIFIER_NGRAMDEASCIIFIER_H
#define DEASCIIFIER_NGRAMDEASCIIFIER_H


#include <FsmMorphologicalAnalyzer.h>
#include "NGram.h"
#include "SimpleDeasciifier.h"

class NGramDeasciifier : SimpleDeasciifier {
private:
    NGram<string> nGram = NGram<string>(1);
public:
    NGramDeasciifier(FsmMorphologicalAnalyzer fsm, NGram<string>& nGram);
    Word* checkAnalysisAndSetRoot(Sentence* sentence, int index);
    Sentence* deasciify(Sentence* sentence) override;
};


#endif //DEASCIIFIER_NGRAMDEASCIIFIER_H
