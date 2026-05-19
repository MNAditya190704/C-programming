// #include<iostream>
// #include<string.h>
// using namespace std;
// class Employee
// {
//     public:
//     int id;
//     char *name;
//     Employee()
//     {
//         cout << " constructor is called";
//         id=111;
//         name=(char *)malloc(10);
//     }
// };
// int main()
// {
//     Employee emp1;
//     cout<<emp1.id<<endl;
//     strcpy(emp1.name,"Aditya");
//     cout<< emp1.name <<endl;
//     return 0;
// }


#include<iostream>
#include<string.h>
using namespace std;
class Employee
{
    public:
    int id;
    char *name;
    Employee(int x, char *str)
    {
        cout << " constructor is called";
        id=x;
        name=(char *)malloc(10);
        strcpy(name,str);
    }
};
int main()
{
    Employee emp1(123, (char *)"aditya");
    cout<<emp1.id<<endl;
    cout<< emp1.name <<endl;
    return 0;
}