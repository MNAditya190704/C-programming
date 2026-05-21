#include <iostream>
#include <cstring>
using namespace std;
class Employee
{
public:
int id;
char *name;
Employee(int x, char *s);
};
Employee::Employee(int x, char *s)
{
id = x;
name = (char *)malloc(sizeof(char)*10);
strcpy(name, s);
}
int main()
{
Employee e(10, (char *) "Tingu");
cout << "The ID is " << e.id << endl;
cout << "The Name is " << e.name << endl;
return 0;
}