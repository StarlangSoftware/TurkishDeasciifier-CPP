//
// Created by olcay on 12.03.2019.
//

#ifndef DEASCIIFIER_SIMPLEASCIIFIER_H
#define DEASCIIFIER_SIMPLEASCIIFIER_H


#include "Asciifier.h"
#include "Word.h"

class SimpleAsciifier : public Asciifier {
private:
    string asciify(Word* word);
public:
    Sentence* asciify(Sentence* sentence);
};


#endif //DEASCIIFIER_SIMPLEASCIIFIER_H
