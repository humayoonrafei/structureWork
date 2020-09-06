
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct ExpTree{
  char value;
  ExpTree* left, *right;
};

bool isOperator(char c){

  if (c == '+' || c == '-' ||c == '*' || c == '/' ||c == '^')
    return true;

  return false;
}

// Utility function to do inorder traversal

void InOrderDisplay(ExpTree* ExValue){
  if(ExValue){
    if (isOperator(ExValue->value))
      cout << "(";
      InOrderDisplay(ExValue->left);
      cout<< ExValue->value;
      InOrderDisplay(ExValue->right);

      if (isOperator(ExValue->value))
        cout << ")";
  }
}

ExpTree* newNode(int v){
  ExpTree* temp = new ExpTree;
  temp->value = v;
  temp->left = temp->right = NULL;
  return temp;
};

ExpTree* constructTree(char postfix[]){

  stack<ExpTree*> stk;

  ExpTree *t, *t1, *t2;

  for (int i=0; i<strlen(postfix); i++){
    if (!isOperator(postfix[i]))
    {
      t = newNode(postfix[i]);
      stk.push(t);
    }

    else
    {
      t = newNode(postfix[i]);
      t1 = stk.top(); // Store top
      stk.pop(); // Remove top
      t2 = stk.top();
      stk.pop();

      t->right = t1;
      t->left = t2;

      stk.push(t);
    }
  }

  t = stk.top();
  stk.pop();

  return t;
}

int main(){
  string s;

  cout << "Enter Postfix Expression: ";
  cin >> s;

  int n = s.length();

  char postfix[n+1];

  strcpy(postfix, s.c_str());



  ExpTree* r = constructTree(postfix);
  cout<<"\ninfix expression is: ";

  InOrderDisplay(r);

  return 0;
}
