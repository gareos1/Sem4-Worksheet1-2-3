/*	 Write a C++ program to implement a number guessing game with different difficulty levels.
Easy difficulty ranges from 1-8, medium from 1-30, hard from 1-50.Then,generate a random number to check if the guess is correct based on the user's selection. 
 [10 marks]
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Game {
    int maxRange, actualno, guessno;

public:
    void setdifficulty() {
        int choice;
        cout << "Select Difficulty Level:"<<endl;
        cout << "1. Easy (1-8)"<<endl;
        cout << "2. Medium (1-30)"<<endl;
        cout << "3. Hard (1-50)"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            maxRange = 8;
            break;
        case 2:
            maxRange = 30; 
            break;
        case 3:
            maxRange = 50;
            break;
        default:
            cout << "Invalid choice! Please choose again\n";
            setdifficulty();
        }
    }

    void randomno() {
        //this is to give random no
        srand(time(0)); 

        actualno = rand() % maxRange + 1; // Generates number in range 1 to maxRange
    }

    void playGame() {
        cout << "Guess a number between 1 and " << maxRange << ":\n";

        do {
            cout << "Enter your guess: ";
            cin >> guessno;

            if (guessno < actualno) {
                cout << "Too low! Try again.\n";
            }
            else if (guessno > actualno) {
                cout << "Too high! Try again.\n";
            }
            else {
                cout << "Congratulations! You guessed the correct number: " << actualno << endl;
            }
        } while (guessno != actualno);
    }
};

int main() {
    Game g1;
    g1.setdifficulty();
    g1.randomno();
    g1.playGame();
    return 0;
}
