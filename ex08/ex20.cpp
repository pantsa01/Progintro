#include <iostream>
using namespace std;

class list
{
  class node
  {
  public:
    int info;
    node *next;
    node (int num)
    {
      info = num;
    }
  };
  typedef node* nodeptr;
  nodeptr head;

public:
  list ();
  bool empty ();
  int size ();
  void add (int k, int x);
  int get (int k);
  void remove (int k);
  int searchMF (int x);
};

list::list ()
{
  head = nullptr;
}

bool list::empty ()
{
  if (head == nullptr)
    return true;
  else
    return false;
}

int list::size()
{
  int count = 0;
  for (nodeptr i = head; i != nullptr; i = i->next)
    count++;
  return count;
}


void list::add (int k, int x)
{
  nodeptr newnod = new node(x);
  nodeptr prevnod;

  if (k == 1)
  {
    newnod->next = head;
    head = newnod;
  }
  else
  {
    prevnod = head;
    for (int i = 0; i < k-2; i++)
      prevnod = prevnod->next;
    newnod->next = prevnod->next;
    prevnod->next = newnod;
  }
}

int list::get (int k)
{
  nodeptr nod = head;
  for (int i = 0; i < k-1; i++)
    nod = nod->next;
  return nod->info;
}

void list::remove (int k)
{
  nodeptr prev, cur;
  if (k == 1)
  {
    cur = head;
    head = cur->next;
  }
  else
  {
    prev = head;
    for (int i = 0; i < k-2; i++)
      prev = prev->next;
    cur = prev->next;
    prev->next = cur->next;
  }
  delete cur;
}

int list::searchMF (int x)
{
  int count = 1;
  nodeptr pos;
  for (pos = head; pos != nullptr and pos->info != x; pos = pos->next)
    count ++;
  if (pos != nullptr)
  {
    remove (count);
    add (1, x);
    return count;
  }
  else
    return 0;
}

int main()
{
  list mylist;
  int n, k, x, m;
  int count = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> k >> x;
    mylist.add (k, x);
  }
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> x;
    count += mylist.searchMF(x);
  }
    cout << count << endl;
}
