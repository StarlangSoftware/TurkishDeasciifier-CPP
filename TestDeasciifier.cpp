//
// Created by olcay on 13.03.2019.
//

#include <FsmMorphologicalAnalyzer.h>
#include <iostream>
#include "SimpleDeasciifier.h"

int main(){
    FsmMorphologicalAnalyzer fsm;
    fsm = FsmMorphologicalAnalyzer();
    SimpleDeasciifier deasciifier = SimpleDeasciifier(fsm);
    Sentence* s1 = new Sentence("cocuk gıttı dun aksam");
    Sentence* s2 = deasciifier.deasciify(s1);
    cout << s2->to_string();
}