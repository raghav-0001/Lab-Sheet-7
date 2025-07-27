// 7.4.cpp

// Create a polymorphic class Vehicle and create other derived classes Bus, Car, and Bike from Vehicle. Illustrate RTTI by the use of dynamic_cast and typeid operators in this program.

#include <iostream>
#include <typeinfo>
using namespace std;

class Vehicle
{
public:
    virtual void showType()
    {
        cout << "This is a Vehicle." << endl;
    }
};

class Bus : public Vehicle
{
public:
    void showType() override
    {
        cout << "This is a Bus." << endl;
    }
};

class Car : public Vehicle
{
public:
    void showType() override
    {
        cout << "This is a Car." << endl;
    }
};

class Bike : public Vehicle
{
public:
    void showType() override
    {
        cout << "This is a Bike." << endl;
    }
};

int main()
{
    Vehicle *v;

    Bus b;
    Car c;
    Bike bi;

    // Using typeid
    v = &b;
    cout << endl
         << "Object type: " << typeid(*v).name() << endl;

    v = &c;
    cout << "Object type: " << typeid(*v).name() << endl;

    v = &bi;
    cout << "Object type: " << typeid(*v).name() << endl;

    // Using dynamic_cast
    v = &c;
    Car *carPtr = dynamic_cast<Car *>(v);
    if (carPtr)
        cout << "\ndynamic_cast to Car* successful." << endl;
    else
        cout << "dynamic_cast to Car* failed." << endl;

    Bike *bikePtr = dynamic_cast<Bike *>(v);
    if (bikePtr)
        cout << "dynamic_cast to Bike* successful." << endl;
    else
        cout << "dynamic_cast to Bike* failed.\n"
             << endl;

    return 0;
}
