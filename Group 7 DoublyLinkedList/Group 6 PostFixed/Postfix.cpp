#include <iostream>
#include <fstream>
using namespace std;

struct node;
void PushItem(int item, node* &top);
void PopItem(node* &top);
void Traverse(node* top);
void Calculate();

struct node
{
    int data;
    node *next;
};

void PushItem(int item, node* &top)
{
    node* newItem = new node;

    newItem->data = item;
    newItem->next = top;
    top = newItem;
}

void PopItem(node* &top)
{
    node *temp = new node;
    temp = top;
    top = top -> next;
    delete(temp);
}

void Traverse(node* top)
{
    while(top != NULL)
    {
        cout << top->data;
        //top = top->next; ///either way
        PopItem(top);
    }
}

void Calculate()
{
      node* current = NULL;

    ifstream input;
    input.open("input.txt");

    char expression;
    int n, n1, n2, n3;
    while(input >> expression)
    {
        if(isdigit(expression))
        {
            int num = expression - '0';
            PushItem(num, current);
        }
        else
        {
            n1 = current->next->data; /// grabs the second item.
            n2 = current -> data; /// grabs the first item.

            PopItem(current);
            PopItem(current);

            switch (expression)
            {
                case '+':
                  n3 = n1+n2;
                    break;
                case '-':
                  n3 = n1-n2;
                    break;
                case '*':
                  n3 = n1*n2;
                    break;
                case '/':
                  n3 = n1/n2;
                  break;
                default:
                  cout << "Invalid Operand" << endl;

            }

          PushItem(n3, current);
        }
    }
    cout << "Result: ";
    Traverse(current);
}

int main(){Calculate(); return 0;}





