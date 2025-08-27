#include <iostream >
using namespace std;

class Employee
{
private:
    string name;
    double salary;

public:
    Employee(string Name, double Salary)
    {
        name = Name;
        salary = Salary;
    }
    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main()
{
    Employee employee1("Alice", 50000);
    employee1.displayInfo();

    return 0;
}
