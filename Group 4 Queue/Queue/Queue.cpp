#include <iostream>
#include <fstream>
using namespace std;


void enqueue(int item, struct node *&front, struct node*&rear);
void dequeue(struct node *& front, struct node *& rear);
void Traverse(node* &queue);
void ReadFile();


struct node {
     int item;
     node *next;
};

void enqueue(int item, struct node *&front, struct node*&rear)
{
    struct node *newNode=new node;

    newNode->item=item;
    newNode->next=NULL;

    if(rear)
    {
        if(newNode->item > 0)
        {
            rear ->next=newNode;
            rear =newNode;
        }
    }
    else
    {
        front = rear =newNode;
    }

}

void dequeue(struct node *& front, struct node *& rear)
{
    struct node *temp;

    if(front)
    {
        temp= front;
        front = front->next;
        delete temp;
        if (!front)
        {
            rear=NULL;
        }

    }
}

void Traverse(node* &front, node* &rear)
{
    ofstream outfile("out.txt");

    node* curr = front;
    while(curr != NULL)
    {
        outfile << curr->item << " ";
        cout << curr->item << " ";
        //front = front->next;
        dequeue(curr, rear);
    }
}

void ReadFile()
{
    struct node * front, * rear;
    front = rear =NULL;

    ifstream infile("input.txt");

    if(!infile.is_open())
    {
        cout << "File is not Found" << endl;
    }
    int num;
    while(infile.good())
    {
        infile >> num;
        enqueue(num, front, rear);
    }

    Traverse(front, rear);
    infile.close();
}

int main(){ReadFile();return 0;}

