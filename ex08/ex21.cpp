#include <iostream>
#include <algorithm>
using namespace std;

class bstree
{
  class node
  {
    public:
      int info;
      node *left, *right;
      node (int x) {info = x;}
  };
  node *root;
  int height (node *t);
  void insert (int x, node *t);
  int search (int x, node *t);
  int min (node *t);
  int max (node *t);
  void inorder (node *t);
  void preorder (node *t);
  void postorder (node *t);

public:
  bstree() {root = nullptr;}
  int height() {return height (root);}
  void insert (int x) {insert (x, root);}
  int search (int x) {return search (x, root);}
  int min() {return min (root);}
  int max() {return max (root);}
  void inorder() {inorder (root); cout << "end\n";}
  void preorder() {preorder (root); cout << "end\n";}
  void postorder() {postorder (root); cout << "end\n";}
};

int bstree::height (node *t)
{
  if (t == nullptr)
    return 0;
  return std::max(height(t->left), height(t->right)) +1;
}

void bstree::insert (int x, node *t)
{
  if (root == nullptr)
    root = new node(x);
  else if (x > t->info)
    if (t->right == nullptr) t->right = new node(x);
    else insert(x, t->right);
  else
    if (t->left == nullptr) t->left = new node(x);
    else insert(x, t->left);
}
int level;
int bstree::search (int x, node *t)
{
  if (t == root) level = 0;
  level++;
  if (t == nullptr) level = 0;
  else if (x > t->info) search(x, t->right);
  else if (x < t->info) search(x, t->left);
  return level;
}

int bstree::max (node *t)
{
  if (t->right == nullptr)
    return t->info;
  else max(t->right);
}

int bstree::min (node *t)
{
  if (t->left == nullptr)
    return t->info;
  else min(t->left);
}

void bstree::inorder (node *t)
{
  if (t == nullptr) return;
  inorder(t->left);
  cout << t->info << ' ';
  inorder(t->right);
}

void bstree::preorder (node *t)
{
  if (t == nullptr) return;
  cout << t->info << ' ';
  preorder (t->left);
  preorder (t->right);
}

void bstree::postorder (node *t)
{
  if (t == nullptr) return;
  postorder (t->left);
  postorder (t->right);
  cout << t->info << ' ';
}

int main()
{
  bstree mytree;
  int n, m, a;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    mytree.insert(a);
  }

  cin >> m;
  int srch[m];
  for (int i = 0; i < m; i++)
  {
    cin >> a;
    srch[i] = mytree.search(a);
  }

  cout << mytree.height() << endl
    << mytree.min() << ' ' << mytree.max() << endl;

  for(int i = 0; i < m-1; i++)
    cout << srch[i] << ' ';
  cout << srch[m-1] << endl;

  mytree.inorder();
  mytree.preorder();
  mytree.postorder();
}
