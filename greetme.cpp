#include<iostream>
#include<fstream>
#include<cstring>
#define FILENAME "Name.txt"

using namespace std;
int main(int argc,char* argv[])
{
    char name[50];
    if(argc == 2 && strcmp(argv[1],"-n")== 0)
    {
        cout<<"Whats your name:";
        // TODO: if name is empty, then do something
        // TODO: remove unnecessary spaces
        cin.getline(name,50);
        cout<<"Hello "<<name;
        fstream file;
        file.open(FILENAME, ios::out);
        file<<name;
        file.close();
    }
    else if(argc == 1)
    {
        fstream file;
        file.open(FILENAME, ios::in);
        if(!file)      //file doesnt exists
        {
            cout<<"Sorry, I dont know your name"<<endl;
            cout<<"Give a argument '-n' to enter name";
        }
        else
        {   
            cout<<"Hello "; 
            file.getline(name,50);
            cout<<name;
        }
        file.close();
    }
    else
    {
        cout<<"Invalid arguments "<<endl;
        cout<<"Enter '-n' as argument if not signed in before  \n\t eg.\t./a.out -n \n or zero argument to greet you\n\t eg. \t ./a.out ";
    }
}