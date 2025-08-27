#include <iostream>
#include <cmath>
using namespace std;

class Circle
{
protected:
    double radius;
    string Color;

public:
    Circle(double r = 0, string c = " chua xac dinh")
    {
        radius = r;
        Color = c;
    }

    double circumference()
    {
        return 2 * M_PI * radius;
    }

    double area()
    {
        return M_PI * radius * radius;
    }
};

class CheckIfPositive : public Circle
{
public:
    CheckIfPositive(double r, string c) : Circle(r, c) {}

    void Display_Result()
    {
        if (radius > 0)
        {
            cout << "Ban kinh hop le (so duong)" << endl;
            cout << "Chu vi hinh tron: " << circumference() << " don vi" << endl;
            cout << "Dien tich hinh tron: " << area() << " don vi vuong" << endl;
        }
        else
        {
            cout << "Ban kinh khong hop le (phai la so duong)" << endl;
        }
    }
    void Display_Color()
    {
        cout << "Hinh tron co mau: " << Color << endl;
    }
};

int main()
{
    double r;
    string c;

    cout << "Nhap ban kinh hinh tron: ";
    cin >> r;

    cout << "Nhap mau cua hinh tron: ";
    cin >> c;

    CheckIfPositive circle1(r, c);
    circle1.Display_Result();
    circle1.Display_Color();

    return 0;
}
