//
// Created by Olcay Taner YILDIZ on 4.01.2021.
//

#include "catch.hpp"
#include "../src/SimpleDeasciifier.h"
#include "../src/SimpleAsciifier.h"

TEST_CASE("SimpleDeasciifierTest-testDeasciify") {
    FsmMorphologicalAnalyzer fsm = FsmMorphologicalAnalyzer();
    SimpleDeasciifier simpleDeasciifier = SimpleDeasciifier(fsm);
    SimpleAsciifier simpleAsciifier = SimpleAsciifier();
    for (int i = 0; i < fsm.getDictionary().size(); i++){
        TxtWord* word = (TxtWord*) fsm.getDictionary().getWord(i);
        int count = 0;
        for (int j = 0; j < Word::size(word->getName()); j++){
            string ch = Word::charAt(word->getName(), j);
            if (ch == "ç" || ch == "ö" || ch == "ğ" || ch == "ü" || ch == "ş" || ch == "ı"){
                count++;
            }
        }
        if (count > 0 && !Word::endsWith(word->getName(), "fulü") && (word->isNominal() || word->isAdjective() || word->isAdverb() || word->isVerb())){
            string asciified = simpleAsciifier.asciify(word);
            if (simpleDeasciifier.candidateList(new Word(asciified)).size() == 1){
                string deasciified = simpleDeasciifier.deasciify(new Sentence(asciified))->to_string();
                REQUIRE(word->getName() == deasciified);
            }
        }
    }
}