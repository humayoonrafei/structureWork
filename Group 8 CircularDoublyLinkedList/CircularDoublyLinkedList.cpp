#include <iostream>
#include <fstream>

using namespace std;

void Insert(string n);
void Traverse();
void Delete(string name);
void DisplayDataBase();

struct node
{
    string name;
    node * next;
    node * prev;

    node(string data, node *next, node *prev):
    name(data), next(next), prev(prev){};
};

node * head = NULL;
node * rear = NULL;
node * current = NULL;

void Insert(string n)
{
  if(!head){head = rear = current = new node(n, NULL, NULL);}
  else
  {
    node * temp = new node(n, NULL, current);
    current->next = temp;
    rear = temp;
    current = temp;
    rear -> next = head;
    head -> prev = rear;
  }
}

void Delete(string name)
{

  node * temp = head;
  while(temp)
  {
    if (temp -> name == name)
    {
      if (temp == head)
      {
        head = head -> next;
      }
      else if (temp == rear)
      {
        rear = rear -> prev;
      }

      current = temp -> next;
      temp -> prev -> next = current;
      current -> prev = temp -> prev;

      delete(temp);

      cout << "Name deleted." << endl << endl;

      Traverse();
      break;
    }
    else
    {
      if (temp -> next != head)
      {
        temp = temp -> next;
      }
      else
      {
        cout << "Name not found.";
        break;
      }
    }
  }
}

void Traverse()
{
    node * current = head;
    if(head)
    do{
      cout << current->name << endl;
      current = current->next;
    }while(current!= head);
}

void DisplayDataBase()
{
  ifstream input;
    input.open("input.txt");
    string n;
    while(input >> n)
    {
      Insert(n);
    }
    Traverse();
    string name;
    do{
        cout << "Enter name to delete: ";
        cin >> name;
        Delete(name);
        cout << endl;
        cout << "Enter any key except 'x' to continue program: ";
        cin >> name;
        cout << endl;
    }
    while(name != "x");
}

int main(){DisplayDataBase(); return 0;}
