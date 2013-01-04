#include <iostream>
#include <cstring>
#include <cctype>
#include "braille.h"

using namespace std;

//START OF FUNCTION DEFINITION FOR int encode_character(char, char*)
int encode_character(char input, char* braille)
{
  //digit and upper flags, will be used later if needed
  bool upper = false;
  static const char *dig = "..0000";
  static const char *up = ".....0";

  // Braille dictionary for alphabetical letters, stolen from Dave to avoid all the typing
  static const char *alpha[26] = {"0.....", "00....", "0..0..", "0..00.", "0...0.", "00.0..", "00.00.", "00..0.", ".0.0..", ".0.00.", "0.0...", "000...", "0.00..", "0.000.", "0.0.0.", "0000..", "00000.", "000.0.", ".000..", ".0000.", "0.0..0", "000..0", ".0.000", "0.00.0", "0.0000", "0.0.00"};

  // Braille dictionary for digits, for laziness when looking up, stolen from Dave to avoid all the typing
  static const char *num[10] = {".0.00.", "0.....", "00....", "0..0..", "0..00.", "0...0.", "00.0..","00.00.", "00..0.", ".0.0.."};

  //Braille dictionary for punctuation
  static const char *punct[7] = {".0..00", ".0....", ".00...", "..0..0", ".00.0.", ".00..0", ".00.00"};

  //check for special input types
  //if you find punctuation, process it and exit
  if (ispunct(input))
    {
      switch (input)
	{
	case '.':
	  strcpy(braille, punct[0]);
	  break;
	case ',':
	  strcpy(braille, punct[1]);
	  break;
	case ';':
	  strcpy(braille, punct[2]);
	  break;
	case '-':
	  strcpy(braille, punct[3]);
	  break;
	case '!':
	  strcpy(braille, punct[4]);
	  break;
	case '?':
	  strcpy(braille, punct[5]);
	  break;
	case '(':
	case ')':
	  strcpy(braille, punct[6]);
	  break;
        default:
	  cerr << "Punctuation was detected but no braille encoding was found.";
	  break;
	}
    }
  else if (isdigit(input))
    {
      switch (input)
	{
	case '0':
	  strcpy(braille, dig);
	  strcat(braille, num[0]);
	  break;
	case '1':
	  strcpy(braille, dig);
	  strcat(braille, num[1]);
	  break;
	case '2':
	  strcpy(braille, dig);
	  strcat(braille, num[2]);
	  break;
	case '3':
	  strcpy(braille, dig);
	  strcat(braille, num[3]);
	  break;
	case '4':
	  strcpy(braille, dig);
	  strcat(braille, num[4]);
	  break;
	case '5':
	  strcpy(braille, dig);
	  strcat(braille, num[5]);
	  break;
	case '6':
	  strcpy(braille, dig);
	  strcat(braille, num[6]);
	  break;
	case '7':
	  strcpy(braille, dig);
	  strcat(braille, num[7]);
	  break;
	case '8':
	  strcpy(braille, dig);
	  strcat(braille, num[8]);
	  break;
	case '9':
	  strcpy(braille, dig);
	  strcat(braille, num[9]);
	  break;
	default:
	  cerr << "A digit was detected but no braille encoding was found.";
	  break;
	}
    }
  else if (isalpha(input))
    {
      if (isupper(input))
	{
	  upper = true;
	  strcpy(braille, up);
	  input = tolower(input);
	}
      switch (input)
	{
	case 'a':
	  if (upper)
	    {
	      strcat(braille, alpha[0]);
	    }
	  else
	    {
	      strcpy(braille, alpha[0]);
	    }
	  break;
	case 'b':
	  if (upper)
	    {
	      strcat(braille, alpha[1]);
	    }
	  else
	    {
	      strcpy(braille, alpha[1]);
	    }
	  break;
	case 'c':
	  if (upper)
	    {
	      strcat(braille, alpha[2]);
	    }
	  else
	    {
	      strcpy(braille, alpha[2]);
	    }
	  break;
	case 'd':
	  if (upper)
	    {
	      strcat(braille, alpha[3]);
	    }
	  else
	    {
	      strcpy(braille, alpha[3]);
	    }
	  break;
	case 'e':
	  if (upper)
	    {
	      strcat(braille, alpha[4]);
	    }
	  else
	    {
	      strcpy(braille, alpha[4]);
	    }
	  break;
	case 'f':
	  if (upper)
	    {
	      strcat(braille, alpha[5]);
	    }
	  else
	    {
	      strcpy(braille, alpha[5]);
	    }
	  break;
	case 'g':
	  if (upper)
	    {
	      strcat(braille, alpha[6]);
	    }
	  else
	    {
	      strcpy(braille, alpha[6]);
	    }
	  break;
	case 'h':
	  if (upper)
	    {
	      strcat(braille, alpha[7]);
	    }
	  else
	    {
	      strcpy(braille, alpha[7]);
	    }
	  break;
	case 'i':
	  if (upper)
	    {
	      strcat(braille, alpha[8]);
	    }
	  else
	    {
	      strcpy(braille, alpha[8]);
	    }
	  break;
	case 'j':
	  if (upper)
	    {
	      strcat(braille, alpha[9]);
	    }
	  else
	    {
	      strcpy(braille, alpha[9]);
	    }
	  break;
	case 'k':
	  if (upper)
	    {
	      strcat(braille, alpha[10]);
	    }
	  else
	    {
	      strcpy(braille, alpha[10]);
	    }
	  break;
	case 'l':
	  if (upper)
	    {
	      strcat(braille, alpha[11]);
	    }
	  else
	    {
	      strcpy(braille, alpha[11]);
	    }
	  break;
	case 'm':
	  if (upper)
	    {
	      strcat(braille, alpha[12]);
	    }
	  else
	    {
	      strcpy(braille, alpha[12]);
	    }
	  break;
	case 'n':
	  if (upper)
	    {
	      strcat(braille, alpha[13]);
	    }
	  else
	    {
	      strcpy(braille, alpha[13]);
	    }
	  break;
	case 'o':
	  if (upper)
	    {
	      strcat(braille, alpha[14]);
	    }
	  else
	    {
	      strcpy(braille, alpha[14]);
	    }
	  break;
	case 'p':
	  if (upper)
	    {
	      strcat(braille, alpha[15]);
	    }
	  else
	    {
	      strcpy(braille, alpha[15]);
	    }
	  break;
	case 'q':
	  if (upper)
	    {
	      strcat(braille, alpha[16]);
	    }
	  else
	    {
	      strcpy(braille, alpha[16]);
	    }
	  break;
	case 'r':
	  if (upper)
	    {
	      strcat(braille, alpha[17]);
	    }
	  else
	    {
	      strcpy(braille, alpha[17]);
	    }
	  break;
	case 's':
	  if (upper)
	    {
	      strcat(braille, alpha[18]);
	    }
	  else
	    {
	      strcpy(braille, alpha[18]);
	    }
	  break;
	case 't':
	  if (upper)
	    {
	      strcat(braille, alpha[19]);
	    }
	  else
	    {
	      strcpy(braille, alpha[19]);
	    }
	  break;
	case 'u':
	  if (upper)
	    {
	      strcat(braille, alpha[20]);
	    }
	  else
	    {
	      strcpy(braille, alpha[20]);
	    }
	  break;
	case 'v':
	  if (upper)
	    {
	      strcat(braille, alpha[21]);
	    }
	  else
	    {
	      strcpy(braille, alpha[21]);
	    }
	  break;
	case 'w':
	  if (upper)
	    {
	      strcat(braille, alpha[22]);
	    }
	  else
	    {
	      strcpy(braille, alpha[22]);
	    }
	  break;
	case 'x':
	  if (upper)
	    {
	      strcat(braille, alpha[23]);
	    }
	  else
	    {
	      strcpy(braille, alpha[23]);
	    }
	  break;
	case 'y':
	  if (upper)
	    {
	      strcat(braille, alpha[24]);
	    }
	  else
	    {
	      strcpy(braille, alpha[24]);
	    }
	  break;
	case 'z':
	  if (upper)
	    {
	      strcat(braille, alpha[25]);
	    }
	  else
	    {
	      strcpy(braille, alpha[25]);
	    }
	  break;
	default:
	  cerr << "A character was detected but no braille encoding was found.";
	  break;
	}
    }

  return strlen(braille);
}
//END OF FUNCTION DEFINITION

//START OF FUNCTION DEFINITION FOR void encode(const char*, char*)
void encode(const char *word, char *braille)
{
  //base case: end of string
  if (*word == '\0')
    {
      return;
    }
 
  //encode string
  char braille_one[512];
  braille_one[0] = '\0';
  encode_character(word[0], braille_one);

  //concatenate
  strcat(braille, braille_one);

  //move forward 1 char
  word++;

  //call recursively
  encode(word, braille);
}
//END OF FUNCTION DEFINITION

//START OF FUNCTION DEFINITION FOR void print_braille(const char*, ostream *)
void print_braille(const char *word, ostream &out)
{
  //encode
  char encoded[512];
  encoded[0] = '\0';
  encode(word, encoded);

  //output
  out << encoded[0] << encoded[1] << " " << encoded[6] << encoded[7] << " " << encoded[12] << encoded[13] << endl;
  out << encoded[2] << encoded[3] << " " << encoded[8] << encoded[9] << " " << encoded[14] << encoded[15] << endl;
  out << encoded[4] << encoded[5] << " " << encoded[10] << encoded[11] << " " << encoded[16] << encoded[17] << endl;
  out << word << endl;
  

}
//END OF FUNCTION DEFINITION
