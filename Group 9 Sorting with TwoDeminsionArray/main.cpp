#include <bits/stdc++.h>
using namespace std;

const int rows = 5;
const int columns = 4;
///Notice rows and row.
void Bubble_Sort(int array[][columns], int row);
void Selection_Sort(int array[][columns], int row);
void Shell_Sort(int array[][columns], int row);
void Insertion_Sort(int array[][columns], int row);

void Display_Array(int array[][columns], int row);
void Reset_Array(int temp[][columns], int row);
void Swap_Array(int *xp, int *yp);



void Swap_Array(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void Bubble_Sort(int array[][columns], int row){
   int index;
   for(;row > 0; row--){
       for(index = 0; index < row -1; index++){
           if(array[index][0] > array[index+1][0]){

               ///we'r using pointers for swap, so we need the address of the content of the array for the pointers.
               ///give me the address of the array index.
               Swap_Array(&array[index][0], &array[index+1][0]); /// uses swap function.
               ///int temp = array[index][1];
               ///array[index][1] = array[index + 1][1];
               ///array[index + 1][1] = temp;
           }
       }
   }

}

void Selection_Sort(int array[][columns], int row){
   int temp, index, indexLarge;
   for(;row>0; row--){
     indexLarge = 0;
       for(index = 1; index <= row; index++){
           if(array[index][1] < array[indexLarge][1]){ /// just change to < for Ascending order
             indexLarge = index;
           }
       }
       if(rows!=indexLarge)
       {
          Swap_Array(&array[row][1], &array[indexLarge][1]);
          ///int temp = array[row][1];
          ///array[row][1] = array[indexLarge][1];
          ///array[indexLarge][1] = temp;
       }

       /// for sorting any column just change the index number 0, 1, 2....
   }
}

void Shell_Sort(int array[][columns], int row){
	int temp;
	for (int gap=row/2; gap>=1; gap=gap/2)
		for(int i=gap; i<row; i++)
			for (int j=i; j>=gap && array[j-gap][2]>array[j][2];j=j-gap){   /// sorting 3rd columns which is index array[2].
                Swap_Array(&array[j-gap][2], &array[j][2]);
				///temp=array[j-gap][2];
				///array[j-gap][2]=array[j][2];
				///array[j][2]=temp;
			}
}

void Insertion_Sort(int array[][columns], int row)
{
   int i, j;
   for(i = 0; i < columns; i++){
       j = i;
       while(j > 0 && array[row][j] < array[row][j - 1]){

           Swap_Array(&array[row][j], &array[row][j-1]);
           ///int temp = array[4][j];
           ///array[4][j] = array[4][j - 1];
           ///array[4][j - 1] = temp;
           j--;
       }
   }
}



void Display_Array(int arr[][columns], int row){

   int i, j;
   for(i = 0; i < row; i++){
       for(j = 0; j < columns; j++){  /// constant columns
          cout << arr[i][j] << " ";
       }
       cout << endl;
   }
}

void Reset_Array(int temp[][columns], int row)
{
    int array[rows][columns]={
                            {5, 3, 2, 16},
                            {9, 8, 10, 17},
                            {4, 7, 11, 18},
                            {2, 5, 9, 12},
                            {7, 9, 4, 10}
                            };

   int i, j;
   for(i = 0; i < row; i++){ /// loops at the rows
       for(j = 0; j < columns; j++){ /// 4 column that is why. loops at the columns
           temp[i][j] = array[i][j];
       }
   }
}

// Driver code
int main()
{
    int array[rows][columns]={
        {5, 3, 2, 16},
        {9, 8, 10, 17},
        {4, 7, 11, 18},
        {2, 5, 9, 12},
        {7, 9, 4, 10}
        };

    cout << "Original Array\n";
    Display_Array(array, rows); /// constant rows.

    cout << endl << endl << "Sorting First Column by Bubble Sort\n";
    Bubble_Sort(array, rows -1); /// size of array -1.
    Display_Array(array, rows);

    Reset_Array(array, rows);/// reseting array to original.
    cout << endl << endl << "Sorting Second Column by Selection Sort\n";
    Selection_Sort(array, rows-1);
    Display_Array(array, rows);

    Reset_Array(array, rows);/// reseting array to original.
    cout << endl << endl << "Sorting Third Column by Shell Sort\n";
    Shell_Sort(array, rows);
    Display_Array(array, rows);

    Reset_Array(array, rows);
    cout << endl << endl << "Sorting Fifth Row by Insertion Sort\n";
    Insertion_Sort(array, 4);
    Display_Array(array, rows);

    return 0;
}
