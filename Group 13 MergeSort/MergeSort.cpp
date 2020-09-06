#include <iostream>
using namespace std;

// Link list node
struct node
{
  int value;
  node* next;
};

// Merging two sorted lists.
node* merge(node* a, node* b)
{
  node* temp = NULL;

  // Base Cases
  if (a == NULL)
    return (b);
  else if (b == NULL)
    return (a);

  // recursively merging two lists
  if (a->value <= b->value) {
    temp = a;
    temp->next = merge(a->next, b);
  }
  else {
    temp = b;
    temp->next = merge(a, b->next);
  }
  return temp;
}

// Splitting two into halves.
// If the size of the list is odd, then extra element goes in the first list.
void split(node* head, node*& a, node*& b)
{
  node* ptr1;
  node* ptr2;
  ptr2 = head;
  ptr1 = head->next;

  // ptr1 is incrmented twice and ptr2 is icremented once.
  while (ptr1 != NULL) {
    ptr1 = ptr1->next;
    if (ptr1 != NULL) {
      ptr2 = ptr2->next;
      ptr1 = ptr1->next;
    }
  }

  // ptr2 is at the midpoint.
  a = head;
  b = ptr2->next;
  ptr2->next = NULL;
}

// Merge Sort
void mergeSort(node*& head)
{
  node* curr = head;
  node* ptr1;
  node* ptr2;

  // Base Case
  if ((curr == NULL) || (curr->next == NULL)) {
    return ;
  }

  // Splitting list
  split(curr, ptr1, ptr2);

  // Recursively sorting two lists.
  mergeSort(ptr1);
  mergeSort(ptr2);

  // Sorted List.
  head = merge(ptr1, ptr2);
}


// Printing List.
void traverse(node* head)
{
  node* curr = head;
  while (curr != NULL) {
    cout << curr->value << " ";
    curr = curr->next;
  }
}

// Push function for inserting nodes in the list.
void push(node*& head, int value)
{
  node* curr = new node();
  curr->value = value;
  curr->next = head;
  head = curr;
}

void display()
{
      // Empty list
  node* Mylist = NULL;

  // adding to the List: 10->4->15->1->2->12->54
  //*By pushing values into stack and adding them to our list.

  push(Mylist, 54);
  push(Mylist, 12);
  push(Mylist, 2);
  push(Mylist, 1);
  push(Mylist, 15);
  push(Mylist, 4);
  push(Mylist, 10);

  cout << endl << "Unsorted Linked List: ";
  traverse(Mylist);
  cout << "\n\n";

  mergeSort(Mylist);
  cout << "Sorted Linked List:   ";
  traverse(Mylist);
  cout << endl;
}

// Driver Program.
int main()
{
    display();
    return 0;
}
