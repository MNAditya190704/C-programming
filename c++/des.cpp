// #include<iostream>
// #include<cstring>
// using namespace std;
// class Employee
// {
//     public:
//     Employee()
//     {
//         cout<<"constructor is called\n";
//     }
//     ~Employee()
//     {
//         cout<<"destructor is called\n";
//     }
// };

// void my_fun(Employee e)
// {
//     cout<<"aditya\n";
// }
// int main()
// {
//     Employee emp1, emp2;
//     my_fun(emp1);
//     return 0;
// }

#include<iostream>
#include<cstring>
using namespace std;
class Employee
{
    public:
    Employee(const Employee &r)
    {
        cout<<"constructor is called\n";
    }
    Employee()
    {
        cout<<"constructor is called\n";
    }
    ~Employee()
    {
        cout<<"destructor is called\n";
    }
};

void my_fun(Employee e)
{
    cout<<"aditya\n";
}
int main()
{
    Employee emp1, emp2;
    my_fun(emp1);
    return 0;
}