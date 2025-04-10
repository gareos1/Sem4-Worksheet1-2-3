/* Write a program that reads the titles of 10 books (use an array of 150 characters) and writes them in a binary file selected by the user.
The program should read a title and display a message to indicate if it is contained in the file or not. 	


 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class BookManager {
    char filename[100];

public:
    void getFilename() {
        cout << "Enter binary filename: ";
        cin.getline(filename, 100);
    }

    void writeBooks() {
        ofstream file(filename, ios::binary);
        if (!file) {
            cout << "Error opening file.\n";
            return;
        }

        char title[150];
        for (int i = 0; i < 10; i++) {
            cout << "Enter title " << (i + 1) << ": ";
            //function is used to set all bytes of the title array to zero (or the null character '\0')
            memset(title, 0, 150);
            cin.getline(title, 150);
            file.write(title, 150);
        }

        file.close();
        cout << "Books written to binary file.\n";
    }

    void searchBook() {
        ifstream file(filename, ios::binary);
        if (!file) {
            cout << "File not found.\n";
            return;
        }

        char search[150];
        cout << "Enter title to search: ";
        cin.getline(search, 150);

        char title[150];
        bool found = false;

        while (file.read(title, 150)) {
            // function in C/C++ is used to compare a specified number of characters between two string
            if (strncmp(title, search, 150) == 0) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "Title found in file.\n";
        }
        else {
            cout << "Title not found.\n";
        }

        file.close();
    }

    void displayBooks() {
        ifstream file(filename, ios::binary);
        if (!file) {
            cout << "File not found.\n";
            return;
        }

        char title[150];
        int count = 1;

        cout << "\nList of books:\n";
        while (file.read(title, 150)) {
            cout << count << ". " << title << "\n";
            count++;
        }

        file.close();
    }

    void menu() {
        getFilename();

        int choice;
        do {
            cout << "\n--- Book Manager Menu ---\n";
            cout << "1. Write 10 Book Titles to File\n";
            cout << "2. Search for a Book Title\n";
            cout << "3. Display All Book Titles\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore(); // To clear leftover newline after cin, to prevent issues with input



            switch (choice) {
            case 1:
                writeBooks();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                displayBooks();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 4);
    }
};

int main() {
    BookManager m1;
    m1.menu();
    return 0;
}
