//
// Created by olcay on 12.03.2019.
//

#ifndef DEASCIIFIER_SIMPLEDEASCIIFIER_H
#define DEASCIIFIER_SIMPLEDEASCIIFIER_H

#include "FsmMorphologicalAnalyzer.h"
#include "Deasciifier.h"

class SimpleDeasciifier : public Deasciifier{
protected:
    FsmMorphologicalAnalyzer fsm;
private:
    void generateCandidateList(vector<string>& candidates, const string& word, int index) const;
public:
    explicit SimpleDeasciifier(const FsmMorphologicalAnalyzer& fsm);
    vector<string> candidateList(Word* word);
    Sentence* deasciify(Sentence* sentence) override;
};


#endif //DEASCIIFIER_SIMPLEDEASCIIFIER_H
