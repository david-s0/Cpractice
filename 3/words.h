#ifndef WORDS_H
#define WORDS_H

//reverse a string
void reverse(const char *word, char *reversed);

//check if two strings are equal (ignoring case), returns 1 on true and 0 on false
int compare(const char *sentence1, const char *sentence);

//check if a string is a palindrome, returns 1 on true and 0 on false
int palindrome(const char *sentence);

//check if a string is an anagram of another, returns 1 on true and 0 on false
int anagram(const char *str1, const char *str2);

//sort a string's characters
void insertionSort(char *sorted);

#endif
