#include <iostream>
#include <fstream>
using namespace std;

struct node{
    string data;
    node *next;
};

node* readFile();
void splitMerge(node* list);
void traverse(node* list);
node* merge(node* alist, node* blist);

int main()
{
    node* startingList = readFile();
    cout<<"The starting list is: ";
    traverse(startingList);
    cout << endl;
    splitMerge(startingList);

    return 0;
}

node* readFile()
{
    string name;
    node* head = NULL;

    ifstream fileRead ("file.txt");

    if(fileRead.is_open()){
        while(!fileRead.eof())
        {
            fileRead >> name;
            node *nnode = new node;
            nnode->data = name;
            nnode->next = NULL;
            if(!head){head = nnode;}
            else
            {
                node* current = head;
                while(current->next){current = current->next;}
                current->next = nnode;
            }
        }
    }
    else{cout << "file is not open" << endl;}
    return head;
}

void splitMerge(node* list){
    node *list1 = list, *list2 = nullptr;

    node *lastNode = list;
    node *midPointNode = list;

    if(list){
        while((lastNode) && (lastNode->next)){
            lastNode = lastNode->next->next;
            midPointNode = midPointNode->next;
        }
        list2 = midPointNode;
    }

    for(node* curr = list1; curr != NULL; curr = curr->next){if(curr->next == list2){curr->next = NULL;}}

    cout << "List 1: ";
    traverse(list1);
    cout << endl;

    cout << "List 2: ";
    traverse(list2);
    cout << endl;

    cout << "Merged list consists of: ";
    traverse(merge(list1, list2));
    cout << endl;
}

void traverse(node* list)
{
    for(node* curr = list; curr; curr = curr->next)
    {
        cout << curr->data << " ";

    }

}

node* merge(node* list1, node* list2)
{

    for(node *curr = list1; curr; curr = curr->next)
    {
        if(curr->next == NULL)
        {
            curr->next = list2;

        }
        else if(curr == list2)
        {
            return list1;

        }

    }


    return list1;
}

