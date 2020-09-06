#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void quickSort(int arr[], int low, int high);
int getPartition(int arr[], int low, int high);
void addDigit(int arr[], int counter);
void countSort(int arr[], int n, int exp);
void radixSort(int arr[], int n);
int getMax(int arr[], int n);
void printArray(int arr[], int n);
void displayData();


int main()
{
    displayData();
    return 0;
}

int getPartition(int arr[], int low, int high)
{
    int pivot = arr[high], i = (low - 1);
    for (int j = low; j <= high- 1; j++)
    {
        if(arr[j] >= pivot)
        {
            swap(arr[++i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = getPartition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi, high);
    }
}

void addDigit(int arr[], int counter)
{
    for(int i = 0; i < counter; i++)
    {
        for(int j = (to_string(arr[0]).length()); (to_string(arr[i]).length()) < j;)
        {
            arr[i] = stoi(to_string(arr[i])+'5');
        }
    }
}

void countSort(int arr[], int n, int exp)
{
    int temp[n], count[10] = {0};
    for (int i = 0; i < n; i++)
    {
        count[9-arr[i]/exp%10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        temp[--count[(9-(arr[i]/exp%10))]] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

void radixSort(int arr[], int n)
{
    for (int m = getMax(arr, n), exp = 1; m/exp>0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
}

int getMax(int arr[], int n)
{
    int m = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > m)
        {
            m = arr[i];
        }
    }
    return m;
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void displayData()
{
    int numA[10];

    ifstream infile("input.txt");

    int n = 0;
    while(infile.good())
    {
        infile>>numA[n];
        n++;
    }

    cout << "Original array:" << endl;
    printArray(numA, n);
    cout << endl;

    quickSort(numA, 0, n - 1);
    cout << "Decending(QuickSort): " << endl;
    for (int i = 0; i < n; i++){cout << numA[i] << " ";}
    cout << '\n' << endl;
    addDigit(numA, n);
    cout << "After adding the five's: " << endl;
    for (int i = 0; i < n; i++){cout << numA[i] << " ";}
    cout << '\n'  << endl;
    radixSort(numA, n);
    cout << "Decending(RadixSort): " << endl;
    for (int i = 0; i < n; i++){cout << numA[i] << " ";}
    cout << endl;
}
