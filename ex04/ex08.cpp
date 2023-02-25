#include <iostream>
using namespace std;

int N, M;

int minMXcol (int array[][100]);
int maxMNrow (int array[][100]);

int main()

{
  cin >> N >> M;
  int array[N][100];
  for (int i=0; i<N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cin >> array[i][j];
    }
  }

  cout << minMXcol (array) << endl << maxMNrow (array) << endl;
}

int minMXcol (int array[][100])
{
  int maxCol[M];
  for (int j = 0; j < M; j++)
  {
    int curMax = array [0][j];
    for (int i = 0;i < N; i++)
    {
      if (array[i][j]>curMax) curMax =array[i][j];
    }
    maxCol[j]=curMax;
  }
  int curMin = maxCol[0];
  for (int j = 0; j < M; j++)
  {
    if (maxCol[j]<curMin) curMin = maxCol[j];
  }
  return curMin;
}


int maxMNrow (int array[][100])
{
  int minRow[N];

  for (int i=0;i<N;i++)
  {
    int curMin=array[i][0];
    for (int j=0;j<M;j++)
    {
      if (array[i][j] <curMin) curMin=array[i][j];
    }
    minRow[i]=curMin;
  }

  int curMin =minRow[0];
  for (int i=0;i<N;i++)
  {
    if (minRow[i]>curMin) curMin = minRow[i];
  }
  return curMin;
}
