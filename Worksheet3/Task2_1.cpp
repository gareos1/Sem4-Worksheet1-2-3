/*  1.	Create a base class Vehicle and two derived classes Car and Bike:
1.	Vehicle has registration number and color
2.	Car adds number of seats
3.	Bike adds engine capacity
4.	Each class should have its own method to write its details to a file
5.	Include proper inheritance and method overriding
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string registrationNumber;
    string color;

public:
    void inputDetails() {
        cout << "Enter Registration Number: ";
        cin >> registrationNumber;
        cout << "Enter Color: ";
        cin >> color;
    }

    virtual void writeDetailsToFile() {
        ofstream outFile("VehicleDetails.txt", ios::app);
        outFile << "Registration Number: " << registrationNumber << endl;
        outFile << "Color: " << color << endl;
        outFile << "--------------------------" << endl;
        outFile.close();
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
protected:
    int numberOfSeats;

public:
    void inputDetails() {
        Vehicle::inputDetails();
        cout << "Enter Number of Seats: ";
        cin >> numberOfSeats;
    }

    void writeDetailsToFile() override {
        ofstream outFile("CarDetails.txt", ios::app);
        outFile << "Registration Number: " << registrationNumber << endl;
        outFile << "Color: " << color << endl;
        outFile << "Number of Seats: " << numberOfSeats << endl;
        outFile << "--------------------------" << endl;
        outFile.close();
    }
};

class Bike : public Vehicle {
protected:
    int engineCapacity;

public:
    void inputDetails() {
        Vehicle::inputDetails();
        cout << "Enter Engine Capacity (in cc): ";
        cin >> engineCapacity;
    }

    void writeDetailsToFile() override {
        ofstream outFile("BikeDetails.txt", ios::app);
        outFile << "Registration Number: " << registrationNumber << endl;
        outFile << "Color: " << color << endl;
        outFile << "Engine Capacity: " << engineCapacity << " cc" << endl;
        outFile << "--------------------------" << endl;
        outFile.close();
    }
};

class Menu {
public:
    void displayMenu() {
        Car car;
        Bike bike;

        cout << "Enter Car Details:\n";
        car.inputDetails();
        car.writeDetailsToFile();

        cout << "\nEnter Bike Details:\n";
        bike.inputDetails();
        bike.writeDetailsToFile();

        cout << "\nDetails have been written to files successfully.\n";
    }

    void displayFileContent() {
        displayFile("CarDetails.txt", "Car Details");
        displayFile("BikeDetails.txt", "Bike Details");
    }

private:
    void displayFile(const string& fileName, const string& header) {
        ifstream inFile(fileName);
        if (!inFile) {
            cout << "Could not open " << fileName << endl;
            return;
        }
        string line;
        cout << "\n--- " << header << " ---\n";
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        cout << "-------------------------\n";
        inFile.close();
    }
};

int main() {
    Menu m1;
    m1.displayMenu();
    m1.displayFileContent();
    return 0;
}

