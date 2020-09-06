#include <iostream>
using namespace std;

const int Size = 8;

int Get_Max(int arr[], int n);
void Count_Sort(int arr[], int n, int exp);
void Radix_Sort(int arr[], int n);
void Display_DataBase();

int main()
{
    Display_DataBase();
    return 0;
}

void Display_DataBase()
{
    int array[] = {170, 45, 75, 90, 802, 24, 2, 66};

    Radix_Sort(array, Size);

    cout << "\nAscending Order:  ";
    for (int i = 0; i < Size; i++)
    {
        cout << array[i] << "  ";
    }
    cout << endl << endl;
    cout << "Descending Order: ";
    for (int i = Size-1; i >= 0; i--)
    {
        cout << array[i] << "  ";
    }
    cout << endl;
}

int Get_Max(int arr[], int n)
{
    int maxNum = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxNum)
        {
            maxNum = arr[i];
        }
    }
    return maxNum;
}

void Count_Sort(int arr[], int n, int exp)
{
    int temp[n], count[10] = {0};

    for (int i = 0; i < n; i++)
    {
        count[(arr[i]/exp)%10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        temp[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

void Radix_Sort(int arr[], int n)
{
    int maxNum = Get_Max(arr, n);

    for (int exp = 1; maxNum/exp > 0; exp *= 10)
    {
        Count_Sort(arr, n, exp);
    }
}

