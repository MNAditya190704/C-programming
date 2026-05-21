#include <iostream>
using namespace std;
class Employee
{
private:
int id;
string name, address;
public:
void get_data(void)
{
cout << "Enter ID No: "; cin >> id;
cout << "Enter Name: "; cin >> name;
cout << "Enter Address: "; cin >> address;
}
void print_data(void)
{
cout << "The ID is: " << id << endl;
cout << "The Name is: " << name << endl;
cout << "The Address is: " << address << endl;
}
};
int main()
{
Employee emp1;
// Private Members
// cannot be accessed
emp1.id = 10;
emp1.name = "Tingu";
return 0;
}