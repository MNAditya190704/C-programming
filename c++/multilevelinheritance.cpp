#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

class A
{
    public:
    A()
    {
        cout<<"A's Constructor\n";
    }
};

class B: public A
{
    public:
    B()
    {
        cout<<"B's Constructor\n";
    }
};

class C: public B
{
    public:
    C()
    {
        cout<<"C's Constructor\n";
    }
};

int main()
{
    A a;
    B b;
    C c;
}