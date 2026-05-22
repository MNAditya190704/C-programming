#include <iostream>
#include <cstring>
#include<cstdlib>

using namespace std;

class Employee
{
    public:
    int id;
    char *name;
    Employee(int id);
    Employee(int id, const char *s);
    ~Employee(void);
};
Employee::Employee(int i, const char *s)
{
    id = i;
    name = (char *)malloc(sizeof(char)*10);
    if(name != NULL)
    {
        strcpy(name, s);
    }
}
Employee::Employee(int i)
{
    id = i;
    name=NULL;
}
Employee::~Employee(void)
{
    free(name);
}
int main()
{
    Employee e1(10), e2(11, (char *) "Tingu");
    cout << "ID: " << e1.id << endl;
    cout << "Name: " << (e1.name ? e1.name : "No Name") << endl; 
    
    cout << "ID: " << e2.id << endl;
    cout << "Name: " << (e2.name ? e2.name : "No Name") << endl;

    return 0;
}