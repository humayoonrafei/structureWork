#include <iostream>
using namespace std;

void BubbleSort(int rows);
void SelectionSort(int rows);
void ShellSort(int rows);
void InsertionSort(int rows);
void Display(int rows);
void Reset(int temp[][4], int rows);
int BinSearch(int rows, int start, int end, int num);
void DisplayDataBase(int arr[][4]);


int rows = 5;
int columns = 4;
int array[5][4]={{5, 3, 2, 16}, {9, 8, 10, 17}, {4, 7, 11, 18}, {2, 5, 9, 12}, {7, 9, 4, 10}};

int main()
{
   int arr [5][4];
   DisplayDataBase(arr);
   return 0;
}

void Swap(int *item)
{
    int temp = *item;
    *item = *(item+1);
    *(item+1) = temp;
}

void BubbleSort(int rows){
   int index;
   for(;rows > 0; rows--){
       for(index = 0; index < rows -1; index++){
           if(array[index][0] > array[index+1][0]){
               //Swap(&array[j][0]);
               int temp = array[index][0];
               array[index][0] = array[index + 1][0];
               array[index + 1][0] = temp;
           }
       }
   }

}

void SelectionSort(int rows){
   int i, j;
   for(i = 0; i < rows; i++){
       int maxi = array[i][1];
       int pos = i;
       for(j = i; j < rows; j++){
           if(array[j][1] < maxi){
               maxi = array[j][1];
               pos = j;
           }
       }
       int temp = array[i][1];
       array[i][1] = array[pos][1];
       array[pos][1] = temp;
   }
}

void ShellSort(int rows){
   int diff = rows / 2;
   while(diff > 0){
       int i, j;
       for(i = diff; i < rows; i++){
           int t = array[i][2];
           j = i;
           while(j >= diff && array[j - diff][2] > t){
               array[j][2] = array[j - diff][2];
               j = j - diff;
           }
           array[j][2] = t;
       }
       diff = diff / 2;
   }
}

void InsertionSort(int rows){
   int i, j;
   for(i = 0; i < 4; i++){
       j = i;
       while(j > 0 && array[4][j] < array[4][j - 1]){
           int temp = array[4][j];
           array[4][j] = array[4][j - 1];
           array[4][j - 1] = temp;
           j--;
       }
   }
}

void Display(int rows){

   int i, j;
   for(i = 0; i < rows; i++){
       for(j = 0; j < 4; j++){
          cout << array[i][j] << " ";
       }
       cout << endl;
   }
}

void Reset(int temp[][4], int rows){
   int i, j;
   for(i = 0;i < rows;i++){
       for(j = 0; j < 4; j++){
           array[i][j] = temp[i][j];
       }
   }
}

int BinSearch(int rows, int start, int end, int num){
   int mid = (start + end) / 2;

   if(start > end)
       return -1;

   if(array[4][mid] == num)
       return mid;
   else if(array[4][mid] < num)
       return BinSearch(rows, mid + 1, end, num);
   else
       return BinSearch(rows, start, mid - 1, num);
}

void DisplayDataBase(int arr[][4])
{
   cout << "Original arrayay" << endl;
   Display(rows);

   int i, j;
   for(i = 0; i < rows; i++){
       for(j = 0;j < columns; j++){
           arr[i][j] = array[i][j];
       }
   }

   cout << "1st Column Bubble Sorted " << endl;
   BubbleSort(rows);
   Display(rows);


   Reset(arr, rows);
   cout << "Second Column Selection Sorted " << endl;
   SelectionSort(rows);
   Display(rows);

   Reset(arr, rows);
   cout << "Third Column Shell Sorted " << endl;
   ShellSort(rows);
   Display(rows);

   Reset(arr, rows);
   cout << "Fourth Column Insertion Sorted" << endl;
   InsertionSort(rows);
   Display(rows);

   int num;
   printf("Enter a number to be searched in row 5\n");
   scanf("%d", &num);

   int res = BinSearch(rows, 0, columns - 1, num);
   if(res == -1)
       printf("No Number founded\n");
   else
       printf("Number is founded at row 5 at column %d\n", res + 1);
}

