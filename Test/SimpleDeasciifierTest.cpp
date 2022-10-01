//
// Created by Olcay Taner YILDIZ on 4.01.2021.
//

#include "catch.hpp"
#include "../src/SimpleDeasciifier.h"
#include "../src/SimpleAsciifier.h"

TEST_CASE("SimpleDeasciifierTest-testDeasciify") {
    FsmMorphologicalAnalyzer fsm = FsmMorphologicalAnalyzer();
    SimpleDeasciifier simpleDeasciifier = SimpleDeasciifier(fsm);
    REQUIRE("hakkında" == simpleDeasciifier.deasciify(new Sentence("hakkinda"))->to_string());
    REQUIRE("küçük" == simpleDeasciifier.deasciify(new Sentence("kucuk"))->to_string());
    REQUIRE("karşılıklı" == simpleDeasciifier.deasciify(new Sentence("karsilikli"))->to_string());
}