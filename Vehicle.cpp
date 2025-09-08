#include <iostream>
#include <string>
using namespace std;

// Định nghĩa lớp Vehicle
class Vehicle {
private:
    string type;       // Kiểu xe (Car, Truck, Motorcycle, ...)
    int maxSpeed;      // Tốc độ tối đa (km/h)
    string fuelType;   // Loại nhiên liệu (Gasoline, Diesel, ...)

public:
    // Hàm khởi tạo (constructor)
    Vehicle(string t, int speed, string fuel) {
        type = t;
        maxSpeed = speed;
        fuelType = fuel;
    }

    // Phương thức mô phỏng xe tăng tốc
    void accelerate() {
        cout << "Xe " << type << " dang tang toc den " 
             << maxSpeed << " km/h." << endl;
    }

    // Getter cho type
    string getType() {
        return type;
    }

    // Getter cho maxSpeed
    int getMaxSpeed() {
        return maxSpeed;
    }

    // Getter cho fuelType
    string getFuelType() {
        return fuelType;
    }

    // Hiển thị thông tin chi tiết về xe
    void displayInfo() {
        cout << "Loai xe: " << type 
             << ", Toc do toi da: " << maxSpeed 
             << " km/h, Nhien lieu: " << fuelType << endl;
    }
};

int main() {
    // Tạo các đối tượng Vehicle
    Vehicle car("Car", 200, "Gasoline");
    Vehicle truck("Truck", 150, "Diesel");
    Vehicle motorcycle("Motorcycle", 180, "Gasoline");

    // Gọi phương thức accelerate()
    car.accelerate();
    truck.accelerate();
    motorcycle.accelerate();

    // In thông tin bằng getter
    cout << "Xe: " << car.getType() << ", Toc do: " << car.getMaxSpeed() << " km/h" << endl;
    cout << "Xe: " << truck.getType() << ", Toc do: " << truck.getMaxSpeed() << " km/h" << endl;
    cout << "Xe: " << motorcycle.getType() << ", Toc do: " << motorcycle.getMaxSpeed() << " km/h" << endl;

    // Cho phép người dùng nhập thông tin xe mới
    string userType, userFuel;
    int userSpeed;
    cout << "\nNhap loai xe: ";
    cin >> userType;
    cout << "Nhap toc do toi da: ";
    cin >> userSpeed;
    cout << "Nhap loai nhien lieu: ";
    cin >> userFuel;

    // Tạo đối tượng động từ thông tin người dùng
    Vehicle userVehicle(userType, userSpeed, userFuel);
    userVehicle.accelerate();
    userVehicle.displayInfo();

    return 0;
}