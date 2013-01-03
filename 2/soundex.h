#ifndef SOUNDEX_H
#define SOUNDEX

//create the soundex encoding for a given surname
void encode(const char *surname, char *soundex);

//create the soundex encoding for a given letter
char encode_one(const char surname);

//return 1 if the soundex codes are the same, 0 if they are not
int compare(const char *soundex1, const char *soundex2);

//count the words in a given sentence that have the same soundex encoding as a given one
int count(const char *surname, const char *sentence);

#endif
