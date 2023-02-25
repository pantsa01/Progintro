#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool check (int sum, int p[]);

void sort (int list[]);

bool checkIfExists (int list[], int num);

int main ()
{
  int N;
  int p[10];
  int sum;
  int list[100];
  int pos=0;

  for (int i = 0; i < 100; i++)
  {
    list[i]=-1;
  }
  cin >> N;


  for (int i = 0;  i < 10; i++)
  {
    p[i] = pow ( i , N );
  }

  for (int i1 = 0; i1 < 9; i1++)
    {
      for (int i2 = 0; i2 < 9 - i1; i2++)
      {
        for (int i3 = 0; i3 < 9 - i1 - i2; i3++)
        {
          for (int i4 = 0 ; i4 < 9 - i1 - i2 - i3 ; i4++)
          {
            for (int i5 = 0 ; i5 < 9 - i1 - i2 - i3 - i4 ; i5++)
            {
              for (int i6 = 0 ; i6 < 9 - i1 - i2 - i3 - i4 - i5 ; i6++)
              {
                for (int i7 = 0 ; i7 < 9 - i1 - i2 - i3 - i4 - i5 - i6 ; i7++)
                {
                  for (int i8 = 0 ; i8 < 9 - i1 - i2 - i3 - i4 - i5 - i6 - i7 ; i8++)
                  {
                    for (int i9 = 0 ; i9 < 9 - i1 - i2 - i3 - i4 - i5 - i6 - i7 - i8 ; i9++)
                    {
                      sum= i1 * p[1] + i2 * p[2] + i3 * p[3] + i4 * p[4] + i5 * p[5] + i6 * p[6] + i7 * p[7] + i8 * p[8] + i9 * p[9];


                      if (check (sum, p) && !checkIfExists (list, sum))
                      {
                        list[pos]=sum;
                        pos++;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    sort (list);
}

 bool checkIfExists (int list[],int num)
 {
   for (int i=0; i<100; i++)
   {
     if (list[i]==num)return true;
   }
   return false;
 }


void sort (int* list)
{
   sort (list, list + 100);
   for (int i =1; i<100; i++)
   {
     if (list [i]>=0) cout << list [i] << endl;
   }
}

bool check (int sum, int p[])
{
  int num=0;
  int temp = sum;
  int dig[8];

  for (int i=0; i<8; i++)
  {
    dig[i] = temp % 10;
    temp /= 10;
    num += p[dig[i]];
  }
  if (num == sum)
    return true;
  else
    return false;
}
