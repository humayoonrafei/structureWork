#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

struct BinaryTree* Insert(struct BinaryTree* root, int data);
struct BinaryTree* deletion(struct BinaryTree* root, int key);
void Level(struct BinaryTree* root, int level);
void Inorder(struct BinaryTree* root);
void Preorder(struct BinaryTree* root);
void Postorder(struct BinaryTree* root);
int height(struct BinaryTree* node);
void display();

struct BinaryTree
{
    int data;
    BinaryTree *right, *left;
};

int main(){display(); return 0;}
ofstream output("output.txt");

struct BinaryTree* minn(BinaryTree* root)
{
    BinaryTree* current = root;
    while(current->left)
    {
        if(!current->left->left)
        {
            return current->left;
        }

        current = current->left;

    }
   return NULL;
}

void LevelOrder(BinaryTree* root)
{
    for (int h = height(root), i = 1; i <= h; cout << endl)
    {
        Level(root, i++);
    }
}

struct BinaryTree* Insert(BinaryTree* root, int data)
{
    if(!root)
    {
        BinaryTree* root = new BinaryTree;
        root->data = data;
        root->right = NULL;
        root->left = NULL;
        return root;
    }
    if(data < root->data)
    {
        root->left = Insert(root -> left, data);
    }
    else if(data > root->data)
    {
        root->right = Insert(root->right, data);
    }
    else
    {
            root = deletion(root, data);
    }
    return root;
}

void Inorder(BinaryTree* root)
{
    if(!root)
        return;
    Inorder(root->left);
    cout << root->data << " ";
    output << root->data << " ";
    Inorder(root->right);
}

void Preorder(BinaryTree* root)
{
    if(!root)
        return;
    cout << root->data << " ";
    output << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(BinaryTree* root)
{
    if(!root)
        return;
    Postorder(root -> left);
    Postorder(root -> right);
    cout << root -> data << " ";
    output << root->data << " ";
}

struct BinaryTree* deletion(BinaryTree* root, int key)
{
    if(!root)
    {
        return root;
    }
    if(key < root->data)
    {
        root->left = deletion(root->left, key);
    }
    else if(key > root->data)
    {
        root->right = deletion(root->right, key);
    }
    else
    {
        if (!(root->left))
        {
            BinaryTree* temp = root->right;
            delete(root);
            return temp;
        }
        else if (!(root->right))
        {
            BinaryTree* temp = root->left;
            delete(root);
            return temp;
        }
        BinaryTree* temp = minn(root->right);
        root->data = temp->data;
        root->right = deletion(root->right, temp->data);
    }
    return root;
}

int height(BinaryTree* node)
{
    if (!node)
        {return 0;}
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
            {return (lheight + 1);}
        else
        {
            return (rheight + 1);
        }
    }
}

void Level(BinaryTree* root, int level)
{
    if (!root)
        {return;}
    if (level == 1)
    {
        cout << root->data << " ";
        output << root->data << endl;
    }
    else if (level > 1)
    {
        Level(root->left, level-1);
        Level(root->right, level-1);
    }
}

void display(){

    BinaryTree *root = NULL, *leaf = NULL;
    ifstream input("input.txt");

    string data;
    while(input.good())
    {
        input >> data;

        if(data == "delete"){}
        else
        {
            int num;
            istringstream (data) >> num;
            root = Insert(root, num);
            leaf = Insert(leaf, num);
        }
    }

    cout << "In order: ";
    output << "In order: ";
    Inorder(root);
    cout << endl;

    cout << "Pre order: ";
    output << "\nPre order: ";
    Preorder(root);
    cout << endl;

    cout << "Post order: ";
    output << "\nPost order: ";
    Postorder(root);
    cout << endl;

    cout << "Levels: " << endl;
    output << "\nLevels: " << endl;
    LevelOrder(root);

    input.close();
    output.close();
}

