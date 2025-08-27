#include <iostream >
using namespace std;

class Rectangle
{
private:
    int width;
    int height;

public:
    Rectangle(int Width, int Height)
    {
        width = Width;
        height = Height;
    }
    int calculateArea()
    {
        return width * height;
    }
};

int main()
{
    Rectangle rect1(2000, 20);

    cout << "Area: " << rect1.calculateArea() << endl;

    return 0;
}