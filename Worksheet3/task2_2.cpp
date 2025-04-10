/* 2.	Create a program that:
1.	Reads student records (roll, name, marks) from a text file
2.	Throws an exception if marks are not between 0 and 100
3.	Allows adding new records with proper validation
4.	Saves modified records back to file
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    int roll;
    string name;
    int marks;
};

class StudentManagement {
    Student students[100];
    int count;
    string filename;

public:
    StudentManagement() {
        count = 0;
        filename = "students.txt";
    }

    void readRecords() {
        ifstream file(filename);
        if (!file) {
            cout << "File not found. A new one will be created.\n";
            return;
        }

        while (file >> students[count].roll >> students[count].name >> students[count].marks) {
            if (students[count].marks >= 0 && students[count].marks <= 100) {
                count++;
            }
            else {
                cout << "Invalid marks in file for student " << students[count].name << ". Skipping.\n";
            }
        }

        file.close();
    }

    void addRecord() {
        cout << "Enter roll number: ";
        cin >> students[count].roll;
        cout << "Enter name: ";
        cin >> students[count].name;
        cout << "Enter marks (0-100): ";
        cin >> students[count].marks;

        if (students[count].marks >= 0 && students[count].marks <= 100) {
            cout << "Record added successfully.\n";
            count++;
        }
        else {
            cout << "Invalid marks. Record not added.\n";
        }
    }

    void writeRecords() {
        ofstream file(filename);
        for (int i = 0; i < count; i++) {
            file << students[i].roll << " " << students[i].name << " " << students[i].marks << endl;
        }
        file.close();
    }

    void showRecords() {
        for (int i = 0; i < count; i++) {
            cout << "Roll: " << students[i].roll << ", Name: " << students[i].name << ", Marks: " << students[i].marks << endl;
        }
    }

    void menu() {
        readRecords();

        int choice;
        do {
            cout << "\nMenu:\n1. Add Record\n2. Show All Records\n3. Save & Exit\nChoice: ";
            cin >> choice;

            if (choice == 1) {
                addRecord();
            }
            else if (choice == 2) {
                showRecords();
            }
            else if (choice == 3) {
                writeRecords();
                cout << "Records saved.\n";
            }
            else {
                cout << "Invalid choice.\n";
            }
        } while (choice != 3);
    }
};

int main() {
    StudentManagement s1;
    s1.menu();
    return 0;
}
