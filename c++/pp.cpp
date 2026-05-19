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
//     sEmployee emp1;
//     cEmployee emp2;
//     emp1.name="tingu";
//     emp2.name="mingu";
// }
#include<iostream>
using namespace std;
struct sEmployee
{
    int id;
    string name;
    string address;
};
class cEmployee
{
    int id;
    public:
    string name;
    string address;
};
int main()
{
    sEmployee emp1;
    cEmployee emp2;
    emp1.name="tingu";
    emp2.name="mingu";
}