#include <iostream>
#include <fstream>
using namespace std;

int getMax(int a, int b);
int getHeight(struct AVL* node);
int getBalance(struct AVL* node);
struct AVL* newNode(int value);
struct AVL* rebalance(struct AVL* node, int data);
struct AVL* rightRotation(struct AVL* node);
struct AVL* leftRotation(struct AVL* node);
void Level(struct AVL* root, int level);
void Print(struct AVL* root);

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

int getHeight(AVL* node){
  if(node == NULL){
    return 0;
  }
  return node->height;
}

int getBalance(AVL* node){
  if(node == NULL){
    return 0;
  }
  return (getHeight(node->left) - getHeight(node->right));
}

AVL* newNode(int value){
  AVL* node = new AVL;
  node->data = value;
  node->right = NULL;
  node->left = NULL;
  node->height = 1;
  return node;
}

AVL *rebalance(AVL* node, int data);

AVL* insertNode(AVL* node, int value){
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

  ///rebalance
  node = rebalance(node, value);
  return node;
}

AVL* rightRotation(AVL* node){
  AVL *x, *y, *z;

  y=x->left;
  z=y->right;

  x->left = z;
  y->right = x;

  ///reassigning height and balance of nodes;

  x->height = getMax(getHeight(x->left),
                      getHeight(x->right)) + 1;

  y->height = getMax(getHeight(y->left),
                      getHeight(y->right)) + 1;

  return y;
}

AVL* leftRotation(AVL* node){
  AVL *x, *y, *z;

  y=z->left;
  z=x->right;

  z->left = x;
  x->right = y;

  ///reassigning height and balance of nodes;

  x->height = getMax(getHeight(x->left),
                      getHeight(x->right)) + 1;

  z->height = getMax(getHeight(z->left),
                      getHeight(z->right)) + 1;

  return y;
}

/*node * rebalance(node *node){
    node->height = max(height(node->left), height(node->right)) + 1;
    int balance = getBalance(node);  //node->left - node->right

    do rotations as necessary
      If Left heavy outside :  return rightRotate(node);
      If right heavy outside:  return leftRotate(node);
      If left heavy inside:  left rotation first, right rotation 2nd, return top node
    		node->left =  leftRotate(node->left);
    		return rightRotate(node);
     if right heavy inside: right rotation first, left rotation 2nd, return top node
		node->right = rightRotate(node->right);
        	return leftRotate(node);
     if no rotation, return node
   */

AVL *rebalance(AVL* node, int data) //Balances Tree
{
    node->height = getMax(getHeight(node->left),
                   getHeight(node->right)) + 1;

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

ofstream output;

void Level(AVL *root, int level)
{
    if(!root) {return;}
    if(level == 1){output << root->data << "(" << (root->height) - 1 << ", " << getBalance(root) << ") ";}
    else if(level > 1)
    {
        Level(root->left, level - 1);
        Level(root->right, level - 1);
    }
}

void Print(AVL *root)
{
    int h = getHeight(root);
    int i;
    for (i = 1; i <= h; i++)
    {
        Level(root, i);
        output << '\n' << endl;
    }
}




int main()
{
    AVL *root = NULL;
    ifstream input("file.txt");
    output.open("output.txt");
    output << "Numbers on File: " << endl;
    for(int data; input >> data; root = insertNode(root, data)){output << data << " ";}
    output << '\n' << '\n' << "AVL Tree (height, balance)" << endl;
    Print(root);
    input.close();
    output.close();
}
