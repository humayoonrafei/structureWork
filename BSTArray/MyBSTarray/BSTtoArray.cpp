#include <iostream>
#include <cmath>
using namespace std;

const int Size = 10;

struct BST{
  int data;
  BST *right, *left;
};

struct BST* NewNode(int value){
  BST* leaf = new BST;
  leaf->data = value;
  leaf->right = NULL;
  leaf->left = NULL;

  return leaf;
}

struct BST* InsertLeaf(BST* leaf, int value){
  if(leaf == NULL){
    return NewNode(value);
  }
  else{

    if(value < leaf->data){
      leaf->left = InsertLeaf(leaf->left,value);
    }
    else{
      leaf->right = InsertLeaf(leaf->right, value);
    }
    return leaf;
  }

  return leaf;
}

int getHeight(BST* leaf){
  int L, R;

  if(leaf == NULL){
    return -1;
  }
  else
  {
    L = getHeight(leaf->left);
    R = getHeight(leaf->right);

    if(L>R){
      return (L +=1);
  }
    else{
      return (R +=1);
    }
  }
}

int getNomberOfLeave(BST* leaf){
  int h = getHeight(leaf);

  int numOfLeav = (pow(2, h+1) -1);

  return numOfLeav;
}

void BSTtoUnsortedArr(BST* leaf, int i){
  int node = getNomberOfLeave(leaf);
  int a[Size];

  if(leaf){
    a[i] = leaf->data;

    BSTtoUnsortedArr(leaf->left, 2*i + 1);
    BSTtoUnsortedArr(leaf->right, 2*i + 2);
    cout << a[i] << " ";
  }

}

struct BST* UnsortedArrToBST(int arr[], int i){

  BST* node = NULL;
  if(arr[i] != 99){
    node = NewNode(arr[i]);
    if((i*2) + 2 < Size){
      node->left = UnsortedArrToBST(arr,(i*2) +1);
      node->right = UnsortedArrToBST(arr,(i*2) +2);
    }
  }
  return node;
}

struct BST* SortedArrayToBST(int arr[], int low, int high){
  if(low > high){
    return NULL;
  }

  int mid = (low+high)/2;

  BST* root = NewNode(arr[mid]);
  root->right = SortedArrayToBST(arr,low,mid-1);
  root->left = SortedArrayToBST(arr,mid+1,high);

  return root;
}

void BSTtoSortedArray(BST* leaf, int position){
  int a[30];

  if(leaf){
    BSTtoSortedArray(leaf->left, position*2 + 1);
    a[position] = leaf->data;
    cout << a[position] << " ";
    BSTtoSortedArray(leaf->right,position*2 + 2);
  }
}

void PreOrder(BST* leaf){
  if(!leaf)
    return ;

  PreOrder(leaf->left);
  cout << leaf->data <<" ";
  PreOrder(leaf->right);

}

int main() {

    BST* root;

    root = InsertLeaf(root, 5);
    root = InsertLeaf(root, 3);
    root = InsertLeaf(root, 4);
    root = InsertLeaf(root, 12);
    root = InsertLeaf(root, 14);

    cout << "BST to an unsorted array: ";
    BSTtoUnsortedArr(root, 0);
    cout << endl;

    cout << "BST to an sorted array:   ";
    BSTtoSortedArray(root, 0);
    cout << endl;

    cout << "unsorted array to BST: ";
    int a[] = {3,4,5,6,9,8,1,2,12};
    root = UnsortedArrToBST(a,0);
    PreOrder(root);
    cout << endl;

    int b[] = {1,2,3,4,5,6,7,8,9,10};
    cout << "sorted array to BST:   ";
    root = SortedArrayToBST(b, 0, 9-1);
    PreOrder(root);
}
