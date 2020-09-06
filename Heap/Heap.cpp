#include <iostream>
#include <fstream>
using namespace std;

struct node *insert(int arr[], struct node *root, int i, int n);
void heap(int arr[], int n, int i);
void sort(int arr[], int n);
void GivenLevel(struct node *root, int level);
int height(struct node* node);
void LevelOrder(struct node *root);
void del(int arr[], int num);
void reheap(int arr[], int num, int element);
struct node* deleteTree(node *root);

#define SIZE 10

struct node
{
    int data;
    node *left;
    node *right;

};

node *deleteTree(node *root)
{
	if(root)
  {
    deleteTree(root->left);
		deleteTree(root->right);
		root = NULL;
		return root;
	}
	return NULL;
}

void LevelOrder(struct node *root){
  for (int i = 1, h = height(root); i <= h; cout << endl){
    GivenLevel(root, i++);
  }
}

void reheap(int arr[], int num, int element)
{
	int par;
	while(element > 0)
	{
		par = (element - 1)/2;
		if(num <= arr[par])
		{
			arr[element] = num;
			return;
		}
		arr[element] = arr[par];
		element = par;
	}
	arr[0] = num;
}

void del(int arr[], int num)
{
    int n = SIZE;
	int left, right, i, temp, par;

	for(i = 0; i < n; i++)
	{
		if(num == arr[i])
		break;
	}

	if(num != arr[i])
	{
		cout << num << "not found in heap\n";
		return;
	}

	arr[i] = arr[n - 1];
 	n = n - 1;
	par = (i - 1) / 2;
	if(arr[i] > arr[par])
	{
		reheap(arr, arr[i], i);
		return;
	}

	left = 2 * i + 1;
    right = 2 * i + 2;
    while(right < n)
	{
		if(arr[i] >= arr[left] && arr[i] >= arr[right]){
      return;
    }
		if(arr[right] <= arr[left])
		{
			temp = arr[i];
			arr[i] = arr[left];
			arr[left] = temp;
			i = left;
		}
		else
		{
			temp = arr[i];
			arr[i] = arr[right];
			arr[right] = temp;
			i = right;
		}
		left = 2 * i + 1;
		right = 2 * i + 2;
	}

	if(left == n - 1 && arr[i] < arr[left])
	{
        temp = arr[i];
		arr[i] = arr[left];
		arr[left] = temp;
	}
}

struct node* newNode(int value){
  node* leaf = new node;
  leaf->data = value;
  leaf->right = NULL;
  leaf->left = NULL;

  return leaf;
}

node *insert(int arr[], node *root, int i, int n)
{
  if (i < n)
  {
    node* temp =  newNode(arr[i]);
    root = temp;
    root->left = insert(arr, root->left, 2 * i + 1, n);
    root->right = insert(arr, root->right, 2 * i + 2, n);
  }
  return root;
}

void heap(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]){largest = l;}
    if (r < n && arr[r] > arr[largest]){largest = r;}
    if (largest != i)
    {
      swap(arr[i], arr[largest]);
      heap(arr, n, largest);
    }
}

void sort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--){
      heap(arr, n, i);
    }
    for (int i = n - 1; i >= 0; heap(arr, i--, 0)){
      swap(arr[0], arr[i]);
    }
}


void GivenLevel(node *root, int level)
{
    if (!(root)){return;}
    if (level == 1){cout << root->data << " ";}
    else if (level > 1)
    {
        GivenLevel(root->left, level - 1);
        GivenLevel(root->right, level - 1);
    }
}

int height(node *node)
{
    if (!(node)){return 0;}
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight){return(lheight + 1);}
        else{return(rheight + 1);}
  }
}

int main(){
    ifstream input;
    input.open("input.txt");
    node *root = NULL;

    int arr[SIZE];
    cout << "Input data: " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        input >> arr[i];
        cout << arr[i] << " ";
    }
    sort(arr, SIZE);
    cout << endl << endl;

    sort(arr, SIZE);
    cout << "Sorted heap: ";
    for (int i = 0; i < SIZE; i++){
      cout << arr[i] << " ";
    }

    root = insert(arr, root, 0, SIZE);
    cout << endl << endl << "Min heap (Level order): " << endl;
    LevelOrder(root);

    int max = arr[SIZE - 1];
    int de, counter;
    counter = 0;

    cout << endl;
    for(int i = 1; i <= 5; i++){
        int arrC = 0;
        cout << "Enter Number to Delete: ";
        cin >> de;
        del(arr, de);

        cout << "Current Heap: ";
        for (int j = 0; j < SIZE; j++)
        {
            if(arr[j] != max || j == SIZE - 1)
            {
                cout << arr[j] << " ";
                counter++;
            }
        }
        int arr2[SIZE - i];
        cout << endl;
        cout << "Current Tree: " << endl;
        for(int k = 0; k < SIZE; k++){
          if(arr[k] != max || k == SIZE - 1){
            arr2[arrC++] = arr[k];
          }
        }

        node *NewRoot = NULL;
        NewRoot = insert(arr2, NewRoot, 0, SIZE - i);
        LevelOrder(NewRoot);
        cout << endl;
        NewRoot = deleteTree(NewRoot);
    }
}
