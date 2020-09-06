#include<iostream>
#include<string.h>
#include<string>
#include<fstream>
using namespace std;

struct Node{
  char* name;
  struct Node* next;
};
struct BinaryTree
{
    char* name;
    struct Node* next;
    struct BinaryTree* left;
    struct BinaryTree* right;
};

BinaryTree* InsertName(BinaryTree* root, char* name)
{
    if(!root){
      BinaryTree* root = new BinaryTree;
      root->name = name;
      root->right = NULL;
      root->left = NULL;
      root->next = NULL;
      return root;
    }

    else if(strcmp(name, root->name) == 0)
    {
        if(!root->next){
          root->next = new Node;
          root->next->name = name;
          root->next = NULL;
        }
        else
        {
            Node* now;
            now->next = new Node;
            now->next->name = name;
            //now->next = NULL;

            for(now = root->next; now->next; now = now->next){
              cout << now->next->name << endl;
            }

        }
    }

    else if(strcmp(name, root->name) < 0){
      root->right = InsertName(root->right, name);
    }
    else if(strcmp(name, root->name) > 0){
      root->left = InsertName(root->left, name);
    }
  return root;
}

bool SearchName(BinaryTree* root, char* name){
  if(!root){
    return false;
  }
  else if(strcmp(root->name, name) == 0){
    cout << root->name << " ";
    if(root->next){
      int i = 2;
      for(Node *curr = root->next; curr->next; curr = curr->next){
        i++;
      }
      cout << '\n' << i << " iterations of " << root->name << " "<< endl;
    }
    else{
      cout << '\n' << "Only 1 iteration of " << root->name << " "<< endl;
    }

    return true;
  }
  else if(strcmp(name, root->name) < 0){
    cout << root->name << " ";
    return SearchName(root->right, name);
  }
  else{
    cout << root->name << " ";
    return SearchName(root->left, name);
  }
}

int main()
{
    BinaryTree* root = NULL;
    ifstream input("input.txt");
    char n[30];
    while(input>>n){
      root = InsertName(root, n);
    }
    char search[30];
    cout << "Enter name to be searched" << endl;
    cin >> search;
    cout << endl;

    if(SearchName(root, search) == true){
      cout << "Name Found" << endl;
    }
    else{
      cout << "Name Not Found" << endl;
    }
}
