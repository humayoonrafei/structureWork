#include <iostream>
using namespace std;

string AddComma(string arr, int n);

int main()
{
  string input, result;
  int n;
  cout << "Enter number: ";
  cin >> input;
  result = AddComma(input, input.size());
  cout << "Comma Separated: " << result;
}

string AddComma(string arr, int n)
{
  string a;

  if (n / 3 >= 0)
  {
    if (n - 3 <= 0 && arr.size() < 4)
    {
      n = n - 3;
    }

    a += AddComma(arr, n-3);

    if (a != "" && arr[arr.size() - 1] != a[a.size() - 1])
    {
      a+= ",";
    }

    for (int i = 0; i < 3; i++)
    {
      a += arr[n + i];
    }

    return a;
  }
}
