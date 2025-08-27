#include <iostream >
using namespace std;

class Book
{
private:
    string title;
    string author;

public:
    Book(string Title, string Author)
    {
        title = Title;
        author = Author;
    }
    void displayInfo()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
    }
};

int main()
{
    Book book1("Dai Viet Su Ky Toan Thu", "Anh Vu Phan");
    book1.displayInfo();

    return 0;
}