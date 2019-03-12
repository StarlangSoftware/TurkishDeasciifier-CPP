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
    void generateCandidateList(vector<string>& candidates, string word, int index);
};


#endif //DEASCIIFIER_SIMPLEDEASCIIFIER_H
