#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Node
{
  string data;
  struct Node *next;
};


struct Node * ReadFile() {

  struct Node *head = NULL;
  struct Node *temp = NULL;
  struct Node *tail = NULL;

  string line;

  ifstream file ("input.txt");

  if (file.is_open())
  {
    while ( getline (file,line) )
    {
      if(head != NULL) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = line;
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
      }
      else {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = line;
        temp->next = NULL;
        head = temp;
        tail = temp;
      }
    }
    file.close();
  }
  else cout << "Failed to open the file.";

  return head;
}

void Traverse(struct Node *head) {

  struct Node *tail = NULL;

  tail = head;

  while(tail->next != NULL) {
    cout << tail->data << " ";
    tail = tail->next;
  }
  cout << tail->data << endl;
}


struct Node * Merge(struct Node *head1, struct Node *head2){

  struct Node *temp = NULL;
  struct Node *tail = NULL;

  temp = tail = head1;

  while(tail->next != NULL) {
    tail = tail->next;
  }

  tail->next = head2;

  return temp;
}

void SplitMerge(struct Node *temp) {

  struct Node *tail = NULL;
  struct Node *head1 = NULL;
  struct Node *head2 = NULL;
  struct Node *tail1 = NULL;
  struct Node *tail2 = NULL;
  struct Node *mergelist = NULL;

  int length = 0;
  int i = 0;

  tail = temp;

  while(tail -> next != NULL) {
    length ++;
    tail = tail->next;
  }
  length ++;

  tail1 = head1 = tail = temp;

  while(i != length / 2) {
    tail = tail1;
    tail1 = tail1->next;
    i ++;
  }

  tail1 = tail;
  tail = tail1->next;
  tail1->next = NULL;

  cout << "List 1 : ";
  Traverse(head1);

  tail2 = head2 = tail;
  i++;

  while(i != length) {
    tail2 = tail2->next;
    i++;
  }

  tail2->next = NULL;

  cout << "List 2 : ";
  Traverse(head2);

  mergelist = Merge(head1, head2);

  cout << "Merge List : ";
  Traverse(mergelist);

}

int main() {

  struct Node *head = NULL;

  head = ReadFile();

  SplitMerge(head);

}
