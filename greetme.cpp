#include<iostream>
#include<fstream>
#include<cstring>
#define FILENAME "Name.txt"

using namespace std;

void writeToFile(char *name)
{
    ofstream file;
    file.open(FILENAME);
    file<<name;
    file.close();
}

void showInstructions()
{
    cout<<"Enter '-n' as argument if not signed in before\n\t";
    cout<<"eg.\t./a.out -n \n";
    cout<<"or zero argument to greet you\n\t";
    cout<<"eg. \t ./a.out \n";
    cout<<"Enter '-h' for help\n";
    cout<<"Enter '-r' to reset name";
}

int main(int argc,char* argv[])
{
    char name[50];
    if(argc == 2 )
    {
        if(strcmp(argv[1],"-n")== 0)
        {
            cout<<"Whats your name: ";
            // TODO: if name is empty, then do something
            // TODO: remove unnecessary spaces
            cin.getline(name,50);
            cout<<"Hello "<<name;
            writeToFile(name);
        }
        else if(strcmp(argv[1],"-h")==0)
        {
            showInstructions();
        }
        else if(strcmp(argv[1],"-r")== 0)
        {
            remove(FILENAME);
            cout<<"Name is removed";
        }
        else
        {
            cout<<"Invalid argument";
            showInstructions();
        }
    }
    else if(argc == 1)
    {
        ifstream file;
        file.open(FILENAME);
        if(!file)      //file doesnt exists
        {
            cout<<"Welcome, you could give your name to greet you "<<endl;
            cout<<"Give a argument '-n' with greetme to enter name";
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
        showInstructions();
    }
}