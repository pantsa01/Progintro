#include <iostream>
#include <iomanip>
using namespace std;

int stringLength (char string[]);
bool palindrom (char string[], int length);

int main()
{
  int n;
  cin >> n;

  while (getchar()!= '\n');

  char string[100];
  int length;
  int PalindrCount=0;
  double perc;

  for (int i = 0; i<n; i++)
  {
    cin.getline (string,200);
    length=stringLength(string);

    if (length==0)
      cout << "empty";

    else if  (length > 20)
      cout << "error";

    else if (palindrom (string, length))
    {
      cout << "yes";
      PalindrCount ++;
    }

    else
      cout << "no";
    cout << endl;
  }

  perc = PalindrCount * 100.0 / n;
  cout << setprecision (3) << fixed << perc << endl;
}

int stringLength (char string[])
{
  int count = 0;
  while (string[count] != '\0') count ++;
  return count;
}
bool palindrom (char string[], int length)
{
  int count =0;
  for (int i=0; i<length/2;i++)
  {
    if (string[i]==string[length - 1-i]) count ++;
  }
  if (count == length /2 ) return true;
  else return false;
}
