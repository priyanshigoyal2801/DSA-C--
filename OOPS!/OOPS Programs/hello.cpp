#include <iostream>
using namespace std;

class Shape
{
protected:
    const float area;

public:
    Shape(float x) : area (x) {}
    void CalculateArea()
    {
    }
};

class Circle : public Shape
{
    static int countCirc;
    // int radius;

public:
    // Circle() : area(0) {}
    Circle(float r) : Shape(r*3.14*r) {
        countCirc++;
    }

    void CalculateArea()
    {
        cout << area;
        cout << endl;
    }
    static void NumberofCircles()
    {
        cout << countCirc;
    }
    
};
int Circle ::countCirc;
int main()
{
    Circle c1[3] = {Circle(2), Circle(5), Circle(6)};
    for (int i = 0; i < 3; i++)
    {
        c1[i].CalculateArea();
        // c1[i].dispArea();
    }
    Circle::NumberofCircles();
    return 0;
}