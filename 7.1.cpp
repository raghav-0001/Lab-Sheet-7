// 7.1.cpp

// Write a program to create a class shape with functions to find the area of the shapes and display the names of the shapes and other essential components of the class. Create derived classes circle, rectangle, and trapezoid each having overriding functions area() and display(). Write a suitable program to illustrate virtual functions and virtual destructors.

#include <iostream>
using namespace std;
const double pi = 3.14;

class shape
{
protected:
    string name;
    float area;

public:
    ~shape()
    {
        cout << "Shape destroyed" << endl << endl;
    }
    virtual void Area() = 0; // Pure virtual function to enforce derived classes to implement this method

    virtual void display()
    {
        cout << "Name : " << name << endl;
        cout << "Area : " << area << endl;
    }
};

class circle : public shape
{
public:
    circle()
    {
        name = "Circle";
    }
    void Area() override
    {
        float r;
        cout << "\nCalculating area of Circle" << endl;
        cout << "Enter radius : ";
        cin >> r;
        area = pi * r * r;
    }

    void display()
    {
        Area();
        cout << "Overridden by circle" << endl;
        shape::display();
    }
    ~circle()
    {
        cout << "Circle destroyed" << endl;
    }
};

class rectangle : public shape
{
public:
    rectangle()
    {
        name = "Rectangle";
    }
    void Area() override
    {
        float l, b;
        cout << "\nCalculating area of Rectangle" << endl;
        cout << "Enter length and breadth : ";
        cin >> l;
        cin >> b;
        area = l * b;
    }

    void display()
    {
        Area();
        cout << "Overridden by rectangle" << endl;
        shape::display();
    }
    ~rectangle()
    {
        cout << "Rectangle destroyed" << endl;
    }
};

class trapezoid : public shape
{
public:
    trapezoid()
    {
        name = "Trapezoid";
    }

    void Area() override
    {

        float a, b, h;
        cout << "\nCalculating area of Trapezoid" << endl;
        cout << "Enter values of a, b and h : ";
        cin >> a;
        cin >> b;
        cin >> h;
        area = 0.5 * (a + b) * h;
    }

    void display()
    {
        Area();
        cout << "Overridden by Trapeziod" << endl;
        shape::display();
    }
    ~trapezoid()
    {
        cout << "\nTrapezoid destroyed" << endl;
    }
};

int main(void)
{
    circle c;
    rectangle r;
    trapezoid t;
    shape *s[3];
    s[0] = &c, s[1] = &r, s[2] = &t;

    s[0]->display();
    s[1]->display();
    s[2]->display();
    return 0;
}