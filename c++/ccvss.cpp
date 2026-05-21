#include <iostream>
#include <string> // Fixed: Added missing header for strings

using namespace std;

struct sEmployee
{
    // Struct members are PUBLIC by default
    int id;
    string name; // Fixed: Removed 'private' so it can be accessed in main()
    string address;
};

class cEmployee
{
    // Class members are PRIVATE by default
    int id; 
public: 
    // Public members can be accessed anywhere
    string name;
    string address;
};

int main()
{
    sEmployee emp1;
    cEmployee emp2;

    // Allowed: sEmployee members are now public
    emp1.name = "Tingu";

    // Allowed: cEmployee.name is explicitly public
    emp2.name = "Pingu";

    cout << emp1.name << " and " << emp2.name << endl;
    return 0;
}