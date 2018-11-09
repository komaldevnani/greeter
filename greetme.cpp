#include<iostream>
#include<fstream>
using namespace std;
int main(int argc,char* argv[])
{
    char name[20];
    if(argc == 2)
    {
        cout<<"Whats your name:";
        cin>>name;
        cout<<"Hello "<<name;
        fstream file;
        file.open("Name.txt",ios::out);
        file<<name;
        file.close();
    }
    else if(argc == 1)
    {
        fstream file;
        file.open("Name.txt",ios::in);
        if(!file)      //file doesnt exists
        {
            cout<<"Sorry, I dont know your name";
        }
        else
        {   
            cout<<"Hello "; 
            while(!file.eof())
            {
                file>>name;      //storing file data in name variable
                cout<<name;
            }
        }
        file.close();
    }
}