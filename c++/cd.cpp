#include<iostream>
using namespace std;
class Employee
{
    public:
    int id;
    string name;
    string address;
    Employee()
    {
        cout<<"Constructor is called\n";
        id=111;
        name="Aditya";
        address="bengaluru";
    }
};
int main()
{
    Employee emp1;
    cout<<emp1.id<<endl;
    cout<<emp1.name<<endl;
    cout<<emp1.address<<endl;
    return 0;
}