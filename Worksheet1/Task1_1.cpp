/*1.	Write a program that takes a temperature value from the user. It should then allow the user to choose between Celsius (C) and Fahrenheit (F) for conversion. 
After the user selection, it should then convert the entered temperature to the chosen scale and display the result.
Use appropriate data types for temperature and handle error like non-numeric input. 
Use the following formula for conversion:
F = (C x 9/5) + 32
C = (F - 32) x 5/9 [10 marks]
*/





#include <iostream>
using namespace std;

class Temperature
{
private:
    float temp;
    char scale;

public:
	//function to get temperature from user
    void gettemp()
    {
        cout << "Enter the temperature: ";
        cin >> temp;
    }
	//function to get scale from user
    void getscale()
    {
        cout << "Pressing C will convert celsius into fahrenheit "<<endl<<"Pressing F will covert fahrenheit into celsius"<<endl;
        cin >> scale;
        if (scale != 'C' && scale != 'F' && scale != 'c' && scale != 'f')
        {
            cout << "Invalid input" << endl;
            getscale();
        }
    }
	//function to convert temperature
    void conversion()
    {
        if (scale == 'C'|| scale=='c')
        {
            cout << "Temperature in Fahrenheit: " << (temp * 9 / 5) + 32 << " F" << endl;
        }
        else
        {
            cout << "Temperature in Celsius: " << (temp - 32) * 5 / 9 << " C" << endl;
        }
    }
};

int main()
{
    Temperature t1;
    t1.gettemp();
    t1.getscale();
    t1.conversion();
    return 0;
}
