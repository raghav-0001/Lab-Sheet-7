// 7.3.cpp

// Write a program with an abstract class Student and create derive classes Engineering, Medicine and Science from base class Student. Create the objects of the derived classes and process them and access them using an array of pointers of type base class Student.

#include <iostream>
using namespace std;

class Student
{
protected:
    int studentNum;

public:
    virtual void showField() = 0;
};

class Engineering : public Student
{
public:
    void showField()
    {
        cout << "\nEngineering" << endl;
    }
};

class Medicine : public Student
{
public:
    void showField()
    {
        cout << "Medicine" << endl;
    }
};

class Science : public Student
{
public:
    void showField()
    {
        cout << "Science\n"
             << endl;
    }
};

int main(void)
{
    Student *s[3];
    Engineering e;
    Medicine m;
    Science sc;
    s[0] = &e;
    s[1] = &m;
    s[2] = &sc;
    for (int i = 0; i < 3; i++)
    {
        s[i]->showField();
    }
    return 0;
}