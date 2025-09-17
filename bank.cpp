#include <bits/stdc++.h>
using namespace std;

class Transaction
{
private:
    double amount;
    string type; // "Deposit", "Withdraw", "Transfer"
    string date;

public:
    Transaction(double _amount, string _type, string _date)
        : amount(_amount), type(_type), date(_date) {}

    void display() const
    {
        cout << "Transaction: " << type
             << " | Amount: " << amount
             << " | Date: " << date << endl;
    }

    double getAmount() const { return amount; }
    string getType() const { return type; }
};

class Account
{
protected:
    string accountNumber;
    double balance;
    string ownerName;
    vector<Transaction> history;

public:
    Account(string accNo, string owner, double initialBalance = 0.0)
        : accountNumber(accNo), ownerName(owner), balance(initialBalance) {}

    virtual void deposit(double amount, string date)
    {
        balance += amount;
        history.emplace_back(amount, "Deposit", date);
    }

    virtual bool withdraw(double amount, string date)
    {
        if (amount > balance)
        {
            cout << "❌ Insufficient funds in account " << accountNumber << endl;
            return false;
        }
        balance -= amount;
        history.emplace_back(amount, "Withdraw", date);
        return true;
    }

    double getBalance() const { return balance; }
    string getAccountNumber() const { return accountNumber; }

    virtual void displayInfo() const
    {
        cout << "Account: " << accountNumber
             << " | Owner: " << ownerName
             << " | Balance: " << balance << endl;
    }

    // Operator overloading: add transaction
    Account &operator+=(const Transaction &t)
    {
        if (t.getType() == "Deposit")
            balance += t.getAmount();
        else if (t.getType() == "Withdraw" && t.getAmount() <= balance)
            balance -= t.getAmount();

        history.push_back(t);
        return *this;
    }

    // Compare accounts by balance
    bool operator==(const Account &other) const
    {
        return balance == other.balance;
    }
};

class SavingsAccount : public Account
{
private:
    double interestRate;

public:
    SavingsAccount(string accNo, string owner, double initialBalance, double rate)
        : Account(accNo, owner, initialBalance), interestRate(rate) {}

    void applyInterest(string date)
    {
        double interest = balance * interestRate;
        balance += interest;
        history.emplace_back(interest, "Interest", date);
    }

    // Override withdraw: hạn chế rút quá 50% số dư
    bool withdraw(double amount, string date) override
    {
        if (amount > balance * 0.5)
        {
            cout << "❌ Withdrawal exceeds 50% of balance in savings account!" << endl;
            return false;
        }
        return Account::withdraw(amount, date);
    }

    void displayInfo() const override
    {
        cout << "Savings Account: " << accountNumber
             << " | Owner: " << ownerName
             << " | Balance: " << balance
             << " | Interest Rate: " << interestRate * 100 << "%" << endl;
    }
};

class Customer
{
private:
    string name;
    string ID;
    vector<Account *> accounts;

public:
    Customer(string _name, string _ID) : name(_name), ID(_ID) {}

    void addAccount(Account *acc)
    {
        accounts.push_back(acc);
    }

    void displayAccounts() const
    {
        cout << "Customer: " << name << " (" << ID << ")\nAccounts:\n";
        for (auto acc : accounts)
        {
            acc->displayInfo();
        }
    }

    double getTotalBalance() const
    {
        double total = 0;
        for (auto acc : accounts)
        {
            total += acc->getBalance();
        }
        return total;
    }
};

// Demo main
int main()
{
    Customer c1("Alice", "C001");

    Account *acc1 = new Account("A1001", "Alice", 1000);
    SavingsAccount *acc2 = new SavingsAccount("S2001", "Alice", 2000, 0.05);

    c1.addAccount(acc1);
    c1.addAccount(acc2);

    acc1->deposit(500, "2025-09-17");
    acc1->withdraw(200, "2025-09-17");

    acc2->applyInterest("2025-09-17");
    acc2->withdraw(1200, "2025-09-17"); // vượt 50% => bị từ chối

    c1.displayAccounts();
    cout << "Total Balance: " << c1.getTotalBalance() << endl;

    delete acc1;
    delete acc2;
    return 0;
}
