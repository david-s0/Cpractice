#ifndef BRAILLE_H
#define BRAILLE_H

#include <iostream>

//encode one character into braille
int encode_character(char input, char* braille);

//encode a whole word into braille
void encode(const char* word, char* braille);

//print the braille encoding of a 3x2 braille block
void print_braille(const char* word, std::ostream &out);

#endif
