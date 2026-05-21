#include <iostream>
using namespace std;
class Employee
{
private:
// Members
int id;
string name, address;
public:
// Methods
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
emp1.get_data();
emp1.print_data();
return 0;
}