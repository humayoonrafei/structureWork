#include <iostream>
#include <fstream>
#include <array>
using namespace std;

struct tree
{
    tree* left;
    tree* right;
    int data;
};


tree* newNode(int data)
{
    tree* node = new tree;
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;

    return(node);
}

tree* sortedArrayToBST(int arr[], int start, int end)
{

    if (start > end)
    return NULL;


    int mid = (start + end)/2;
    tree *root = newNode(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid - 1);

    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

void printInorder(tree* node)
{
    if (node == NULL)
        return;

    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

int maxDepth(tree* node)
{
    if (node == NULL)
        return 0;
    else
    {

      int lDepth = maxDepth(node->left);
      int rDepth = maxDepth(node->right);


      if (lDepth > rDepth)
        return(lDepth + 1);
      else
        return(rDepth + 1);
    }
}


void printGivenLevel(tree* root, int level,int unsortedArr[],int j)
{

    if (root == NULL)
    {
        unsortedArr[j] = 0;
        cout << unsortedArr[j] << ' ';
        ++j;
        return;
    }
    if (level == 1)
    {
        unsortedArr[j] = root->data;
        cout << unsortedArr[j] << ' ';
        ++j;
    }
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1,unsortedArr,j);
        printGivenLevel(root->right, level-1,unsortedArr,j);
    }
}
void BSTtoArray(tree* root,int unsortedArr[])
{
    int h = maxDepth(root);
    int i,j = 0;
    for (i = 1; i <= h; i++)
        printGivenLevel(root, i,unsortedArr,j);
}

void insert(tree * &pRoot, int val)
{
    if(pRoot == NULL)
        pRoot = newNode(val);
    else if((pRoot)->data <= val)
        insert(((pRoot)->right), val);
    else if((pRoot)->data > val)
        insert(((pRoot)->left), val);
}

tree*  getBST(int * arr, int size)
{
    tree * pRoot = NULL;
    for(int i = 0; i < size; i++)
        insert(pRoot, arr[i]);
    return pRoot;
}

void display(tree* root){

    int arr[10];
    int i = 0;

    ifstream inputFile("input.txt");
    while(inputFile >> arr[i])
    {
      ++i;
    }

    cout << "Sorted array from file ";
    for(int j = 0 ; j <i ; ++j)
        cout << arr[j] << " ";
        cout << endl << endl;

    root = sortedArrayToBST(arr,0, i - 1);
    cout << "BST inorder traversal ";

    printInorder(root);
    cout << endl << endl;
    int unsortedArr[(2^(maxDepth(root) + 1)) - 1];

    cout << "Unsorted array to BST ";

    BSTtoArray(root,unsortedArr);

    cout << endl << endl;
    tree* Root = getBST(unsortedArr,6);
    cout << "Tree to unsorted array: ";

    printInorder(root);

    cout << endl;
    inputFile.close();
}
int main(){
  tree* root;
  display(root);
  return 0;
}
