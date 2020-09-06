#include <iostream>
using namespace std;

void ConvertToString(string x, int* p);
int AddNumber(int* p, int x);
void Display();

int main(){Display();return 0;}

void ConvertToString(string x, int* p)
{
    for (int i = 0; i < x.length(); i++)
    {
        int a = x[i] - '0';
        p[i] = a;
    }
}

int AddNumber(int* p, int x)
{
    if (x != 3)
    {
        int total = AddNumber(p, x+1);
        return total+p[x];
    }
    else
    {
      return p[x];
    }
}
 void Display()
 {
    int arr[4] = {0};
    string userInput;
    cout << "Enter a number(4 digits or less): ";
    cin >> userInput;

    ConvertToString(userInput, arr);
    int total = AddNumber(arr, 0);
    cout << "Total of the digits: " << total;
 }
