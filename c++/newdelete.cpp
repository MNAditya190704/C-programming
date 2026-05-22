#include <iostream>
#include <cstring>

using namespace std;

class Employee
{
    public:
    int id;
    char *name;
    Employee()
    {
        id = 0;
        name = new char[10];
    }
    ~Employee()
    {
        delete name;
    }
};

int main()
{
    Employee emp1;
    cout << "The ID is " << emp1.id << endl;
    strcpy(emp1.name, "Tingu");
    cout << "The Name is " << emp1.name << endl;
    return 0;
}