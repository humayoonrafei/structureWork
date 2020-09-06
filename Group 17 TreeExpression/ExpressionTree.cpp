
#include <iostream>
#include <string.h>

using namespace std;

struct ExpTree{
  char value;
  ExpTree *left;
  ExpTree *right;
};

struct stk {
  struct ExpTree* item;
  stk* next;
};

void pop(stk* &top){
  struct stk* temp;
  if(top){
      temp=top;
      top=top->next;
      delete temp;
  }
}

void push(ExpTree* item,stk* &top){
  struct stk *newNode=new stk;
  newNode->item=item;
  newNode->next=top;
  top=newNode;
}

struct ExpTree* top(stk* &top){
  if(top)
    return top->item;
  else
    cout << "Stock is Empty" << endl;
    return NULL;
}

int strlen(char* str)
{
  int length = 0;
  while (*str != '\0'){
    length++;
    str++;
  }
  return length;
}

bool isOperator(char c){
  if (c == '+' || c == '-' ||c == '*' || c == '/' ||c == '^')
    return true;
return false;
}

void InOrderDisplay(ExpTree* ExValue){
  if(ExValue){
    if (isOperator(ExValue->value))
      cout << "(";
      InOrderDisplay( ExValue->left);
      cout<< ExValue->value;
      InOrderDisplay(ExValue->right);

      if (isOperator(ExValue->value))
        cout << ")";
  }
}

struct ExpTree* newNode(int v){
  ExpTree *temp = new ExpTree;
  temp->left = temp->right = NULL;
  temp->value = v;
  return temp;
};

struct ExpTree* constructTree(char postfix[]){
  stk* s = nullptr;
  ExpTree *root, *rightChild, *leftChild;
  for (int i=0; i<strlen(postfix); i++){

    if (!isOperator(postfix[i])){
      root = newNode(postfix[i]);
      push(root,s);
    }
    else{
      root = newNode(postfix[i]);
      rightChild = top(s);
      pop(s);
      leftChild = top(s);
      pop(s);
      root->right = rightChild;
      root->left = leftChild;
      push(root,s);
    }
  }

  root = top(s);
  pop(s);
  return root;
}

int main(){
  string userInput;

  cout << "Enter Postfix Expression: ";
  cin >> userInput;

  int n = userInput.length();

  char* postfix;
  //char postfix[n+1];
  ///convert str to char
  strcpy(postfix, userInput.c_str());

  ExpTree* Tree = constructTree(postfix);
  cout<<"\nInfix Expression is: ";
  InOrderDisplay(Tree);
  return 0;
}
