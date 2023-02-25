#include <iostream>
#include <iomanip>
using namespace std;
void readArray (double array[][100], int &N, int &M);
void average (double array[][100], int first, int second, int N);

int main()
{
  int N,M;
  double array[100][100];
  readArray (array, N, M);
  average (array, N, M, N);
  average (array, N, M, N);

}

void readArray (double array[][100], int &N, int &M)
{
  cin >> N >> M;
  for (int i = 0; i<N;i++)
  {
    for (int j =0;j<M;j++)
    {
      cin >> array[i][j];

    }
  }
}

void average (double array[][100], int first, int second, int N)
{
  double averages[first];
  double finalAvrg;
  double sum;
  for (int i=0;i<first;i++)
  {
    sum=0;
    for (int j=0;j<second;j++)
    {
      if (first==N)
        sum += array[i][j];
      else
         sum += array[i][j];
    }
    averages[i] = sum/second;
  }
  sum=0;
  for (int i =0;i<first;i++)
  {
    sum += averages[i];
  }
  finalAvrg=sum/first;
  cout << setprecision(3) << fixed << finalAvrg << endl;
}
