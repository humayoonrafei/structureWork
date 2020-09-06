#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void Push(int item, node* &top)
{
  node* newItem = new node;

  newItem->data = item;
  newItem->next = top;
  top = newItem;

}

int pop(node* &top)
{
    int value;
    {
        node *curr = top;
        top = top->next;
        value = curr->data;
        delete(curr);
    }
    return value;
}

void HexNumBiNUM(node* &top)
{
    cout << "Please enter a number: ";
    int binaryNumber, hex;
    char hexNumbers[] = "0123456789ABCDEF";
    cin >> binaryNumber;
    hex = binaryNumber;

    for(; hex > 0; hex = hex/16)
    {
      Push((hex % 16), top);
    }

    cout << "Hex Number is: ";

    while (true)
    {
        if (top != NULL)
        {
            cout << hexNumbers[pop(top)];

        }
        else
            {
                break;

            }

    }

    /*
    node* cur = top;
    while (top != NULL)
    {

        cout << hexNumbers[pop(top)];

        cur = cur->next;

    }
    */
    cout << endl;

    cout << "Binary Number is: ";

    for(; binaryNumber > 0; binaryNumber = binaryNumber/2)
    {
        Push((binaryNumber % 2), top);
        cout << pop(top);

    }
}

int main()
{
    node* top = NULL;
    HexNumBiNUM(top);
}
