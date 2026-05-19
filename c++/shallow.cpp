#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
public:
    int id;
    char *name;

    Employee(int i, const char* n)
    {
        cout << "Parameterized constructor is called\n";
        id = i;
        name = new char[strlen(n) + 1]; 
        strcpy(name, n);
    }

    // Copy constructor
    Employee(const Employee &r)
    {
        cout << "Copy constructor is called\n";
        id = r.id;
        name = new char[strlen(r.name) + 1];
        strcpy(name, r.name);
    }

    ~Employee()
    {
        cout << "Destructor is called\n";
        free(name); 
    }
};

int main()
{
    Employee emp1(123, (char *)"aditya"); 
    Employee emp2 = emp1; // Calls the copy constructor
    
    cout << emp1.id << endl;
    cout << emp1.name << endl << endl;
    
    return 0;
}
