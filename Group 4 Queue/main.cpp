#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;

int queue[500],queFront = 0,queRear = 0;

void enqueue(int elemnt){
    queue[queRear] = elemnt;
    queRear++;
    }

int dequeue(){
    int elemnt;
    if (queFront == queRear){
            return -9999;
    }
    else{
            elemnt = queue[queFront];
            queFront ++;
            return elemnt;
    }
}

void traverse(){
    int i,temp = queFront;
    cout << "  ";
    for(i = temp; i < queRear; i++){
            cout << queue[i] << " ";
    }
    cout << endl << endl;
    }

int main(){
    ifstream infile;
    infile.open("input.txt");
    int fileData;

    while(infile >> fileData){
            enqueue(fileData);
    }

    infile.close();

    cout << "Original queue including the negative numbers: " << endl << endl;

    traverse();

    cout << endl;

    int last = -1,first = -1;

    int deque = 0;

    while(deque != -9999){

    deque = dequeue();

    if(deque > 0){
        enqueue(deque);

        first = deque;

        break;
    }

    }

    if(first!=-1){
        while(deque != -9999){
            deque = dequeue();

            if(deque > 0){

            enqueue(deque);

            if(deque != first){

            last=deque;

            }

            else{
                    break;

            }

            }

        }

    }

    while(deque != last){
        deque = dequeue();

        enqueue(deque);

    }

    cout << "Updated queue after removing the negative numbers: " << endl << endl;

    traverse();

}
