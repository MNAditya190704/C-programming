#include <iostream>
#include <cstring>

using namespace std;

class Employee
{
    private: // Abstracted the members
    int id;
    char *name;
    public:
    Employee(int id, char *s);
    ~Employee(void);
    int get_id(void);
    char *get_name(void);
};

int Employee::get_id(void)
{
    return id;
}

char *Employee::get_name(void)
{
    return name;
}

Employee::Employee(int i, char *s)
{
    id = i;
    name = new char [10];
    strcpy(name, s);
}

Employee::~Employee(void)
{
    delete name;
}

int main()
{
    Employee e1(11, (char *) "Tingu");
    // Cannot access the members directly
    // This, we had seen in the initial
    // examples, Please refer 002_example.cpp
    cout << "ID: " << e1.get_id() << endl;
    cout << "Name: " << e1.get_name() << endl;
    return 0;
}