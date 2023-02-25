#include <iostream>
using namespace std;

void decryptionList (char encryption[]);
char letter (char ch);
bool check_code (char encryption[]);
inline void skipln (){while (getchar() != '\n');};
string get_plaintext ();
string get_cyphertext (string plaintext, char encryption[]);

int main()
{
  char encryption[26];
  string plaintext;
  string cyphertext;

  for (int i = 0; i < 26; i++)
    encryption[i] = getchar();

  if (!check_code (encryption))
  {
    cout << "error" << endl;
    return 0;
  }
  skipln();

  if (getchar() == 'd')
    decryptionList (encryption);
  skipln();
  plaintext = get_plaintext();
  cyphertext = get_cyphertext (plaintext, encryption);

  cout << cyphertext;
}


string get_cyphertext (string plaintext, char encryption[])
{
  const int CapSm = 'a' - 'A';
  string cyphertext;
  char new_letter;

  for (unsigned int i = 0; i < plaintext.length(); i++)
  {
    switch (letter (plaintext[i]))
    {
      case 's':
        new_letter = encryption [plaintext[i]- 'a'];
        break;
      case 'C':
        new_letter = encryption [plaintext[i] - 'A'] - CapSm;
        break;
      case '-':
        new_letter = plaintext[i];
    }
    cyphertext += new_letter;
  }
  return cyphertext;
}

string get_plaintext ()
{
  char new_letter;
  string plaintext;
  while (true)
  {
    new_letter = getchar();

    if (new_letter == EOF)
      break;
    else
      plaintext += new_letter;
  }
  return plaintext;
}


void decryptionList (char* encryption)
{
  char decryption[26];
  for (int ch = 'a'; ch <= 'a'; ch++)
    for (int i = 0; i < 26; i++)
      if (encryption[i] == ch)
        decryption[ch-'a'] = i+'a';

  for (int i = 0; i < 26; i++)
    encryption[i]=decryption[i];
}

char letter (char ch)
{
  if (ch >= 'a' and ch <= 'z')
    return 's';
  else if (ch >= 'A' and ch <= 'Z')
    return 'C';
  else
    return '-';
}

bool check_code (char encryption[])
{
  char usedlet[26];
  for (int i = 0; i <26; i++)
    if (encryption[i] < 'a' or encryption[i] > 'z')
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
