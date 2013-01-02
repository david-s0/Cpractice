#include <cstring>
#include "substring.h"

#include <iostream>
using namespace std;

//START OF FUNCTION DEFINITION FOR int substring_position(const char*, const char*)
int substring_position(const char *needle, const char *hay)
{
  //check for the special case of "looking of an empty needle"
  if (strlen(needle) == 0)
    {
      return 0;
    }
  
  //if you arrived at the bottom of the haystack, return the negative value
  if (strlen(hay) == 0)
    {
      return -1;
    }

    //check if the needle is the prefix of the stack
    int pos = 0;
    if (is_prefix(needle, hay))
      {
	//if it is, you have found the needle and can start returning
	return 0;
      }
    else
      {
	//if it isn't, move one position deeper in the haystack and try again
	hay++;
	pos = substring_position(needle, hay);
	//if you are not coming from the bottom of the haystack (-1), return adding the positions found
	if (pos > -1)
	  {
	    return ++pos;
	  }
      }
    
  return -1;
}
//END OF FUNCTION DEFINITION

//START OF FUNCTION DEFINITION FOR bool is_prefix(const char*, const char*)
bool is_prefix(const char *needle, const char *hay)
{
  bool prefix = true;

  //if you reached the end of the needle, you are at the end of the needle, which is probably the prefix of the haystack
  if (needle[0] == '\0')
    {
      return true;
    }

  //if you find a character that doesn't match, this was not a prefix, stop the recursion and exit the function
  if (needle[0] != hay[0])
    {
      prefix = false;
      return prefix;
    }
  
  //the successive recursions progressively move down needle and haystack
  needle++;
  hay++;

  prefix = is_prefix(needle, hay);

  return prefix;
}
//END OF FUNCTION DEFINITION
