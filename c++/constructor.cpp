#include<iostream>
#include<string.h>
using namespace std;
class Employee
{
    public:
    int id;
    char *name;
    Employee()
    {
        cout<<"default Constructor\n";
        id=0;
        name=(char*)malloc(10);
        strcpy(name, "No name");
    }
    
    Employee(int x, char *str)
    {
        cout<<"constructor with 1 arg\n";
        id=x;
        name=(char *)malloc(10);
        strcpy(name, str);
    }
};

int main()
{
    Employee emp1(123, (char*)"aditya");
    Employee emp2, emp3;
    cout<<emp1.id<<endl;
    cout<<emp1.name<<endl<<endl;
    cout<<emp2.id<<endl;
    cout<<emp2.name<<endl<<endl;
    cout<<emp3.id<<endl;
    cout<<emp3.name<<endl<<endl;
}