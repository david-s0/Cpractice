#ifndef PIGLATIN_H
#define PIGLATIN_H

#include <iostream>
#include <fstream>

using namespace std;

//returns the position of the first “vowel” in the given word, according to the pattern given
int findFirstVowel(const char *word);

//produces a Pig Latin translation for a given English word
void translateWord(const char *english, char *piglatin);

//takes words from an input stream and writes a corresponding Pig Latin translation to an output stream
void translateStream(istream &inputStream, ostream &outputStream);

//returns true if the letter ch at position position in a string with length characters is a “vowel” according to the Pig Latin rules
bool isVowel(char ch, int position, int length);

#endif
