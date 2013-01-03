#include <cctype>
#include <iostream>
#include <cstring>
#include "soundex.h"

using namespace std;

//FUNCTION DEFINITION FOR void (const char *, char *)
void encode(const char *surname, char *soundex)
{
  //first letter is the first char of soundex
  soundex[0] = surname[0];
  //the middle ones will be 0s unless a letter encoding is found
  soundex[1] = '0';
  soundex[2] = '0';
  soundex[3] = '0';
  //last char of soundex is the end of the string
  soundex[4] = '\0';
  //move to the next char of soundex
  soundex++;

  //loop through the rest of the surname
  //k is a counter used to ensure that we just create 3 digits for soundex
  for (int i = 1, k = 0; (surname[i] != '\0') && (k < 3); i++)
    {
      char temp_soundex = encode_one(surname[i]);
      if (temp_soundex == 'E')
	{
	  continue;
	}
      if (temp_soundex == encode_one(surname[i - 1]))
	{
	  continue;
	}
      else
	{
	  *soundex = temp_soundex;
	  soundex++;
	  k++;
	}
    }
  //if soundex length < 5, add 0s at the end

}
//END OF FUNCTION DEFINITION

//START OF FUNCTION DEFINITION FOR void encode_one(const char, char)
char encode_one(const char surname)
{
  switch(surname)
	{
	  //if the letter is a, e, h, i, o, u, w and y, ignore it
	case 'a':
	case 'e':
	case 'h':
	case 'i':
	case 'o':
	case 'u':
	case 'w':
	case 'y':
	  break;
	  //if the letter is b, f, p, v, the encoding_char is 1
	case 'b':
	case 'f':
	case 'p':
	case 'v':
	  return '1';
	  break;
	  //if the letter is c, g, j, k, q, s, x, z, the encoding_char is 2
	case 'c':
	case 'g':
	case 'j':
	case 'k':
	case 'q':
	case 's':
	case 'x':
	case 'z':
	  return '2';
	  break;
	  //if the letter is d, t, the encoding_char is 3
	case 'd':
	case 't':
	  return '3';
	  break;
	  //if the letter is l, the encoding_char is 4
	case 'l':
	  return '4';
	  break;
	  //if the letter is m and n, the encoding_char is 5
	case 'm':
	case 'n':
	  return '5';
	  break;
	  //if the letter is r, the encoding_char is 6
	case 'r':
	  return '6';
	  break;
	}
  return 'E';
}
//END OF FUNCTION DEFINITION

//FUNCTION DEFINITION FOR int compare(char *, char *);
int compare(const char *soundex1, const char *soundex2)
{
  //create a return value
  int comparison;

  //cout << "soundex1 == " << soundex1 << " soundex2 == " << soundex2 << endl;

  //if you arrived at the end of the string start returning with 1
  if (*soundex2 == '\0')
    {
      return 1;
    }

  //if you find a difference, return with 0
  if (*soundex1 != *soundex2)
    {
      return 0;
    }

  //more forward in the strings
  soundex1++;
  soundex2++;

  //return value = compare(soundex1, soundex2)
  comparison = compare(soundex1, soundex2);

  //return the return value, that should be 1 or 0 now
  return comparison;
}
//END OF FUNCTION DEFINITION

//FUNCTION DEFINITION FOR int count(const char *, const char *)
int count(const char *surname, const char *sentence)
{
  //initialise a counter
  int counter;
  char temp_surname[100];
  char soundex_temp[5];
  //soundex that we are looking for
  char soundex_surname[5];
  encode(surname, soundex_surname);

  //loop through the sentence
  for (int i = 0, k = 0; sentence[i] != '\0'; i++)
    {
      if (isalpha(sentence[i]))
	{
	  //as long as you find characters, store them in temp_surname
	  temp_surname[k] = sentence[i];
	  k++;
	}
      else
	{
	  //if you are at the end of a surname in the sentence, do the comparison
	  temp_surname[k] = '\0';
	  encode(temp_surname, soundex_temp);
	  if (!strcmp(soundex_surname, soundex_temp))
	    {
	      //increase the counter every time you find the encoding
	      counter++;
	    }
	  k = 0;
	}
    }

  //return the return value
  return counter;
}
//END OF FUNCTION DEFINITION
