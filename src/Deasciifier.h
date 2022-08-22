//
// Created by olcay on 12.03.2019.
//

#ifndef DEASCIIFIER_DEASCIIFIER_H
#define DEASCIIFIER_DEASCIIFIER_H


#include <Sentence.h>

class Deasciifier {
public:
    /**
     * The deasciify method which takes a {@link Sentence} as an input and also returns a {@link Sentence} as the output.
     *
     * @param sentence {@link Sentence} type input.
     * @return Sentence result.
     */
    virtual Sentence* deasciify(Sentence* sentence) = 0;
};


#endif //DEASCIIFIER_DEASCIIFIER_H
