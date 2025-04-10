/* 1.	Create a Time class to store hours and minutes. Implement:
1.	Overload the + operator to add two Time objects
2.	Overload the > operator to compare two Time objects
3.	Handle invalid time (>24 hours or >60 minutes) by throwing a custom exception
 */


#include <iostream>
using namespace std;

class Measure {
private:
	int hours;
	int minutes;
public:
	Measure() {
		hours = 0;
		minutes = 0;
	}

	Measure(int h, int m) {
		if (h < 0 || m < 0 || h > 24 || m > 60) {
			int a = 1;
			throw (a);
		}
		hours = h;
		minutes = m;
	}

	Measure operator+(Measure m) {
		Measure temp;
		temp.minutes = minutes + m.minutes;
		int ff = temp.minutes / 60;
		temp.minutes = temp.minutes % 60;
		temp.hours = hours + m.hours + ff;
		
		if (temp.hours > 24) {
			int a = 1;
			throw (a);
		}
		return temp;
	}
	bool operator>(Measure m) {
		return (hours > m.hours) || (hours == m.hours && minutes > m.minutes);
	}

	


	void display() {
		cout << "Hours: " << hours << ", Minutes: " << minutes << endl;
	}

	void menu() {
		try {
			int hours, minutes;
			cout << "Enter the hours and minutes: " << endl;
			cin >> hours >> minutes;
			Measure t1(hours, minutes);
			t1.display();
			cout << "Enter the hours and minutes for the second time: " << endl;
			cin >> hours >> minutes;
			Measure t2(hours, minutes);
			t2.display();
			if (t1 > t2) {
				cout << "Time 1 is greater than Time 2" << endl;
			}
			else {
				cout << "Time 2 is greater than Time 1" << endl;
			}
			Measure t3 = t1 + t2;
			cout << "After adding the two times: " << endl;
			t3.display();
		}
		catch (int a) {
			cout << "Invalid time" << endl;
		}
	}
};

	int main()
	{
		Measure t1;
		t1.menu();
		return 0;
	}
