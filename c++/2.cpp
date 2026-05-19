#include<iostream>
#include<string.h>
using namespace std;
class Employee
{
    private:
    int id;
    public:
    string name, address;
    void get_data()
    {
        cout<< "Enter ID No: "; cin >> id;
        cin.ignore();
        cout<< "Enter name No: "; cin >> name;
        cout<< "Enter address No: "; cin >> address;
    }
    void print_data()
    {
        cout<< "the id is : " << id << endl;
        cout<< "the name is : " << name << endl;
        cout<< "the address is : " << address << endl;
    }
};
int main()
{
    Employee emp1;
    emp1.name="mn";
    return 0;
}