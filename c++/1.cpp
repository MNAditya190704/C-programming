#include<iostream>
using namespace std;
class Employee
{
    public :
    int id;
    string name;
    string address;
    void get_data()
    {
        cout << "Enter ID :";
        cin >> id;
    
    
        cout << "Enter name : ";
        cin.ignore();
        getline(cin, name);
    
    
    
        cout << "Enter address : ";
        cin.ignore();
        getline(cin, address);
    }
    void print_data()
    {
        cout << id << endl;
        cout << name << endl;
        cout << address << endl;
    }
};
int main()
{
    Employee emp1;
    emp1.get_data();
    emp1.print_data();
    //emp1.get_address();

    cout << emp1.id << endl;
    cout << emp1.name << endl;
    cout << emp1.address << endl;
    return 0;

}