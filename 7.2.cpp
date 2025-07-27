// 7.2.cpp

// Create a class Person and two derived classes Employee and Student, inherited from class Person. Now create a class Manager which is derived from two base classes Employee and Student. Show the use of the virtual base class.

#include <iostream>
using namespace std;

class Person
{
protected:
    string name;

public:
    void inputDetails()
    {
        cout << "\nEnter name : ";
        cin >> name;
    }
    void showName()
    {
        cout << "\nName : " << name << endl;
    }
};

class Student : virtual public Person
{
private:
    float gpa;

public:
    void showDetails()
    {
        showName();
        cout << "GPA : " << gpa << endl;
    }

    void inputDetails()
    {
        Person::inputDetails();
        cout << "Enter GPA: ";
        cin >> gpa;
    }
};

class Employee : virtual public Person
{
private:
    float salary;

public:
    void showDetails()
    {
        showName();
        cout << "Salary : " << salary << endl;
    }

    void inputDetails()
    {
        Person::inputDetails();
        cout << "Enter Salary: ";
        cin >> salary;
    }
};

class Manager : virtual public Student, virtual public Employee
{
public:
    void showDetails()
    {

        showName();
        cout << "Post : Manager" << endl;
    }

    void inputDetails()
    {
        Person::inputDetails();
    }
};

int main(void)
{
    Student s;
    Employee e;
    Manager m;
    m.inputDetails();
    m.showDetails();
    return 0;
}