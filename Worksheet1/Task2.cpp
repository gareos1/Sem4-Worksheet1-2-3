/*	Create a program that takes a positive integer as input and determines whether it's a "bouncy number". A bouncy number is one where the digits neither consistently increase nor consistently decrease when read from left to right. For example:
●	123 is NOT bouncy (digits consistently increase)
●	321 is NOT bouncy (digits consistently decrease)
●	120 is bouncy (neither consistently increasing nor decreasing)
 [25 marks]
*/

#include <iostream>
using namespace std;

class BouncyNumber {
    int number;
    //this bool var checks whether its bouncy or not
    bool isBouncy; 

public:

    //function to enter number
    void enterno() {
        cout << "Enter a number: ";
        cin >> number;
    }

    //function to check bounce no or not
    void determineBouncyNumber() {
        int temp = number;
        bool increasing = false, decreasing = false;

        int lastno = temp % 10;
        temp /= 10;

        while (temp > 0) {
            int currentno = temp % 10;

            if (currentno < lastno) {
                increasing = true;
            }
            else if (currentno > lastno) {
                decreasing = true;
            }

            lastno = currentno;
            temp /= 10;

            // If both conditions are met, it's bouncy
            if (increasing && decreasing) {
                isBouncy = true;
                break; // breaks loop
            }
        }

        // If we exit the loop without breaking, it's not bouncy
        if (!(increasing && decreasing)) {
            isBouncy = false;
        }
    }

    void checkAndDisplay() {
        enterno();
        determineBouncyNumber();

        if (isBouncy) {
            cout << "The number is a bouncy number." << endl;
        }
        else {
            cout << "The number is not a bouncy number." << endl;
        }
    }
};

int main() {
    BouncyNumber b1;
    b1.checkAndDisplay();
    return 0;
}

