#include <iostream>
using namespace std;

struct node
{
  int data;
  node *next;
  node *previous;
};

class list
{
  public:
    bool empty();
    int size();
    void add (int k, int x);
    int get (int k);
    void remove (int k);
    node *list_head;
};

bool list::empty()
{
  if (list_head == NULL)
    return true;
  else
    return false;
}

int list::size()
{
  int count = 0;
  node *aux;
  aux = list_head;
  while (aux != NULL)
  {
    count++;
    aux = (aux->next);
  }
  return count;
}
void list::add (int k, int x)
{
  int i;
  node *aux1, *aux4, *temp;
  aux1 = list_head;
  if (list_head == NULL and k == 1)
  {
    node *neos = new (nothrow) node;
    neos->data = x;
    neos->next = NULL;
    neos->previous = NULL;
    list_head = neos;
  }
  else if (list_head != NULL and k == 1)
  {
    node *neos2 = new (nothrow) node;
    aux4 = list_head;
    neos2->data = x;
    neos2->next = aux4;
    neos2->previous = NULL;
    aux4->previous = neos2;
    list_head = neos2;
  }
  else
  {
    for (i = 2; i < k; i++)
      aux1 = (aux1->next);
    if (aux1->next == NULL)
    {
      node *neos1 = new (nothrow) node;
      aux1->next = neos1;
      neos1->data = x;
      neos1->previous = aux1;
    }
    else
    {
      aux1 = (aux1->next);
      node *neos4 = new (nothrow) node;
      temp = aux1->previous;
      aux1->previous = neos4;
      neos4->data = x;
      neos4->next = aux1;
      neos4->previous = temp;
      temp->next = neos4;
    }
  }
}

int list::get(int k)
{
  int i;
  node *aux2;
  aux2 = list_head;
  for (i = 2; i <= k; i++)
    aux2 = (aux2->next);
  return aux2->data;
}
void list::remove(int k)
{
  int i;
  node *aux3, *temp;
  aux3 = list_head;
  for (i = 2; i < k; i++)
    aux3 = (aux3->next);
  if (aux3->next == NULL)
    delete aux3;
  else
  {
    temp = (aux3->next)->next;
    if (temp == NULL)
    {
      if (k == 1)
      {
        temp = aux3->next;
        delete aux3;
        list_head = temp;
        temp->previous = NULL;
      }
      else
      {
        delete aux3->next;
        aux3->next = NULL;
      }
    }
    else
    {
      if (k == 1)
      {
        temp = aux3->next;
        delete aux3;
        list_head = temp;
        temp->previous = NULL;
      }
      else
      {
        delete aux3->next;
        aux3->next = temp;
      }
    }
  }
}
int main()
{
  list list1;
  int N, M, K, X, j;
  cin >> N;
  list1.list_head = NULL;
  for (j = 0; j < N; j++)
  {
    cin >> K >> X;
    list1.add(K, X);
  }
  cin >> M;
  for ( j = 0; j < M; j++)
  {
    cin >> K;
    list1.remove(K);
  }
  cin >> K;
  cout << list1.size() << " " << list1.get(K) << endl;
}
