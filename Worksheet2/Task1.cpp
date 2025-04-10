/*   Write a program that manages a simple student grade calculator with the following requirements. Create a Student class that has: 
1.	Student name (string)
2.	Three subject marks (integers)
3.	A basic member function to calculate average
The program should: 
1.	Accept student details (name and marks) from user input
2.	Calculate and display: 
1.	Total marks
2.	Average marks
3.	Grade (A for ≥90%, B for ≥80%, C for ≥70%, D for ≥60%, F for <60%)
3.	Display a message if any mark is below 0 or above 100
 */


#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int marks1, marks2, marks3;

public:
    void getDetails() {
        cout << "Enter student name: ";
        getline(cin, name);
        cout << "Enter marks for subject 1: ";
        cin >> marks1;
        cout << "Enter marks for subject 2: ";
        cin >> marks2;
        cout << "Enter marks for subject 3: ";
        cin >> marks3;

        if (marks1 < 0 || marks1 > 100 || marks2 < 0 || marks2 > 100 || marks3 < 0 || marks3 > 100) {
			int a = 1; // Dummy variable to throw an exception
            throw(a);
        }
    }

    void display() {
        cout << "\nStudent Name: " << name << endl;
        cout << "Marks in Subject 1: " << marks1 << endl;
        cout << "Marks in Subject 2: " << marks2 << endl;
        cout << "Marks in Subject 3: " << marks3 << endl;
    }

    void average() {
        int total = marks1 + marks2 + marks3;
        float avg = total / 3.0;
        cout << "Total Marks: " << total << endl;
        cout << "Average Marks: " << avg << endl;

        cout << "Grade: ";
        if (avg >= 90) {
            cout << "A" << endl;
        }
        else if (avg >= 80) {
            cout << "B" << endl;
        }
        else if (avg >= 70) {
            cout << "C" << endl;
        }
        else if (avg >= 60) {
            cout << "D" << endl;
        }
        else {
            cout << "F" << endl;
        }
    }
};

int main() {
    Student s1;
    try {
        s1.getDetails();
        s1.display();
        s1.average();
    }
    catch (int a) {
        cout << "Error!, Marks should be between 0-100" << endl;
    }

    return 0;
}
