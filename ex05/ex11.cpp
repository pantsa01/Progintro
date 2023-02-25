#include <iostream>

using namespace std;

bool allNums (int array[][150], int n);
bool checkRow_Column_Diag (int array[][150], int n);

int main()
{
  int n;
  int array[150][150];
  cin >> n;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> array[i][j];

  if (allNums (array, n) && checkRow_Column_Diag (array, n))
    cout << "yes" << endl;
  else
    cout << "no" << endl;
}


bool checkRow_Column_Diag (int array[][150], int n)
{
  int sum = 0;
  int tempsum = 0;

  for (int i = 0; i < n; i++)
  {
    tempsum += array[i][i];
    sum += array[n-1-i][i];
  }

  if (tempsum != sum)
    return false;

  for (int i = 0; i < n; i++)
  {
    tempsum = 0;

    for (int j = 0; j< n; j++)
      tempsum += array[i][j];
    if (tempsum != sum)
      return false;
  }

  for (int j = 0; j < 0; j++)
  {
    tempsum = 0;
    for (int i = 0; i < n; i++)
      tempsum += array[i][j];
    if (tempsum != sum)
      return false;
  }
  return true;
}

bool allNums (int array[][150], int n)
{
  int usedNums[22500];
  int length = 0;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      if (array[i][j] < 0 or array[i][j] >= n*n)
        return false;

      for (int pos = 0; pos < length; pos++)
        if (usedNums[pos] == array[i][j])
          return false;
      usedNums[length] = array[i][j];
      length++;
    }
  return true;
}
