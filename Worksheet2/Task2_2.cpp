/*  2.	Create a program with these overloaded functions named Max:
1.	One that finds maximum between two integers
2.	One that finds maximum between two floating-point numbers
3.	One that finds maximum among three integers
4.	One that finds maximum between an integer and a float	 */

#include <iostream>
using namespace std;

class Maximum {
private:
    int maxInt;
    float maxFloat;

public:
    // two integers
    void Max(int a, int b) {
        if (a > b) {
            maxInt = a;
        }
        else {
            maxInt = b;
        }
        cout << "Maximum between " << a << " and " << b << " is: " << maxInt << endl;
    }

    // two floats
    void Max(float a, float b) {
        if (a > b) {
            maxFloat = a;
        }
        else {
            maxFloat = b;
        }
        cout << "Maximum between " << a << " and " << b << " is: " << maxFloat << endl;
    }

    // three ints
    void Max(int a, int b, int c) {
        if (a > b) {
            maxInt = a;
        }
        else {
            maxInt = b;
        }

        if (c > maxInt) {
            maxInt = c;
        }

        cout << "Maximum among " << a << ", " << b << ", and " << c << " is: " << maxInt << endl;
    }

    // an int and a float
    void Max(int a, float b) {
        if (a > b) {
            maxFloat = a;
        }
        else {
            maxFloat = b;
        }
        cout << "Maximum between " << a << " and " << b << " is: " << maxFloat << endl;
    }

    void run() {
        int int1, int2, int3;
        float float1, float2;

        cout << "Enter two integers: ";
        cin >> int1 >> int2;
        Max(int1, int2);

        cout << "Enter two float numbers: ";
        cin >> float1 >> float2;
        Max(float1, float2);

        cout << "Enter three integers: ";
        cin >> int1 >> int2 >> int3;
        Max(int1, int2, int3);

        cout << "Enter an integer and a floating-point number: ";
        cin >> int1 >> float1;
        Max(int1, float1);
    }
};

int main() {
    Maximum m1;
    m1.run();
    return 0;
}
