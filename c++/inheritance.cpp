#include<iostream>
#include"inheritance.h"
Mentor: : Mentor(int id, string n, string sub_taought, string rank):EmertxeMember(id, n, a)
{
    this->sub_taught;
    this->rank=rank;
}
Candidate: : Candidate(int id, string n, string a, string course, int year):EmertxeMember(id, n, a)
{
    this->course=course;
    this->year=year;
}
void EmertxeMember: :display_profile(void)
{
    cout<<"ID: "<< id << endl;
    cout<<"Name: "<< name << endl;
    cout<<"Address: "<< address << endl;
}
void Mentor::display_profile(void) // Override the base class definition
{
cout << "ID: " << id << endl;
cout << "Name: " << name << endl;
cout << "Address: " << address << endl;
cout << "Subject Taught: " << sub_taught << endl;
cout << "Rank: " << rank << endl;
}
void Candidate::display_profile(void) // Override the base class definition
{
cout << "ID: " << id << endl;
cout << "Name: " << name << endl;
cout << "Address: " << address << endl;
cout << "Course: " << course << endl;
cout << "Year: " << year << endl;
}