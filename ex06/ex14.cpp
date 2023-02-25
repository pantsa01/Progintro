#include <iostream>
using namespace std;

void sort (int a[], int first, int last);
int partition (int a[], int first, int last);
void swap (int &a, int &b);


int main()
{
  int n;
  cin >> n;

  int a[n], b[n];
  int min = 100000000, max = 0;
  bool equal = true;

  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];

  sort (a, 0, n-1);
  sort (b, 0, n-1);

  for (int i = 0; i < n; i++)
  {
    if (a[i] != b[i])
    {
      if (a[i] < min)
        min = a[i];
      if (a[i] > max)
        max = a[i];
      if (b[i] < min)
        min = b[i];
      if (b[i] > max)
        max = b[i];
      equal = false;
    }
  }

  if (equal)
    cout << "yes" << endl;
  else
    cout << "no " << min << ' ' << max << endl;
}

void swap (int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}
int partition (int a[], int first, int last)
{
  int pivot = a[first];

  while (true)
  {
    for (; a[first] < pivot; first++);
    for (; a[last] > pivot; last--);
    if (first >= last)
      break;

    swap (a[first], a[last]);
    first++;
    last--;
  }
  return last;
}

void sort (int a[], int first, int last)
{
  int i;
  if (first >= last)
    return;

  i = partition (a, first, last);
  sort (a, first, i);
  sort (a, i+1, last);
}
