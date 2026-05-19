#include<iostream>
using namespace std;
class A
{
public:
A()
{
 cout<<"A's constructor" ;
}
};
class B: public A
{
public:
B()
{
 cout<<"B's constructor" ;
}
};
class C: public B
{
public:
C()
{
 cout<<"C's constructor" ;
}
};
int main()
{
    A a;
    B b;
    C c;
}