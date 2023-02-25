#include <iostream>
using namespace std;

int ascii_to_encryptionPos (char ch)
{
  if (ch <= 90)
    return ch - 65;
  else
    return ch - 71;
}

bool letter (char ch)
{
  if ((ch >= 65 and ch <= 90) or (ch >= 97 and ch <= 132))
    return true;
  else
    return false;
}


bool check_code (char encryption[])
{
  char usedlet[26];

  for (int i = 0; i < 26; i++)
    if (encryption[i] < 65 or encryption[i] > 90)
      return false;
  for (int i = 0; i < 26; i++)
  {
    for (int j = 0; j < i; j++)
      if (usedlet[j] == encryption[i])
        return false;

    usedlet[i] = encryption[i];
  }
  return true;
}


int main()
{
  char encryption[52];
  string plaintext;
  string cyphertext;
  char new_letter;

  for (int i = 26; i < 52; i++)
    encryption[i] = getchar();

  for (int i = 0; i < 26; i++)
    encryption[i] = encryption[i+26] - 32;

  if (!check_code (encryption))
  {
    cout << "error" << endl;
    return 0;
  }

  while (getchar() != '\n');

  while (true)
  {
    new_letter = getchar();

    if (new_letter == EOF)
      break;
    else
      plaintext += new_letter;
  }

  for (unsigned int i = 0; i < plaintext.length(); i++)
  {
    if (letter (plaintext[i]))
      new_letter = encryption [ascii_to_encryptionPos (plaintext[i])];
    else
      new_letter = plaintext[i];

    cyphertext += new_letter;
  }
  cout << cyphertext;
}
