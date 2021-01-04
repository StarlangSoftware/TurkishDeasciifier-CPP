//
// Created by Olcay Taner YILDIZ on 4.01.2021.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../SimpleAsciifier.h"

TEST_CASE("SimpleAsciifierTest-testWordAsciify") {
    SimpleAsciifier simpleAsciifier = SimpleAsciifier();
    REQUIRE("cogusiCOGUSI" == simpleAsciifier.asciify(new Word("çöğüşıÇÖĞÜŞİ")));
    REQUIRE("sogus" == simpleAsciifier.asciify(new Word("söğüş")));
    REQUIRE("uckagitcilik" == simpleAsciifier.asciify(new Word("üçkağıtçılık")));
    REQUIRE("akiskanlistiricilik" == simpleAsciifier.asciify(new Word("akışkanlıştırıcılık")));
    REQUIRE("citcitcilik" == simpleAsciifier.asciify(new Word("çıtçıtçılık")));
    REQUIRE("duskirikligi" == simpleAsciifier.asciify(new Word("düşkırıklığı")));
    REQUIRE("yuzgorumlugu" == simpleAsciifier.asciify(new Word("yüzgörümlüğü")));
}

TEST_CASE("SimpleAsciifierTest-testSentenceAsciify") {
    SimpleAsciifier simpleAsciifier = SimpleAsciifier();
    REQUIRE(Sentence("cogus iii COGUSI").to_string() == simpleAsciifier.asciify(new Sentence("çöğüş ııı ÇÖĞÜŞİ"))->to_string());
    REQUIRE(Sentence("uckagitcilik akiskanlistiricilik").to_string() == simpleAsciifier.asciify(new Sentence("üçkağıtçılık akışkanlıştırıcılık"))->to_string());
    REQUIRE(Sentence("citcitcilik duskirikligi yuzgorumlugu").to_string() == simpleAsciifier.asciify(new Sentence("çıtçıtçılık düşkırıklığı yüzgörümlüğü"))->to_string());
}