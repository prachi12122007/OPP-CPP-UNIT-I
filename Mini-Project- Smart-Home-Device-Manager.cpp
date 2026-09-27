#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SmartDevice {
private:
    string deviceId;
    string deviceName;
    string location;
    string status;
    string lastUpdated;

public:

    // Constructor
    SmartDevice(string id, string name, string loc,
                string stat, string time)
        : deviceId(id),
          deviceName(name),
          location(loc),
          status(stat),
          lastUpdated(time) {}

    // Turn device ON
    void turnOn(string time) {
        status = "ON";
        lastUpdated = time;
    }

    // Turn device OFF
    void turnOff(string time) {
        status = "OFF";
        lastUpdated = time;
    }

    // Change status
    void changeStatus(string newStatus, string time) {
        status = newStatus;
        lastUpdated = time;
    }

    // Display device details
    void display() const {
        cout << "Device ID   : " << deviceId << endl;
        cout << "Device Name : " << deviceName << endl;
        cout << "Location    : " << location << endl;
        cout << "Status      : " << status << endl;
        cout << "Last Updated: " << lastUpdated << endl;
        cout << "-----------------------------" << endl;
    }
};

int main() {

    vector<SmartDevice> devices;

    // Create smart home devices
    devices.emplace_back(
        "D001",
        "Smart Light",
        "Living Room",
        "OFF",
        "08:00"
    );

    devices.emplace_back(
        "D002",
        "Thermostat",
        "Bedroom",
        "ON",
        "08:05"
    );

    devices.emplace_back(
        "D003",
        "Security Camera",
        "Main Door",
        "ON",
        "08:10"
    );

    devices.emplace_back(
        "D004",
        "Smart Door Lock",
        "Main Door",
        "LOCKED",
        "08:15"
    );

    cout << "====================================" << endl;
    cout << "       SMART HOME DASHBOARD" << endl;
    cout << "====================================" << endl;

    // Display all devices
    for (const auto& device : devices) {
        device.display();
    }

    // Update devices
    devices[0].turnOn("09:00");

    devices[1].changeStatus("24°C", "09:05");

    devices[2].turnOff("09:10");

    devices[3].changeStatus("UNLOCKED", "09:15");

    cout << "\n====================================" << endl;
    cout << "       UPDATED HOME DASHBOARD" << endl;
    cout << "====================================" << endl;

    // Display updated devices
    for (const auto& device : devices) {
        device.display();
    }

    return 0;
}
