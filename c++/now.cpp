#include<iostream>
using namespace std;
int main()
{
    int num1=10, num2=20;

    int &ref=num1;

    cout << num1 << " " << num2 << " " << ref << endl;
    ref=123;
    cout << num1 << " " << num2 << " " << ref << endl;
    ref=num2;
    cout << num1 << " " << num2 << " " << ref << endl;
}
