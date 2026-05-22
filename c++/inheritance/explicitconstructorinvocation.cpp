#include <iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

class Polygon 
{
    protected:
    int width, height;
    
    public:
    Polygon(int a, int b)
    {
        width=a; height=b;
    }

    display_value()
    {
        cout<<width<<" "<<height<<" "<<endl;
    }
};

int main()
{
    Polygon p = Polygon(4,40);
    p.display_value();
    return 0;
}