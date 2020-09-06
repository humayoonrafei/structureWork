
#include <iostream>
#include <fstream>
using namespace std;

struct Node* readFile();
void Traverse(Node* head);
void SplitMerge(Node* List);
struct Node* Merge(Node* List1, Node* List2);


struct Node{
    string data;
    Node* next;
};

struct Node* readFile()
{
    string name;
    Node* head = new Node;

    ifstream fileRead ("input.txt");

    if(fileRead.is_open()){
        while(fileRead.good())
        {
            fileRead >> name;
            Node *temp = new Node;
            temp->data = name;
            temp->next = NULL;
            if(head == NULL)
            {
              head = temp;  ///if head is empty then makes the temp to be head;
            }
            else
            {
                Node* current = head;
                while(current->next != NULL)
                {
                    current = current->next;
                }
                current->next = temp;  /// add to end
            }
        }
    }
    else
    {
        cout << "file is not open" << endl;
    }

    fileRead.close();
    return head;
}

void SplitMerge(struct Node *head)
{
    struct Node* list1 = head;
    struct Node* list2 = NULL;

    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;

    if (list1!=NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }

        list2 = slow_ptr;
    }

   Node* curr = list1;

   while(curr != NULL)
    {

      if(curr->next == list2)
      {
        curr->next = NULL;
      }
      curr = curr->next;
    }



    cout << "List 1: ";
    Traverse(list1);
    cout << endl;

    cout << "List 2: ";
    Traverse(list2);
    cout << endl;

    cout << "Merged list: ";
    Traverse(Merge(list1, list2));
    cout << endl;
}

struct Node * Merge(struct Node* List1, struct Node* List2){

  struct Node* head = NULL;
  struct Node* current = NULL;

  head = current = List1;

  while(current->next != NULL) {
    current = current->next;
  }

  current->next = List2;

  return head;
}

void Traverse(Node* head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;


    }

    cout << endl;

}

int main()
{
    Node* head = new Node;
    head = readFile();

    SplitMerge(head);


    return 0;
}





/*#include <iostream>
#include <fstream>
using namespace std;

struct Node* readFile();
void Traverse(Node* head);
void SplitMerge(Node* List);
struct Node* Merge(Node* List1, Node* List2);


struct Node{
    string data;
    Node* next;
};


void SplitMerge(struct Node *temp) {

  struct Node *full = NULL;
  struct Node *head1 = NULL;
  struct Node *head2 = NULL;
  struct Node *tail1 = NULL;
  struct Node *tail2 = NULL;
  struct Node *mergelist = NULL;

  int length = 0;
  int mid = 0;

  full = temp;

  while(full -> next != NULL) {
    length ++;
    full = full->next;
  }
  length++;


  tail1 = head1 = full = temp;

  while(mid != (length /2)) {
    full = tail1;
    tail1 = tail1->next;
    mid++;
  }

  tail1 = full;
  full = tail1->next;
  tail1->next = NULL;

  cout << "List 1 : ";
  Traverse(head1);

  tail2 = head2 = full;
  mid++;

  while(mid != length) {
    tail2 = tail2->next;
    mid++;
  }

  tail2->next = NULL;

  cout << "List 2 : ";
  Traverse(head2);

  mergelist = Merge(head1, head2);

  cout << "Merge List : ";
  Traverse(mergelist);

}

struct Node * Merge(struct Node* List1, struct Node* List2){

  struct Node* head = NULL;
  struct Node* current = NULL;

  head = current = List1;

  while(current->next != NULL) {
    current = current->next;
  }

  current->next = List2;

  return head;
}

void Traverse(Node* head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;


    }

    cout << endl;

}

struct Node* readFile()
{
    string name;
    Node* head = new Node;

    ifstream fileRead ("input.txt");

    if(fileRead.is_open()){
        while(fileRead.good())
        {
            fileRead >> name;
            Node *temp = new Node;
            temp->data = name;
            temp->next = NULL;
            if(!head)
            {
              head->next = temp;
            }
            else
            {
                Node* current = head;
                while(current->next)
                {
                    current = current->next;
                }
                current->next = temp;
            }
        }
    }
    else
    {
        cout << "file is not open" << endl;
    }

    fileRead.close();
    return head;
}


int main()
{
    Node* head = new Node;
    head = readFile();

    SplitMerge(head);


    return 0;
}*/



