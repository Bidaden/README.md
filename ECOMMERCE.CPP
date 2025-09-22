#include <iostream>
#include <string>
#include <vector>
using namespace std;

// =============================
// Interface (lop truu tuong)
// =============================
class Discountable
{
public:
    virtual double applyDiscount(double rate) = 0; // ap dung giam gia
    virtual ~Discountable() {}
};

// =============================
// Lop co so Product
// =============================
class Product : public Discountable
{
protected:
    int id;
    string name;
    double price;
    int stock;

public:
    Product(int i, string n, double p, int s)
        : id(i), name(n), price(p), stock(s) {}

    int getId() const { return id; }
    string getName() const { return name; }
    double getPrice() const { return price; }
    int getStock() const { return stock; }

    void updateStock(int qty)
    {
        stock -= qty;
        if (stock < 0)
            stock = 0;
    }

    // toan tu so sanh ==
    bool operator==(const Product &other) const
    {
        return id == other.id;
    }

    // ham ao hien thi thong tin san pham
    virtual void display() const
    {
        cout << "ID: " << id << ", Name: " << name
             << ", Price: " << price << ", Stock: " << stock << endl;
    }

    // ap dung giam gia
    double applyDiscount(double rate) override
    {
        return price * (1 - rate);
    }

    virtual ~Product() {}
};

// =============================
// Lop ke thua: Electronics
// =============================
class Electronics : public Product
{
private:
    int warranty; // bao hanh (thang)
public:
    Electronics(int i, string n, double p, int s, int w)
        : Product(i, n, p, s), warranty(w) {}

    void display() const override
    {
        cout << "[Electronics] ";
        Product::display();
        cout << "Warranty: " << warranty << " months" << endl;
    }
};

// =============================
// Lop ke thua: Clothing
// =============================
class Clothing : public Product
{
private:
    string size;
    string color;

public:
    Clothing(int i, string n, double p, int s, string sz, string c)
        : Product(i, n, p, s), size(sz), color(c) {}

    void display() const override
    {
        cout << "[Clothing] ";
        Product::display();
        cout << "Size: " << size << ", Color: " << color << endl;
    }
};

// =============================
// Template class: InventoryList<T>
// dung de quan ly danh sach tong quat
// =============================
template <typename T>
class InventoryList
{
private:
    vector<T> items;

public:
    void addItem(T item)
    {
        items.push_back(item);
    }

    void removeItem(int index)
    {
        if (index >= 0 && index < (int)items.size())
        {
            items.erase(items.begin() + index);
        }
    }

    T *findItem(int id)
    {
        for (auto &item : items)
        {
            if (item->getId() == id)
            {
                return item;
            }
        }
        return nullptr;
    }

    vector<T> &getItems()
    {
        return items;
    }
};

// =============================
// Lop ShoppingCart
// ke thua tu Discountable
// =============================
class ShoppingCart : public Discountable
{
private:
    InventoryList<Product *> cartItems; // dung template voi Product*
    double total = 0;

public:
    // toan tu += de them san pham vao gio hang
    ShoppingCart &operator+=(Product *p)
    {
        if (p->getStock() > 0)
        {
            cartItems.addItem(p);
            total += p->getPrice();
            p->updateStock(1);
        }
        else
        {
            cout << "Loi: San pham het hang!" << endl;
        }
        return *this;
    }

    void showCart()
    {
        cout << "\n=== Gio hang ===" << endl;
        for (auto item : cartItems.getItems())
        {
            item->display();
        }
        cout << "Tong tien: " << total << endl;
    }

    // ap dung giam gia
    double applyDiscount(double rate) override
    {
        total = total * (1 - rate);
        return total;
    }

    double getTotal() const { return total; }
};

// =============================
// Lop Order (don hang)
// =============================
class Order
{
private:
    int orderId;
    ShoppingCart cart;
    string customerName;

public:
    Order(int id, ShoppingCart c, string name)
        : orderId(id), cart(c), customerName(name) {}

    void confirmOrder()
    {
        cout << "Don hang #" << orderId
             << " cua " << customerName
             << " da duoc xac nhan." << endl;
    }

    void printInvoice()
    {
        cout << "\n=== Hoa don ===" << endl;
        cout << "Khach hang: " << customerName << endl;
        cout << "Ma don: " << orderId << endl;
        cout << "Tong tien: " << cart.getTotal() << endl;
    }
};

// =============================
// Ham main de test chuong trinh
// =============================
int main()
{
    // tao san pham
    Electronics *e1 = new Electronics(1, "Laptop Dell", 1500, 5, 24);
    Clothing *c1 = new Clothing(2, "Ao thun", 20, 10, "L", "Do");

    // hien thi san pham
    e1->display();
    c1->display();

    // tao gio hang va them san pham
    ShoppingCart cart;
    cart += e1;
    cart += c1;
    cart.showCart();

    // ap dung giam gia 10%
    cart.applyDiscount(0.1);
    cart.showCart();

    // tao don hang
    Order order(1001, cart, "Nguyen Van A");
    order.confirmOrder();
    order.printInvoice();

    // giai phong bo nho
    delete e1;
    delete c1;

    return 0;
}
