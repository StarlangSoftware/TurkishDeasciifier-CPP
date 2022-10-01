//
// Created by Olcay Taner YILDIZ on 4.01.2021.
//

#include <FsmMorphologicalAnalyzer.h>
#include "catch.hpp"
#include "../src/NGramDeasciifier.h"
#include "../src/SimpleAsciifier.h"
#include <NoSmoothing.h>
#include <LaplaceSmoothing.h>
#include <Corpus.h>

TEST_CASE("NGramDeasciifierTest-testDeasciify2") {
    FsmMorphologicalAnalyzer fsm = FsmMorphologicalAnalyzer();
    auto* nGram = new NGram<string>("ngram.txt");
    NoSmoothing<string> noSmoothing;
    noSmoothing.setProbabilities(*nGram);
    NGramDeasciifier nGramDeasciifier = NGramDeasciifier(fsm, *nGram, false);
    REQUIRE("noter hakkında" == nGramDeasciifier.deasciify(new Sentence("noter hakkinda"))->to_string());
    REQUIRE("sandık medrese" == nGramDeasciifier.deasciify(new Sentence("sandik medrese"))->to_string());
    REQUIRE("kuran'ı karşılıklı" == nGramDeasciifier.deasciify(new Sentence("kuran'ı karsilikli"))->to_string());
}

TEST_CASE("NGramDeasciifierTest-testDeasciify3") {
    FsmMorphologicalAnalyzer fsm = FsmMorphologicalAnalyzer();
    auto* nGram = new NGram<string>("ngram.txt");
    LaplaceSmoothing<string> simpleSmoothing;
    simpleSmoothing.setProbabilities(*nGram);
    NGramDeasciifier nGramDeasciifier = NGramDeasciifier(fsm, *nGram, true);
    REQUIRE("dün akşam yeni aldığımız çam ağacını süsledik" == nGramDeasciifier.deasciify(new Sentence("dün aksam yenı aldıgımız cam ağacını susledık"))->to_string());
    REQUIRE("ünlü sanatçı tartışmalı konu hakkında demeç vermekten kaçındı" == nGramDeasciifier.deasciify(new Sentence("unlu sanatçı tartismali konu hakkinda demec vermekten kacindi"))->to_string());
    REQUIRE("köylü de durumdan oldukça şikayetçiydi" == nGramDeasciifier.deasciify(new Sentence("koylu de durumdan oldukca şikayetciydi"))->to_string());
}