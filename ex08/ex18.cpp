#include <iostream>
#include <string>
using namespace std;
struct node{
  char data;
  node *next;
};

class queue{
  public :
    bool empty();
    void enqueue(char x);
    void dequeue();
    int peek();
    node *list_head;
    node *list_tail;
};

void queue::enqueue(char x)
{
  node *neos;
  neos = new(nothrow) node;
  neos->data=x;
  if (list_tail!=NULL)
    list_tail->next=neos;
  neos->next = NULL;
  list_tail=neos;
  if (list_head==NULL)
    list_head=list_tail;
}

void queue::dequeue()
{
  if (list_head!=NULL)
  {
    node *temp;
    temp=list_head->next;
    delete list_head;
    list_head=temp;}
}

bool queue::empty()
{
  if (list_head==NULL)
    return true;
  else
    return false;
}
int queue::peek()
{
  if(list_head!=NULL)
    return list_head->data;
  else
    return 0;
}

bool ifpositive (char ch)
{
  if (ch>='0' and ch<='9')
    return true;
  else
    return false;
}

bool check(char a[], char b[], int l, int k)
{
  int i;
  bool equal=true;
  if (l==k and l!=0 and k!=0)
  {
    for(i=0; i < l; i++)
    {
      if (a[i]!=b[i])
      {
        equal=false;
        break;
      }
    }
  }
  else
    equal=false;
  return equal;
}

int main()
{
  queue queue1;
  char c;
  char positive[10000000];
  char negative[10000000];
  int count1=0;
  int count2=0;
  node *aux;
  (queue1.list_head)=NULL;
  while((c=getchar())!='\n')
    queue1.enqueue(c);
  aux=queue1.list_head;
  while(aux!=NULL)
  {
    if(ifpositive(aux->data)){
      positive[count1]=(aux->data);
      count1++;
    }
    else if((aux->data)=='-')
    {
      aux=aux->next;
      while(aux!=NULL and (aux->data)!=' ')
      {
        negative[count2]=(aux->data);
        count2++;
        aux=(aux->next);
      }
    }
    if (aux!=NULL)
      aux=aux->next;
  }
  if ((check(positive, negative, count1, count2)))
    cout << "yes" << endl;
  else
    cout << "no" << endl;
}
