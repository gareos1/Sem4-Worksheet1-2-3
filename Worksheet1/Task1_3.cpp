/*	Write a program that reads an array of integer numbers from the user and sorts the numbers in the ascending order. 
[10 marks]
*/



#include <iostream>
using namespace std;

class SortArray {
private:
    int size;
    int arr[100];
	

public:
    void inputArr() {
        //size can be increased as per the requirement for now 100 is used
        cout << "Enter the size of the array (max 100): ";
        cin >> size;

        if (size > 100 || size <= 0) {
            int a;
			throw(a = 1);
        }
		
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    void sortArr() {

        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (arr[i] > arr[j]) {
                   
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
                  
                }
            }
        }
    }

    void displayArr() {
        cout << "The sorted array is: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    SortArray s1;
	try {
		s1.inputArr();
	}
	catch (int a) {
		cout << "Invalid size of the array" << endl;
		return 0;
	}
   
    s1.sortArr();
    s1.displayArr();
    return 0;
}
