#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct node
{
    char exp;
    node *next;
};

void push(char item, node* &top)
{
    node* newItem = new node;

    newItem->exp = item;
    newItem->next = top;
    top = newItem;
}

void enqueue(int item, node *&front, node*&rear){
    struct node *newNode=new node;

    newNode->exp=item;
    newNode->next=NULL;

    if (rear){
        rear ->next=newNode;
        rear =newNode;
   }
   else
        front = rear =newNode;
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
    else{return -1;}
}

void Postfix(char expression)
{
    struct node * front, * rear, *top;
    front = rear = top = NULL;

    push(expression, top);

    if(top -> next != NULL)
    {
        if(Precedence(top -> exp) <= Precedence(top -> next -> exp))
        {
          if(top -> exp == '('){}
          else if (top -> exp == ')')
          {
            node * temp = top;
            top = top -> next;
            delete(temp);
            while (top -> exp != '(')
            {
              node * temp = top;
              enqueue(temp -> exp, front, rear);
              top = temp -> next;
              //delete(temp);
            }

            if(top -> next != NULL)
            {
              node * temp = top;
              top = top -> next;
              //delete(temp);
            }
            //else
            //{
              //delete(top);
              //top = NULL;
            //}
          }
          else //If precedence is lower than previous, pop all operators greater than or equal to
          {
            while(top -> next != NULL)
            {
              if(Precedence(top -> next -> exp) >= Precedence(top -> exp))
              {
                node * temp = top -> next;
                enqueue(temp -> exp, front, rear);
                top -> next = temp -> next;
                //delete(temp);
              }
              else
              {
                break;
              }
            }
          }
        }
    }
}

void Traverse(node* start)
{
    while(start != NULL)
    {
        cout << start->exp;
        start = start->next;
    }
}

int main()
{
    struct node * front, * rear, *top;
    front = rear = top = NULL;

    ifstream infile("input.txt");

    char expression;

    while(infile >> expression)
    {
      if (isdigit(expression))
      {
        enqueue(expression, front, rear);
      }
      else
      {
        Postfix(expression);
      }
    }

    while (top != NULL)
    {
        node * temp = top;
        enqueue(temp -> exp, front, rear);
        top = temp -> next;
        //delete(temp);
    }

    Traverse(front);
}


