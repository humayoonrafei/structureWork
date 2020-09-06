#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct node
{
    char exp;
    node *next;
    node(int val, node *in): exp(val), next(in){}
};

node *stack = NULL;
node *current = NULL;
node *start = NULL;
node *rear = NULL;

void PushItem(char top)
{
    if (stack == NULL)
    {
        stack = new node(top, NULL);
        current = stack;
    }
    else{current = new node(top, current);}
}

void enqueue(char c)
{
    node *temp = new node(c, NULL);
    if (start == NULL && rear == NULL)
    {
        start = rear = temp;
    }
    else
    {
        rear -> next = temp;
        rear = temp;
    }
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

void Postfix(char expression)
{
    PushItem(expression);

    if(current -> next != NULL)
    {
        if(Precedence(current -> exp) <= Precedence(current -> next -> exp))
        {
          if(current -> exp == '('){}
          else if (current -> exp == ')') //If ')' Pop all until '('
          {
            node * temp = current;
            current = current -> next;
            delete(temp);
            while (current -> exp != '(')
            {
              node * temp = current;
              enqueue(temp -> exp);
              current = temp -> next;
              delete(temp);
            }

            if(current -> next != NULL)
            {
              node * temp = current;
              current = current -> next;
              delete(temp);
            }
            else
            {
              delete(current);
              stack = NULL;
            }
          }
          else
          {
            while(current -> next != NULL)
            {
              if(Precedence(current -> next -> exp) >= Precedence(current -> exp))
              {
                node * temp = current -> next;
                enqueue(temp -> exp);
                current -> next = temp -> next;
                delete(temp);
              }
              else{break;}
            }
          }
        }
    }
}

void Traverse()
{
    while(start!= NULL)
    {
        start=start->next;
        cout << start->exp;
    }
}

int main()
{
    ifstream input;
    input.open("input.txt");

    char expression;

    while (input >> expression)
    {
        if (isdigit(expression))
        {
            enqueue(expression);
        }
        else
            {
                Postfix(expression);
            }
    }

    while (current != NULL)
    {
        node * temp = current;
        enqueue(temp -> exp);
        current = temp -> next;
        delete(temp);
    }

    Traverse();
}







