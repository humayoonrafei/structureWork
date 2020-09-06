#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

/************************/
///prototypes Funcs

void push(char c);
char pop(char c);
void enqueue(char c);
char dequeue(char c);
int Precedence (char c);
void InfixToPostfix(char c[]);
void TraverseAtQueue();
void TraverseAtChar(char c[]);
void Display(char s[]);

struct node{
  char exp;
  node* next;
};

node*top=NULL, *front=NULL, *rear=NULL;
///global pointers cause we'r not using them as argument in the funcs.

void push(char c)
{
  node* newNode = new node;
  newNode->exp = c;
  newNode->next = top;
  top = newNode;
}

char pop(char c)
{
  char v;
  node* temp;
  if(top)
  {
    temp = top;
    top = top->next;
    v = temp->exp;
    delete temp;
  }

  return v;
}

void enqueue(char c)
{
  node* newNode = new node;
  newNode->exp = c;
  newNode->next = NULL;

  if(rear)
  {
    rear->next = newNode;
    rear = newNode;
  }

  else
  {
    front = rear = newNode;
  }
}

char dequeue(char c)
{
  char v;  /// for return.
  if(front)
  {
    node* temp;
    temp = front;
    front = front->next;
    v = temp->exp;
    delete temp;

    if(!front)
    {
      rear = NULL;
    }
  }

  return v;
}

int Precedence (char c)
{

    if(c == '*' || c == '/')
    {
        return 2;
    }
    else if(c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void InfixToPostfix(char c[])
{
    //int a = c.length(); if string.
    for(int i=0; i<strlen(c);i++)
    {
        if(c[i] >= '0' && c[i] <= '9')
        {
            cout << c[i];  /// print or enqou
            enqueue(c[i]);
        }
        else if(c[i] == '(')
        {
            push(c[i]);  ///push to stk;
        }
        else if(c[i] == ')') /// if c[i] == ) and stk not = null and stk reach to (, pop.
        {
            while(top != NULL && top->exp != '(')
            {
                char a = pop(c[i]); /// pop and enqueue.
                cout << a;
                enqueue(a);
            }

            if(top->exp == '(')
            {
              pop(c[i]); ///pop but not enqou or print.
            }

        }
        else
        {
            while(top != NULL && Precedence(c[i]) <= Precedence(top->exp))
            {
                char a = pop(c[i]); /// enqou or print
                cout << a;
                enqueue(a);

            }
            push(c[i]); /// else push to stk.

        }
    }

    while(top != NULL)  /// traverse inside stk to print all value.
    {

      char a = pop(top->exp);
      cout << a;
      enqueue(a);
    }
}

void TraverseAtQueue()
{
  cout << "Queue's output: ";
  while(front != NULL)
  {
    cout << dequeue(front->exp); /// FIFO
  }
}

void TraverseAtChar(char c[])
{
  cout << "Infix Value: ";
  for(int i=0; i<strlen(c); i++)
  {
    cout << c[i];  /// print given value from in file.
  }

  cout << endl;
}

void Display(char s[])
{
    int i =0;
    fstream infile("input.txt");

    if(!infile.is_open())
    {
        cout << "Try again, File Not Found..." << endl;
    }

    else
    {
       while(infile.good())
       {
           infile>>s[i];
            i++;

       }

       TraverseAtChar(s);
       cout << "PostFix Value: ";
       InfixToPostfix(s);
       cout << endl;
       TraverseAtQueue();
       cout << endl;
    }
}


int main()
{
    char s[20];
    Display(s);
    return 0;
}
