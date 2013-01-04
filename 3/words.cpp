#include <cstring>
#include <iostream>
#include "words.h"

using namespace std;

const int SENTENCE_LENGTH = 100;

//START OF FUNCTION DEFINITION FOR void reverse(const char *, char *)
void reverse(const char *word, char *reversed)
{
  //set a pointer to the beginning of the word
  const char* beginning = word;

  //point the word pointer to the end of the string
  word = &word[strlen(word)];

  //loop backwards, copying word into reversed
  while(--word >= beginning)
    {
      *reversed++ = *word;
    }

  //set the sentinel character for reversed
  *reversed = '\0';
}
//END OF FUNCTION DEFINITION 

//START OF FUNCTION DEFINITION FOR int compare(const char *, const char *)
int compare(const char *sentence1, const char *sentence2)
{
  //if both strings are over, return 1
  if ((*sentence1 == '\0') && (*sentence2 == '\0'))
    {
      return 1;
    }
  //if one is over but the other still have alphanums, return 0
  else if ((*sentence1 == '\0') && !(isalpha(*sentence2)))
    {
      sentence2++;
      return compare(sentence1, sentence2);
    }
  else if ((*sentence2 == '\0') && !isalpha(*sentence1))
    {
      sentence1++;
      return compare(sentence1, sentence2);
    }
  //skip non-alphabetic characters
  else if (!isalpha(*sentence1))
    {
      sentence1++;
      return compare(sentence1, sentence2);
    }
  else if (!isalpha(*sentence2))
    {
      sentence2++;
      return compare(sentence1, sentence2);
    }
  //compare the chacters
  else if (tolower(*sentence1) == tolower(*sentence2))
    {
      sentence1++;
      sentence2++;
      return compare(sentence1, sentence2);
    }
  else if (tolower(*sentence1) != tolower(*sentence2))
    {
      return 0;
    }
  
  return 0;
}
//END OF FUNCTION DEFINITION 

//START OF FUNCTION DEFINITION FOR int palindrome(const char *)
int palindrome(const char *sentence)
{
  //create a reversed string
  char sentence_reversed[SENTENCE_LENGTH];
  reverse(sentence, sentence_reversed);

  //compare reversed and sentence
  if (compare(sentence, sentence_reversed))
    {
      return 1;
    }

  return 0;
}
//END OF FUNCTION DEFINITION 

//START OF FUNCTION DEFINITION FOR int anagram(const char *, const char *)
int anagram(const char *str1, const char *str2)
{
  char str1_sorted[SENTENCE_LENGTH];
  strcpy(str1_sorted, str1);
  char str2_sorted[SENTENCE_LENGTH];
  strcpy(str2_sorted, str2);
  
  //sort the letters in the strings
  insertionSort(str1_sorted);
  insertionSort(str2_sorted);

  //compare them
  if (compare(str1_sorted, str2_sorted))
    {
      return 1;
    }

  return 0;
}
//END OF FUNCTION DEFINITION 

//START OF FUNCTION DEFINITION FOR void quicksort(const char *, char *)
void insertionSort(char *sorted)
{
  //given that we are going to be dealing mostly with words or sentences, insertion sort should be a good choice as sorting algorithm (its performance decreases rapidly with large arrays, but is good with small ones)
  int strLength = strlen(sorted);
  char temp;

  for(int i = 1, j; i < strLength; i++)
    {
      temp = tolower(sorted[i]);

      for(j = i - 1; j >= 0 && tolower(sorted[j]) > temp; j--)
	{
	sorted[j + 1] = sorted[j];
	}

      sorted[j + 1] = temp;
    }
}
//END OF FUNCTION DEFINITION 
