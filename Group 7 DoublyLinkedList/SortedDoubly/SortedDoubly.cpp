#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void AddAndSort(struct node* &head, struct node* &tail, string name);
void DeleteNode(struct node* &head, string name);
void TraversePrintHead(struct node* head);
void TraversePrintTail(struct node* tail);
void DisplayData();

struct node{
  string data;
  node* next;
  node* prev;
};

void AddAndSort(node* &head, node* &tail, string name)
{
  node* nn = new node;
  nn->data = name;
  nn->next = NULL;  /// we aren't adding to nn node. we are adding to the head and tail

  if(head == NULL)
  {
    head = nn;  /// head is 1st node
    tail = nn;  /// tail is last node
    nn->prev = NULL;
  }
  else if(nn->data < head->data)
  {
    /// if it is less than first node then add to end of first node.

    nn->prev = NULL;
    head->prev = nn;
    nn->next = head;
    head = nn;
  }
  else if(nn->data > tail->data)
  {
    ///if it is greater than last node add to the next of tail node
    tail->next = nn;
    nn->prev = tail;
    tail = nn;
  }
  else{
    /// looking one node head
    node* temp = head->next;
    while(nn->data > temp->data)
    {
      temp = temp->next;
    }
    /// insert new node before node that is less then existing node
    /// we only have temp node that can access back its previous node.
    temp->prev->next = nn;
    nn->prev = temp->prev;
    temp->prev = nn;
    nn->next = temp;
  }
}

void DeleteNode(node* &head, node* &tail, string name)
{
  node* temp = head;
  if(head->data == name)
  {
      head = head->next;
      head->prev = NULL;
      delete temp;
  }
  else if(tail->data == name)
  {
      temp = tail;
      tail = tail->prev;
      tail->next = NULL;
      delete temp;
  }

  else
  {
      while(temp != NULL && temp->data != name)
      {
          temp = temp->next;
      }

       if(temp!=NULL)
       {
           temp->next->prev=temp->prev;
           temp->prev->next=temp->next;
           delete temp;
       }
  }


}

void TraversePrintHead(node* head)
{
  node* cur = head;
  while(cur != NULL)
  {
    cout << cur->data << endl;
    cur = cur->next;
  }
}

void TraversePrintTail(node* tail)
{
  node* cur = tail;
  while(cur != NULL)
  {
    cout << cur->data << endl;
    cur = cur->prev;
  }
}

void DisplayData()
{
  node* head = NULL;
  node* tail = NULL;

  ifstream infile("input.txt");
  string name;
  string line;

  infile >> line;
  while(infile.good())
  {
    if(line == "delete")
    {
        infile >> name;
        DeleteNode(head, tail, name);
    }
    else{
        AddAndSort(head, tail, line);
    }
    infile >> line;
  }
  cout << "Printing Sorted List in Ascending Order...\n";
  TraversePrintHead(head);
  cout << "\nPrinting Sorted List in Descending Order...\n";
  TraversePrintTail(tail);

  infile.close();
}

int main()
{
  DisplayData();
  return 0;
}
