#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

void insertItem(int arr[], int temp);
bool searchItem(int arr[], int temp);
void display(int arr[]);

#define MAX 10
int SIZE = 10;

int j = 1;
int i = 0;
int k = 0;

void insertItem(int arr[], int temp)
{
    bool x = false;
    int high;
    int val = pow(i, 2);
    int mod = temp % MAX;

    if(arr[mod] == '\0'){
      arr[mod] = temp;
    }
    else if(arr[mod]){

        cout << j++ << " Inserting: " << temp << " in " << mod << "." << endl;
        mod = mod - (temp % mod);
        if(arr[mod] == 0){
          arr[mod] = temp;
        }
        else if(arr[mod]){

            cout << j++ << " Inserting: " << temp << " in " << mod << "." << endl;
            do
            {
                high = (temp + val) % MAX;

                if(!(arr[high]))
                {
                    arr[high] = temp;
                    x = true;
                }

                else if(arr[high])
                {
                    cout << j++ << " Inserting: " << temp << " in " << mod << "." << endl;
                    x = true;
                }
                i++;
            }while(!x);
            x = false;
            if(arr[high])
            {
                k = temp;
                do
                {
                    mod = k % MAX;
                    if(!(arr[mod]))
                    {
                        arr[mod] = temp;
                        x = true;
                    }

                    else if(arr[mod])
                    {
                        k++;
                    }
                }while(!x);
            }
        }
    }
}

bool searchItem(int arr[], int temp)
{
    bool x = false;
    int high;
    int val = pow(i, 2);
    int mod = temp % MAX;

    if(arr[mod] == temp)
    {
        x = true;
        return x;
    }

    else if(arr[mod] != temp)
    {
        mod = mod - (temp % mod);
        if(arr[mod] == temp)
        {
            x = true;
            return x;
        }
        else if (arr[mod]!=temp)
        {
            do
            {
                high = (temp + val) % MAX;
                if(arr[high] == temp)
                {
                    arr[high] = temp;
                    x = true;
                    return x;
                }
                else if (arr[high]!=temp){x = false;}
                i++;
            }while(x == false);
            return (x);
            x = false;
            if(arr[high] != temp)
            {
                k = temp;
                do
                {
                    mod = k % MAX;
                    if(arr[mod] == temp)
                    {
                        x = true;
                        return (x);
                    }
                    else if(arr[mod] != temp){k++;}
                }while(x == false);
                return (x);
            }
        }
    }
    return (x);
}

void display(int arr[])
{
    cout << "\n Displaying Hash:" << endl;
    for(int i = 0; i < MAX; i++){cout << arr[i] <<", ";}
}

int main()
{
    ifstream input("input.txt");
    int temp;
    int arr[SIZE];

    while(input >> temp){
      insertItem(arr, temp);
    }

    display(arr);

    cout << endl;
    cout << "Search: ";
    int userInput;

    cin >> userInput;

    if(searchItem(arr,userInput) == true){
      cout<<"Found!";
    }
    else{
      cout<<"Not Found!\n";
    }
}
