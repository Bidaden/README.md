#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vehicle
{
protected:
    string route;
    string capacity;
    string status;

public:
    Vehicle(string _route, string _capacity, string _status) : route(_route), capacity(_capacity), status(_status) {}
    Vehicle() : route(""), capacity(""), status("") {}
    string getRoute() const { return route; }
    string getStatus() const { return status; }

    // Cho phép override
    virtual double calculateTravelTime(double distance) const
    {
        double avgSpeed = 40.0; // tốc độ mặc định
        return distance / avgSpeed;
    }

    virtual void displayInfo() const
    {
        cout << "Vehicle on route: " << route
             << " | Capacity: " << capacity
             << " | Status: " << status << endl;
    }

    virtual ~Vehicle() = default;
};

// Bus thông thường
class Bus : public Vehicle
{
protected:
    int numberofStops;

public:
    Bus(string _route, string _capacity, string _status, int _stops)
        : Vehicle(_route, _capacity, _status), numberofStops(_stops) {}

    double calculateTravelTime(double distance) const override
    {
        double avgSpeed = 40.0;
        double baseTime = distance / avgSpeed;
        return baseTime + (numberofStops * 2.0 / 60.0);
    }

    void displayInfo() const override
    {
        cout << "Bus on route: " << route
             << " | Capacity: " << capacity
             << " | Stops: " << numberofStops
             << " | Status: " << status << endl;
    }
};

// ExpressBus
class ExpressBus : public Bus
{
private:
    double speedMultiplier;

public:
    ExpressBus(string _route, string _capacity, string _status, int _stops, double _speedMultiplier = 0.8)
        : Bus(_route, _capacity, _status, _stops), speedMultiplier(_speedMultiplier) {}

    double calculateTravelTime(double distance) const override
    {
        double normalTime = Bus::calculateTravelTime(distance);
        return normalTime * speedMultiplier;
    }

    void displayInfo() const override
    {
        cout << "Express Bus on route: " << route
             << " | Capacity: " << capacity
             << " | Stops: " << numberofStops
             << " | Status: " << status
             << " | Faster by 20%" << endl;
    }
};

class Station
{
private:
    struct Schedule_Entry
    {
        string time;
        Vehicle *vehicle;
        string type;   // Arrival/Departure
        string status; // On-time / Delayed
    };
    vector<Schedule_Entry> schedules;

    string name;
    string location;
    string type;

public:
    Station(string _name, string _location, string _type) : name(_name), location(_location), type(_type) {}
    Station() : name(""), location(""), type("") {}

    void displayInfo()
    {
        cout << "Station: " << name
             << " | Location: " << location
             << " | Type: " << type << endl;
    }

    void addSchedule(string time, Vehicle *vehicle, string scheduleType, string status = "on-time")
    {
        Schedule_Entry entry = {time, vehicle, scheduleType, status};
        schedules.push_back(entry);

        cout << "Added schedule: "
             << scheduleType << " of " << vehicle->getRoute()
             << " at " << time
             << ", status " << status << endl;
    }

    void showSchedules()
    {
        cout << "Schedules for station: " << name << endl;
        for (auto &s : schedules)
        {
            cout << "- " << s.type
                 << " | Time: " << s.time
                 << " | Vehicle: " << s.vehicle->getRoute()
                 << " | Status: " << s.status
                 << endl;
        }
    }
};

class Passenger
{
private:
    string name;
    string ID;
    vector<Vehicle *> bookedVehicles;

public:
    Passenger(string _name, string _ID) : name(_name), ID(_ID) {}
    Passenger() : name(""), ID("") {}

    void displayInfo()
    {
        cout << "Passenger: " << name
             << " | ID: " << ID << endl;
    }

    void bookRide(Vehicle *v)
    {
        bookedVehicles.push_back(v);
        cout << name << " booked vehicle on route " << v->getRoute() << endl;
    }

    void cancelRide(Vehicle *v)
    {
        for (auto it = bookedVehicles.begin(); it != bookedVehicles.end(); ++it)
        {
            if (*it == v)
            {
                cout << name << " canceled booking for vehicle on route " << v->getRoute() << endl;
                bookedVehicles.erase(it);
                return;
            }
        }
        cout << name << " has no booking for this vehicle." << endl;
    }

    void showBookings()
    {
        cout << "Bookings of passenger " << name << ":" << endl;
        if (bookedVehicles.empty())
        {
            cout << "   (no bookings)" << endl;
        }
        for (auto *v : bookedVehicles)
        {
            cout << "- Vehicle on route " << v->getRoute()
                 << " | Status: " << v->getStatus() << endl;
        }
    }
};

int main()
{
    // Tạo station
    Station s1("Central Station", "Downtown", "Bus");

    // Tạo vehicles
    Bus bus1("Route 10", "50", "on-time", 5);
    ExpressBus expBus("Route 20X", "40", "on-time", 2);

    // Hiển thị vehicle info
    bus1.displayInfo();
    expBus.displayInfo();

    // Thêm schedule
    s1.addSchedule("08:00", &bus1, "Departure", "on-time");
    s1.addSchedule("09:00", &expBus, "Arrival", "delayed");

    // Hiển thị schedule
    s1.showSchedules();

    // Tạo passenger
    Passenger p1("Alice", "P001");
    p1.displayInfo();

    // Passenger booking
    p1.bookRide(&bus1);
    p1.bookRide(&expBus);
    p1.showBookings();

    // Passenger hủy vé
    p1.cancelRide(&bus1);
    p1.showBookings();

    // Demo tính thời gian di chuyển
    double distance = 100.0;
    cout << "\nTravel time for Bus: " << bus1.calculateTravelTime(distance) << " hours" << endl;
    cout << "Travel time for Express Bus: " << expBus.calculateTravelTime(distance) << " hours" << endl;

    return 0;
}
