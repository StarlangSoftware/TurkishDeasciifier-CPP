//
// Created by olcay on 12.03.2019.
//

#include "SimpleDeasciifier.h"

/**
 * The generateCandidateList method takes an {@link vector} candidates, a {@link String}, and an integer index as inputs.
 * First, it creates a {@link String} which consists of corresponding Latin versions of special Turkish characters. If given index
 * is less than the length of given word and if the item of word's at given index is one of the chars of {@link String}, it loops
 * given candidates {@link vector}'s size times and substitutes Latin characters with their corresponding Turkish versions
 * and put them to newly created char {@link vector} modified. At the end, it adds each modified item to the candidates
 * {@link vector} as a {@link String} and recursively calls generateCandidateList with next index.
 *
 * @param candidates {@link vector} type input.
 * @param word       {@link String} input.
 * @param index      {@link Integer} input.
 */
void SimpleDeasciifier::generateCandidateList(vector<string> &candidates, string word, int index) {

}
