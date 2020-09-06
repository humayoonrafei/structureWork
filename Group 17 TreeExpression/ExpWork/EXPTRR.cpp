#include <iostream>
#include <string.h>
using namespace std;

struct ExpTree{
  char data;
  ExpTree *right, *left;
};

struct StackNode{
  struct ExpTree* info;
  StackNode *next;
};

void push(ExpTree* root, StackNode* &top){
  StackNode* node = new StackNode;
  node->info = root;
  node->next = top;
  top = node;
}

ExpTree* pop(StackNode* &top){
  StackNode* temp;
  ExpTree* leaf;
  if(top){
    temp = top;
    top = top->next;
    leaf = temp->info;
    delete temp;
    return leaf;
  }
  else{
    cout << "Stock is Empty" << endl;
    return NULL;
  }

}

bool isOperator(char* c){
  if(*c == '+' || *c == '-' || *c == '/' ||*c == '*' || *c == '^'){
    return true;
  }
  return false;
}

void InOrderDisplay(ExpTree* leaf){
  if(leaf){
    if (isOperator(&leaf->data))
      cout << "(";
      InOrderDisplay(leaf->left);
      cout<< leaf->data;
      InOrderDisplay(leaf->right);

      if (isOperator(&leaf->data))
        cout << ")";
  }
}

ExpTree* newNode(int v){
  ExpTree *nn = new ExpTree;
  nn->data = v;
  nn->right = nn->left = NULL;

  return nn;
}

ExpTree* constructTree(char* postfix){
  StackNode *stk;
  ExpTree* leaf, *rightLeaf, *leftLeaf;

  for(int i=0; i<strlen(postfix); i++){
    if(!isOperator(&postfix[i])){
      leaf = newNode(postfix[i]);
      push(leaf,stk);
    }

    else{
      leaf = newNode(postfix[i]);

      rightLeaf = pop(stk);
      leftLeaf = pop(stk);

      leaf->right = rightLeaf;
      leaf->left = leftLeaf;

      push(leaf, stk);
    }
  }

  leaf = pop(stk);
  return leaf;
}

int main(){
  string userInput;

  cout << "Enter Postfix Expression: ";
  cin >> userInput;

  int n = userInput.length();

  //char* postfix;
  char postfix[n+1];
  ///convert str to char
  strcpy(postfix, userInput.c_str());

  ExpTree* Tree = constructTree(postfix);
  cout<<"\nInfix Expression is: ";
  InOrderDisplay(Tree);
  return 0;
}
