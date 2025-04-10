/* Task 3: Programming Exercises on Arrays
1.	Write a program that manages a cinema ticket booking system.The program should display a 5x5 seating arrangement where : [25 marks]
1.	Available seats are marked with 'O'
2.	Booked seats are marked with 'X'
Program should :
1.	Display the current seating arrangement
2.	Ask user for row and column number(1 - 5) for booking
3.	Mark that seat as booked('X')
4.	Show updated seating after each booking
5.	Display error if user selects already booked seat
6.	Display error if user enters invalid row / column numbers
*/


#include <iostream>
using namespace std;

class Cinema {
private:
    char seats[5][5];
    bool isValid;
    bool isAvailable;
    bool keepBooking;

    // Show the seating arrangement
    void showSeats() {
        cout << "\nCurrent Seating Arrangement:\n";
        cout << "  1 2 3 4 5\n";
        for (int i = 0; i < 5; ++i) {
            cout << i + 1 << " ";
            for (int j = 0; j < 5; ++j) {
                cout << seats[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Check if input is valid or not 
    void checkInput(int row, int col) {
        isValid = (row >= 1 && row <= 5 && col >= 1 && col <= 5);
    }

    // Check if the seat is not already booked
    void checkSeat(int row, int col) {
        isAvailable = (seats[row - 1][col - 1] == 'O');
    }

    // Mark seat as booked
    void book(int row, int col) {
        seats[row - 1][col - 1] = 'X';
    }

	//asks user if user wants to book another seat
    void askAgain() {
        char choice;
        cout << "Do you want to book another seat? (y/n): ";
        cin >> choice;
        keepBooking = (choice == 'y' || choice == 'Y');
    }

public:
    // Constructor to initialize all seats as available
    Cinema() {
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < 5; ++j)
                seats[i][j] = 'O';
    }

    // Booking menu
    void start() {
        cout << "Welcome to the Cinema Ticket Booking System \n";

        while (true) {
            showSeats();

            int row, col;
            cout << "Enter row number (1-5): ";
            cin >> row;
            cout << "Enter column number (1-5): ";
            cin >> col;

            checkInput(row, col);
            if (!isValid) {
                cout << "Invalid input\n";
                continue;
            }

            checkSeat(row, col);
            if (!isAvailable) {
                cout << "Seat already booked\n";
                continue;
            }

            book(row, col);
            cout << "Seat booked successfully!\n";

            askAgain();
            if (!keepBooking) {
                cout << "Thank you for using the Cinema Ticket Booking System.\n";
                break;
            }
        }
    }
};

int main() {
    Cinema c;
    c.start();
    return 0;
}

