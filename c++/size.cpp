// #include<iostream>
// using namespace std;
// struct sEmployee
// {
//     int id;
//     string name;
//     string address;
// };
// class cEmployee
// {
//     int id;
//     string name;
//     string address;
// };
// int main()
// {
//     cout << sizeof(sEmployee) << endl;
//     cout << sizeof(cEmployee) << endl;
//     cout << sizeof(string) << endl;
//     return 0;
// }

//size of empty structure or class is 1 byte, however in c it is 0

#include<iostream>
using namespace std;
struct sEmployee
{
};
class cEmployee
{
};
int main()
{
    cout << sizeof(sEmployee) << endl;
    cout << sizeof(cEmployee) << endl;
    return 0;
}
