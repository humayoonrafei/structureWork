#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void InsertName(struct node* &head, string name);
void DeleteName(struct node* &head, string name);
void Traverse(struct node* head);
void DisplayDataBase();

struct node{
  string data;
  node* next;
  node* prev;
};

void InsertName(node* &head, string name)
{
  node* nn = new node;
  nn->data = name;

  if(!head)
  {
    nn->next = nn;
    nn->prev = nn;
    head = nn;
  }

  else
  {
    nn->next = head;
    nn->prev = head->prev;
    head->prev = nn;
    nn->prev->next = nn;
    head = nn;
  }
}

void DeleteName(node* &head, string name)
{
  node* temp = head;
  while(temp)
  {
    if(name == temp->data)
    {
      if(temp == head)  /// if it is on the head
      {
        head = head->next; /// move the head forward
      }
      else if(temp == head->prev) /// if it is on the tail to previous of head
      {
        temp = temp->prev; ///  move the head backward
      }

      node* current = temp -> next;  /// looking one node after head
      temp -> prev -> next = current;
      current -> prev = temp -> prev;
      delete(temp);

      cout << "Name deleted: " << endl << endl;

      Traverse(head);
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

void Traverse(node* head)
{
  if(head)
  {
    node* cur = head;
    do{
        cout << cur->data << endl;
        cur = cur->next;
    }while(cur != head);
  }
}

void DisplayDataBase()
{
  node* head = NULL;
  ifstream infile("input.txt");
  string name;
  while(infile.good())
  {
    infile >> name;
    InsertName(head, name);
  }

  Traverse(head);

  string userInput;

  do{

    cout << "\nEnter name to delete: ";
    cin >> userInput;
    DeleteName(head, userInput);
    cout << endl;
    cout << "Enter any key except 'x' to continue program: ";
    cin >> userInput;
    cout << endl;

  }while(userInput != "x");
  cout << "\nGood bye!";

  infile.close();
}

int main()
{
  DisplayDataBase();
  return 0;
}
