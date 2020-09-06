#include <iostream>
#include <fstream>
using namespace std;
//;kdfjhg;osidfjg;sdfj;gildfsj;glisjdf;lgidfsj
void stringCopy(char *A, char *B);
bool stringCompare(char *A, char *B);
void stringConcatenation (char *A, char *B);
int stringPosition(char *A, char B);
char* stringLength(char *A);

ifstream in("input.txt");


int main()
{
    char a[20], b[20];

    in >> a >> b;
    stringCopy(a, b);

    in >> a >> b;
    stringCompare(a, b);

    in >> a >> b;
    stringConcatenation(a, b);

    in >> a >> b;
    stringPosition(a, 'r');

    in >> a;
    stringLength(a);


    in.close();
    return 0;
}

void stringCopy(char* A, char* B)
{
    int counter = 0;

    char temp;

    for (int i = 0; B[i] != '\0'; i++)
    {
        temp = A[i];
        A[i] = B[i];
        B[i] = temp;

        counter++;
    }

    A[counter] = '\0';

    cout << endl << "Copy String B to A: " << A << endl << endl;
}

bool stringCompare(char *A, char *B)
{
    bool a;

    int i=0;
    while(A[i] != '\0' && B[i] != '\0')
    {
        if(A[i] == B[i])
        {
            a = true;
        }

        if(A[i] != B[i])
        {
            if(A[i] > B[i] || A[i] < B[i])
            {
                a = false;
            }
        }

        i++;
    }

    cout << "Compares String A with String B: " << a << endl << endl;

    return a;
}

void stringConcatenation (char *A, char *B)
{
    char str[20];

    int i = 0, j = 0;

    while(A[i] != '\0')
    {
        str[j] = A[i];
        i++;
        j++;
    }

    i = 0;
    while(B[i] != '\0')
    {
        str[j] = B[i];
        i++;
        j++;
    }

    cout << "Concatenats String B to A: " << str << endl << endl;
}

int stringPosition(char *A, char B)
{
    int found = -1;


    for(int i=0; A[i] != '\0'; i++)
    {
        if(A[i] == B)
        {
            found = i;
        }

    }

    cout << "Returns the indext position in the string: " << found << endl << endl;

    return found;
}

char* stringLength(char *A)
{
    int i, strLength = 0;
    char str[50];

    for(i=0; A[i] != '\0'; i++)
    {
        strLength++;
        str[i+1] = A[i];
    }

    str[0] = char(i+48);
    A = str;

    cout << "Placed the Length of string into index 0: " << A << endl << endl;

    return A;
}



