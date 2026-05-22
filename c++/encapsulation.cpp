#include <iostream>

using namespace std;

class Employee
{
    int id; // This member can be accessed with only get and set function since its
    // private, hence we can say its encapsulated

    public:
    int get_id(void) 
    {   // Getter
        return id;
    }

    void set_id(int id) 
    {   // Setter
        this->id = id;
    }
};

int main()
{
    Employee e;
    e.set_id(10);
    cout << "The ID is " << e.get_id() << endl;
    return 0;
}