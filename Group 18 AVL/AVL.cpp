#include <iostream>
#include <fstream>
using namespace std;

int getMax(int a, int b);
int getHeight(struct AVL* node);
int getBalance(struct AVL* node);
struct AVL* newNode(int value);
struct AVL* insertNode(struct AVL* node, int value);
struct AVL* rebalance(struct AVL* node, int data);
struct AVL* rightRotation(struct AVL* x);
struct AVL* leftRotation(struct AVL* x);
void Level(struct AVL* root, int level);
void print(struct AVL* root);
ofstream output;

struct AVL{
  int data;
  int height;
  AVL* right, *left;
};

int getMax(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

int getHeight(struct AVL* node)
{
    if(node == NULL){
      return 0;
    }
    return node->height;
}

int getBalance(struct AVL* node)
{
    if(node == NULL){
      return 0;
    }
    return (getHeight(node->left) - getHeight(node->right));
}

struct AVL *rightRotation(struct AVL* x)
{
    AVL *y = x->left;
    AVL *z = y->right;

    y->right = x;
    x->left= z;

    x->height = getMax(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = getMax(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

struct AVL *leftRotation(struct AVL *x){

    AVL *z = x->right;
    AVL *y = z->left;

    z->left = x;
    x->right = y;

    x->height = getMax(getHeight(x->left), getHeight(x->right)) + 1;
    z->height = getMax(getHeight(z->left), getHeight(z->right)) + 1;

    return z;
}

struct AVL* newNode(int value){
  AVL* node = new AVL;
  node->data = value;
  node->right = NULL;
  node->left = NULL;
  node->height = 1;
  return node;
}

struct AVL* insertNode(struct AVL* node, int value){
  if(node == NULL){
    return newNode(value);
  }
  else{
    if(value < node->data){
      node->left =insertNode(node->left, value);
    }
    else if(value > node->data){
      node->right = insertNode(node->right, value);
    }
    else{
      return node;
    }
  }

  node = rebalance(node, value);
  return node;
}

struct AVL *rebalance(struct AVL *node, int data) //Balances Tree
{
    node->height = getMax(getHeight(node-> left), getHeight(node->right)) + 1; //Sets height
    int balance = getBalance(node);

    if(balance > 1 && data < node->left->data){
        return rightRotation(node);
    }
    if(balance < -1 && data > node->right->data){
        return leftRotation(node);
    }
    if(balance > 1 && data > node->left->data)
    {
        node->left = leftRotation(node->left);
        return rightRotation(node);
    }
    if(balance < -1 && data < node->right->data)
    {
        node -> right = rightRotation(node->right);
        return leftRotation(node);
    }
    return node;
}

void Level(struct AVL *root, int level)
{
    if(!root){
      return;
    }
    if(level == 1){
      output << root->data << "(" << (root->height) - 1 << ", " << getBalance(root) << ") ";

      cout << root->data << "(" << (root->height) - 1 << ", " << getBalance(root) << ") ";
    }
    else if(level > 1)
    {
        Level(root->left, level - 1);
        Level(root->right, level - 1);
    }
}

void print(struct AVL *root)
{
    int h = getHeight(root);
    int i;
    for (i = 1; i <= h; i++)
    {
        Level(root, i);
        output << '\n' << endl;
        cout << '\n' << endl;
    }

    cout << "You can also find a copy of this in the output file."<< endl;
}

int main()
{
    AVL* root = NULL;
    ifstream input("input.txt");
    output.open("output.txt");
    output << "Numbers in File: " << endl;
    cout << "Numbers in File: " << endl;
    int data;

    while(input >> data){
      root = insertNode(root, data);
      output << data << " ";
      cout << data << " ";
    }

    output << '\n' << '\n' << "AVL Tree (height, balance)" << endl;

    cout << '\n' << '\n' << "AVL Tree (height, balance)" << endl;

    print(root);
    input.close();
    output.close();
}
