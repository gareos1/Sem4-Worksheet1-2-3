
/* Create a program that:
1.	Reads student records (roll, name, marks) from a text file
2.	Throws an exception if marks are not between 0 and 100
3.	Allows adding new records with proper validation
4.	Saves modified records back to file
  */


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class StudentManager {
public:
    void displayStudents() {
        ifstream file("student.txt");
        if (!file) {
            cout << "File not found.\n";
            return;
        }

        int roll, marks;
        string name;

        cout << "\nList of Students:\n";
        while (file >> roll >> ws) {
            getline(file, name, '|');
            file >> marks;
            cout << "Roll: " << roll << ", Name: " << name << ", Marks: " << marks << "\n";
        }

        file.close();
    }

    void addStudents() {
        ofstream file("student.txt", ios::app);
        if (!file) {
            cout << "Error opening file.\n";
            return;
        }

        int n;
        cout << "How many students do you want to add? ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            int roll, marks;
            string name;

            cout << "\nEnter details for student " << (i + 1) << ":\n";

            cout << "Roll: ";
            cin >> roll;

            cout << "Name: ";
			// Using ws to consume any leading whitespace before getline
            cin >> ws; 
            getline(cin, name);

            cout << "Marks (0-100): ";
            cin >> marks;

            if (marks >= 0 && marks <= 100) {
                file << roll << " " << name << "|" << marks << "\n";
            }
            else {
                cout << "Invalid marks. Skipping student.\n";
            }
        }

        file.close();
        cout << "\nStudent record(s) added.\n";
    }

    void menu() {
        int choice = 0;
        while (choice != 3) {
            cout << "\n--- Student Manager Menu ---\n";
            cout << "1. Display Student Records\n";
            cout << "2. Add Student Records\n";
            cout << "3. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) {
                displayStudents();
            }
            else if (choice == 2) {
                addStudents();
            }
            else if (choice == 3) {
                cout << "Exiting program.\n";
            }
            else {
                cout << "Invalid choice.\n";
            }
        }
    }
};

int main() {
    StudentManager m1;
    m1.menu();
    return 0;
}
