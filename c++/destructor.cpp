#include <iostream>
#include <string> // Switched to modern C++ strings
using namespace std;

class Employee
{
public:
    int id;
    string name; // No manual allocation or freeing needed

    // Constructor 1: Initialize name to empty string
    Employee(int i) : id(i), name("") {}

    // Constructor 2: Initialize name with given string
    Employee(int i, string s) : id(i), name(s) {}

    // Destructor: No longer needs to manually free anything
    ~Employee() {}
};

int main()
{
    Employee e1(10);
    Employee e2(11, "Tingu"); // No ugly typecasting needed

    cout << "ID: " << e1.id << endl;
    cout << "Name: " << e1.name << endl; // Safely prints empty string
    cout << "ID: " << e2.id << endl;
    cout << "Name: " << e2.name << endl;

    return 0;
}