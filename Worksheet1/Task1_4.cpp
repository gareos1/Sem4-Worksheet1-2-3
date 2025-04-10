/* Write a program that reads a number from the user and based on the user input, it says what day of the week it is, Sundays being 1 and Saturdays being 7.
You system should give appropriate response for invalid input entries.[20 marks] */


#include <iostream>
using namespace std;

class dayOfWeek {

private:
	int day;

public:
	void setday() {
		cout << "Enter a number between 1 and 7: ";
		cin >> day;
	}

	void weekday() {
		if (day == 1) {
			cout << "Sunday" << endl;
		}
		else if (day == 2) {
			cout << "Monday" << endl;
		}
		else if (day == 3) {
			cout << "Tuesday" << endl;
		}
		else if (day == 4) {
			cout << "Wednesday" << endl;
		}
		else if (day == 5) {
			cout << "Thursday" << endl;
		}
		else if (day == 6) {
			cout << "Friday" << endl;
		}
		else if (day == 7) {
			cout << "Saturday" << endl;
		}
		else {
			cout << "Invalid input" << endl;
		}
	}


	void menu() {
		setday();
		weekday();
	}

};

int main() {
	dayOfWeek d1;
	d1.menu();
	return 0;
}