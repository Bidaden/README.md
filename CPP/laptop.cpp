#include <iostream >
using namespace std;

class Laptop
{
private:
    string brand;
    string model;
    int ram;
    int storage;

public:
    Laptop(string Brand, string Model, int RAM, int Storage)
    {
        brand = Brand;
        model = Model;
        ram = RAM;
        storage = Storage;
    }
    void displayInfo()
    {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "RAM: " << ram << " GB" << endl;
        cout << "Storage: " << storage << " GB" << endl;
    }

    void checkRAM(int requiredRAM)
    {
        if (ram >= requiredRAM)
        {
            cout << "This laptop has enough RAM to run the software." << endl;
        }
        else
        {
            cout << "This laptop does not have enough RAM to run the software.";
        }
    }
};

int main()
{
    Laptop laptop1("Dell", "XPS13", 8, 256);

    laptop1.displayInfo();

    // ểKim tra xem laptop có đủ RAM để chạy 16GB RAM
    laptop1.checkRAM(16);

    return 0;
}