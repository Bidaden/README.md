#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    double grade;
    string phoneNumber; // Thuộc tính mới: số điện thoại
    string address;     // Thêm thuộc tính địa chỉ
public:
    Student(string Name, double Grade, string phoneNum, string Address)
    {
        name = Name;
        grade = Grade;
        phoneNumber = phoneNum;
        address = Address;
    }
    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Grade: " << grade << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Address: " << address << endl;
    }

    // Cập nhật địa chỉ mới
    void move(string newAddress)
    {
        address = newAddress;
    }

    // Lời chào
    void greet()
    {
        cout << "Hello, my name is " << name << endl;
    }
};

int main()
{
    Student student1("Biden", 20.0, "0384686440", "hem_48_Bui_Thi_Xuan");

    student1.displayInfo();

    cout << "\n--- Sau khi chuyển nhà ---" << endl;
    student1.move("456 New Avenue"); // cập nhật địa chỉ
    student1.displayInfo();

    cout << "\n--- Lời chào ---" << endl;
    student1.greet();

    return 0;
}
