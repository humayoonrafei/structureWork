#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

struct node
{
    char data[30];
    node *next;
    node(){}
    node(char *data, node *next)
    {
        strcpy(this->data, data);
        this->next = next;
    }
};

struct tree
{
    char data[30];
    node *next;
    tree *left;
    tree *right;
    tree(){}
    tree(char *data, node *next, tree *left, tree *right)
    {
        strcpy(this->data, data);
        this->next = next;
        this->left = left;
        this->right = right;
    }
};

tree *Insert(tree *root, char *data)
{
    if(!root){root = new tree(data, NULL, NULL, NULL);}
    else if(strcmp(data, root->data) == 0)
    {
        if(!root->next){root->next = new node(data, NULL);}
        else
        {
            node *now;
            for(now = root->next; now->next; now = now->next){cout << now->next->data << endl;}
            now->next = new node(data, NULL);
        }
    }
    else if(strcmp(data, root->data) < 0){root->right = Insert(root->right, data);}
    else if(strcmp(data, root->data) > 0){root->left = Insert(root->left, data);}
    return root;
}

bool SearchName(tree *root, char *data)
{
    if(!root){return false;}
    else if(strcmp(root->data, data) == 0)
    {
        cout << root->data << " ";
        if(root->next)
        {
            int i = 2;
            for(node *curr = root->next; curr->next; curr = curr->next){i++;}
            cout << '\n' << i << " iterations of " << root->data << " "<< endl;
        }
        else{cout << '\n' << "Only 1 iteration of " << root->data << " "<< endl;}
        return true;
    }
    else if(strcmp(data, root->data) < 0)
    {
        cout << root->data << " ";
        return SearchName(root->right, data);
    }
    else
    {
        cout << root->data << " ";
        return SearchName(root->left, data);
    }
}
int main()
{
    tree* root = NULL;
    ifstream input("input.txt");
    char n[30];
    while(input>>n){root = Insert(root, n);}
    char search[30];
    cout << "Enter name to be searched" << endl;
    cin >> search;
    cout << endl;

    if(SearchName(root, search) == true){cout << "Name Found" << endl;}
    else{cout << "Name Not Found" << endl;}
}
