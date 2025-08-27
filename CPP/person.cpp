#include <iostream >
using namespace std;

class Person
{
private:
    string name;
    int age;
    string address;

public:
    Person(string Name, int Age, string Address)
    {
        name = Name;
        age = Age;
        address = Address;
    }
    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
    }

    bool isAdult()
    {
        return age >= 18;
    }
};

int main()
{
    Person person1("Phan_Anh_Biden", 19, "Hem_48_Bui_Thi_Xuan");

    person1.displayInfo();

    if (person1.isAdult())
    {
        cout << "This person is an adult." << endl;
    }
    else
    {
        cout << "This person is not an adult." << endl;
    }

    return 0;
}