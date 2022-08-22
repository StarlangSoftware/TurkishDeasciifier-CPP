//
// Created by olcay on 12.03.2019.
//

#ifndef DEASCIIFIER_ASCIIFIER_H
#define DEASCIIFIER_ASCIIFIER_H

#include "Sentence.h"

class Asciifier {
public:
    /**
     * The asciify method which takes a {@link Sentence} as an input and also returns a {@link Sentence} as the output.
     *
     * @param sentence {@link Sentence} type input.
     * @return Sentence result.
     */
    virtual Sentence* asciify(Sentence* sentence) = 0;
};


#endif //DEASCIIFIER_ASCIIFIER_H
