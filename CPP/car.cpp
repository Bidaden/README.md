#include <iostream >
using namespace std;
class Car
{
private:
    string brand;
    int year;

public:
    Car(string Brand, int Year)
    {
        brand = Brand;
        year = Year;
    }

    void displayInfo()
    {
        cout << "Brand: " << brand << endl;
        cout << "Year: " << year << endl;
    }
};
int main()
{
    Car car1("Mercedes", 3636);

    car1.displayInfo();
}