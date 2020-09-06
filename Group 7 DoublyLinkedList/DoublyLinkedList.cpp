#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct node{
   string name;
   node *prev;
   node *next;
};

struct node *header=NULL,*tail=NULL;

void addName(string name)
{
   if(header==NULL)
   {
       header=new node;
       header->name=name;
       header->next=header->prev=NULL;
       tail=header;//header also points to tail
   }
   else if(name<header->name)
   {
       header->prev=new node;
       header->prev->name=name;
       header->prev->next=header;
       header=header->prev;
       header->prev=NULL;
   }
   else if(name>tail->name)
   {
       tail->next=new node;
       tail->next->name=name;
       tail->next->prev=tail;
       tail=tail->next;

       tail->next=NULL;
   }
   else
   {
       node *temp=header;
       while(temp->name<name) //traverse upto list name is less than new name
       {
           temp=temp->next;
       }

       node *nn=new node;
       nn->name=name;
       temp->prev->next=nn;
       nn->prev=temp->prev;
       nn->next=temp;
       temp->prev=nn;
   }

}
string convertToLower(string upStr)
{
   string lowStr="";//new string
   for(int i=0;i<strlen(upStr.c_str());i++)
       if(upStr[i]>=65 && upStr[i]<=90)
           //when upper case found
           //c_str convert to c str;
           lowStr+=tolower(upStr[i]);
           //convert lower and add to new string

   return lowStr;//return new string
}
void deleteName(string name)
{

   node *temp=header;
   if(convertToLower(header->name)==convertToLower(name))
   {
       header=header->next;
       header->prev=NULL;
       delete temp;
   }
   else if(convertToLower(tail->name)==convertToLower(name))
   {
       temp=tail;
       tail=tail->prev;
       tail->next=NULL;
       delete temp;
   }
   else
   {
       while(temp!=NULL && convertToLower(temp->name)!=convertToLower(name))
           temp=temp->next;
       if(temp!=NULL)
       {
           temp->next->prev=temp->prev;
           temp->prev->next=temp->next;
           delete temp;
       }
   }
}
int main()
{
   ifstream infile("input.txt");
   string line,name="";

   infile>>line;
   while(infile.good())
   {
       if(line=="delete")
       {
           infile>>name;
           deleteName(name);
       }
       else
       {
           addName(line);
       }
       infile>>line;
   }
   infile.close();

   ofstream outfile("output.txt");
   node *temp=header;
   while(temp!=NULL)
   {
       cout<<temp->name<<endl;
       outfile<<temp->name<<endl;
       temp=temp->next;
   }

   cout<<"================"<<endl;
   outfile<<"================"<<endl;
   temp=tail;
   while(temp!=NULL)
   {
       cout<<temp->name<<endl;
       outfile<<temp->name<<endl;
       temp=temp->prev;
   }
   outfile.close();


   return 0;
}
