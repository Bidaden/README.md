#include <iostream>
using namespace std;

class Course
{
private:
    string courseName;
    string courseCode;
    int credits;
    string instructorName; // Thuoc tinh moi: Ten giang vien
public:
    Course(string name, string corsecode, int credit, string instructorname)
    {
        courseName = name;
        courseCode = corsecode;
        credits = credit;
        instructorName = instructorname;
    }
    void displayInfo()
    {
        cout << "Course Name: " << courseName << endl;
        cout << "Course Code: " << courseCode << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor: " << instructorName << endl; // In ra ten giang vien
    }

    bool isHighCredit()
    {
        return credits > 3;
    }

    bool isLabRequired()
    {
        return credits > 4; // Khoa hoc co hon 4 tin chi thi can phong thi nghiem
    }
};

int main()
{
    Course course1("OOP", "2025", 4, "Phan Anh Vu");

    course1.displayInfo();

    if (course1.isHighCredit())
    {
        cout << "This is a high credit course." << endl;
    }
    else
    {
        cout << "This is not a high credit course." << endl;
    }

    if (course1.isLabRequired())
    {
        cout << "This course requires a lab." << endl;
    }
    else
    {
        cout << "This course does not require a lab." << endl;
    }

    return 0;
}
