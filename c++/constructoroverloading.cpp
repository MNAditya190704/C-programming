#include <iostream>
using namespace std;

class construct
{
    public:
    float area;
    
    // Default constructor
    construct()
    {
        cout << "Constructor with zero args\n";
        area = 0;
    }
    
    // Parameterized constructor
    construct(int a, int b)
    {
        cout << "Constructor with two args\n";
        area = a * b;
    }
    
    void disp()
    {
        cout << area << endl;
    }
};

int main()
{
    construct o;
    construct o2(10, 20);
    o.disp();
    o2.disp();
    return 0; 
}