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
    cout<<"eg. \t ./a.out ";
}

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
        writeToFile(name);
    }
    else if(argc == 1)
    {
        ifstream file;
        file.open(FILENAME);
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
        showInstructions();
    }
}