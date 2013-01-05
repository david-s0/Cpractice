#include "piglatin.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

//START OF FUNCTION DEFINITION FOR int findFirstVowel(const char *)
int findFirstVowel(const char *word)
{
  //start looping through the word
  for (int i = 0; word[i] != '\0'; i++)
    {
      //pass the current char, the counter and the  length of the word to isVowel
      if (isVowel(word[i], i, strlen(word)))
	{
	  return i;
	}
    }
  
  //if you couldn't find a vowel, return -1
  return -1;
}
//END OF FUNCTION DEFINITION

//START OF FUNCTION DEFINITION FOR void translateWord(const char *, char *)
void translateWord(const char *english, char *piglatin)
{
  for (int i = 0; i < 100; i++)
    {
      piglatin[i] = '\0';
    }

  //find first vowel's position
  int vowel = findFirstVowel(english);

  //if position == 0, add "way" to the word
  if (vowel == 0)
    {
      strcpy(piglatin, english);
      strcat(piglatin, "way");
    }

  //if the first char is a digit, do nothing
  if (isdigit(*english))
    {
      strcpy(piglatin, english);
    }

  //if the word contains no vowels just add “ay” to it
  if (vowel == -1)
    {
      strcpy(piglatin, english);
      strcat(piglatin, "ay");
    }

  //if the word begins with a letter that is not a vowel, find the first occurence of a vowel, move all the characters before the vowel to the end of the word, and add “ay”
  if (vowel > 0)
    {
      //copy the english string to the piglatin one from the vowel to the end
      for (int i = vowel, j = 0; english[i] != '\0'; i++, j++)
	{
	  piglatin[j] = english[i];
	}
      //copy the beginning consonants at the end of the word
      for (int i = 0, j = (strlen(english) - vowel); i < vowel; i++, j++)
	{
	  piglatin[j] = english[i];
	}
      //add tail
      strcat(piglatin, "ay");
    }

  //fix capitalisation
  for (int i = 0; piglatin[i] != '\0'; i++)
    {
      if ((i > 0) && (isupper(piglatin[i])))
	{
	  piglatin[i] = tolower(piglatin[i]);
	  break;
	}
    }
  
  piglatin[0] = toupper(piglatin[0]);
}
//END OF FUNCTION DEFINITION

//START OF FUNCTION DEFINITION FOR void translateStream(istream &, ofstream &);
void translateStream(istream &in, ostream &out)
{
  char line[500] = {'\0'};
  char word[100] = {'\0'};
  int i = 0;

  //loop through the file
  while (!in.eof())
    {
      //get the lines of the poem one by one
      in.getline(line, 100);

      //get one word
      for (int j = 0; line[j] != '\0'; j++)
	{
	  //if you find a non alpha character, output it
	  if (!isalpha(line[j]))
	    {
	      cout << line[j];
	    }
	  else if (line[j] == ' ')
	    {
	      cout << line[j];
	    }
	  //else, get the word and translate it
	  else 
	    {
	      char translated[100] = {'\0'};
	      for (int k = 0; isalpha(line[j]); k++, j++)
		{
		  word[k] = line[j];
		}
	      translateWord(word, translated);
	      cout << translated;
	      j--;
	    }
	}
      cout << endl;
      i++;
    }
  
}
//END OF FUNCTION DEFINITION

//START OF FUNCTION DEFINITION FOR bool isVowel(char, int, int)
bool isVowel(char ch, int position, int length)
{
  //the vowels are a, e, i, o, u and y; but y is only considered a vowel if it is not the first or last letter of the word
  switch (ch)
    {
    case 'a':
    case 'A':
      return true;
      break;
    case 'e':
    case 'E':
      return true;
      break;
    case 'i':
    case 'I':
      return true;
      break;
    case 'o':
    case 'O':
      return true;
      break;
    case 'u':
    case 'U':
      return true;
      break;
    case 'Y':
    case 'y':
      if (position != 0)
	{
	  return true;
	}
      break;
    }

  return false;
}
//END OF FUNCTION DEFINITION
