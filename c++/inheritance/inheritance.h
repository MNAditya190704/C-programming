#ifndef EXAMPLE_013_H
#define EXAMPLE_013_H
#include <iostream>
#include <cstring>

using namespace std;

class EmertxeMember
{
    protected:
    int id;
    string name;
    string address;

    public:
    EmertxeMember(int id, string n, string a)
    {
        this->id = id;
        name = n;
        address = a;
    }

    void display_profile(void);
};

class Candidate : public EmertxeMember
{
    // Note have not considered all cases said in the previous slide
    string course;
    int year;
    public:
    Candidate(int id, string n, string a, string course, int year);
    void display_profile(void);
};

class Mentor : public EmertxeMember
{
    // Note have not considered all cases said in the previous slide
    string sub_taught;
    string rank;

    public:
    Mentor(int id, string n, string a, string sub_taught, string year);
    void display_profile(void);
};

#endif