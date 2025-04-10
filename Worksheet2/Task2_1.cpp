/* 1.	Write a program with a class Circle having:
1.	Private member: radius (float)
2.	A constructor to initialize radius
3.	A friend function compareTwoCircles that takes two Circle objects and prints which circle has the larger area
 */


#include <iostream>
using namespace std;
class Circle {
private:
	float radius;
public:
	
	Circle(float r) {
	radius = r;
	}

	friend void compareTwoCircles(Circle c1, Circle c2);
};
void compareTwoCircles(Circle c1, Circle c2) {
	float PI = 3.14;
	float area1 = PI * c1.radius * c1.radius;
	float area2 = PI * c2.radius * c2.radius;
	if (area1 > area2) {
		cout << "Area of circle 1 is : " << area1 << endl;
		cout << "Area of circle 2 is : " << area2 << endl;
		cout << "Circle 1 has a larger area." << endl;
	}
	else if (area1 < area2) {
		cout << "Area of circle 1 is : " << area1 << endl;
		cout << "Area of circle 2 is : " << area2 << endl;
		cout << "Circle 2 has a larger area." << endl;
	}
	else {
		cout << "Area of circle 1 is : " << area1 << endl;
		cout << "Area of circle 2 is : " << area2 << endl;
		cout << "Both circles have the same area." << endl;
	}
}
int main() {
	float a, b;
	cout << "Enter radius of circle 1: ";
	cin >> a;
	cout << "Enter radius of circle 2: ";
	cin >> b;
	Circle cir1(a);
	Circle cir2(b);
	compareTwoCircles(cir1, cir2);
	return 0;
}