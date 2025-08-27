#include <iostream>
using namespace std;

class Account
{
private:
    string accountNumber;
    string ownerName; // Thuộc tính mới: tên chủ tài khoản
    double balance;

public:
    Account(string AccNum, string Ownername, double Balance)
    {
        accountNumber = AccNum;
        ownerName = Ownername;
        balance = Balance;
    }

    string getAccountnumber()
    {
        return accountNumber;
    }
    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(double amount)
    {
        double minBalance = 100000; // số dư tối thiểu
        if (amount > balance - minBalance)
        {
            cout << "Withdrawal denied! Account must keep at least " << minBalance << " VND." << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrew: " << amount << endl;
        }
    }

    void displayBalance()
    {
        cout << "Owner: " << ownerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current balance: " << balance << " VND" << endl;
    }
};

int main()
{
    Account acc1("123456789", "Phan Anh Vu", 36363636363363636363.36);

    acc1.displayBalance();
    acc1.deposit(200000);
    acc1.displayBalance();
    acc1.withdraw(100000);
    acc1.displayBalance();
    acc1.withdraw(700000); // thử rút quá mức (vi phạm số dư tối thiểu)
    acc1.displayBalance();

    return 0;
}
