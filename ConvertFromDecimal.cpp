/*
The Converter
---------------------------------------------------------------------
This program will take a decimal number from the user, and then allow the user to convert it to either Binary, Octal,
or Hexadecimal.

@Author: Kyle Welch
@Version: 1.0
*/


#include <cmath>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
	//Variable Declaration
	int d;
	int b;
	int o;
	int h;
	char decision;
	char yorn;

	//Declare function prototype
	int convertDecimalToBinary(int);
	int convertDecimalToOctal(int);
	int convertDecimalToHexadecimal(int);

	//Welcome the user. Then ask them to enter a decimal value. The input will be held in int d.
	cout << "Welcome to The Converter!";

decimal:
	cout << "\n" << "Please enter a decimal value: ";
	cin >> d;

	//Check if the user entered a integer for the decimal
	if (cin.fail())
	{
		//Inform the user that he didn't enter a integer
		cout << "\nYou entered a char, which isn't a valid integer!" << endl;

		//Clear and ignore the user input.
		cin.clear();
		cin.ignore();

		//Go back to decimal and try again
		goto decimal;
	}

conversion:
	//Ask the user if they want to conver this to Binary, Octal, or Hexadecimal
	cout << "\n\nDo you want to convert " << d
		<< " to Binary (b), Octal (o), or Hexadecimal (h)?: ";
	cin >> decision;

	//If the user wanted to do a binary conversion to the inputted decimal value
	if (decision == 'b')
	{
		//Inform the user what they selected
		cout << "\nBinary Conversion! We will now convert, " << d << ", to binary!";
		cout << "\n-------------------------------------------------\n";

		//Explain to the user how to convert from decimal to binary
		cout << "\n\nthe binary (base two) numeral system has two possible values represented as 0 or 1 for each place-value.\n\n";

		//Call the convertDecimalToBinary function, and set the value of it equal to b.
		b = convertDecimalToBinary(d);

		//Output the conversion
		cout << "\n\nThe decimal value you inputted, " << d << ", in binary: " << b << endl;
	}

	//If the user wanted to do a octal conversion to the inputted decimal value
	else if (decision == 'o')
	{
		//Inform the user what they selected
		cout << "\nOctal Conversion! We will now convert " << d << " into octal!";
		cout << "\n-------------------------------------------------- \n";

		//Explain to user how to convert from decimal to octal
		cout << "\n\nOctal is the base 8 number system, that only uses the digits 0 through 7. "
			<< "\nIts main advantage is the ease of conversion with binary (base 2), "
			<< "\nsince each digit in octal can be written as a unique three-digit binary number.\n\n";

		//Call the convertDecimalToOctal function, and set the value of it equal to o.
		o = convertDecimalToOctal(d);

		//Output the conversion
		cout << "\n\nThe decimal value you inputted, " << d << ", in octal: " << o << endl;
	}

	//If the user wanted to do a hexadecimal conversion to the inputted decimal value
	else if (decision == 'h')
	{
		//Inform user of selection
		cout << "\nBinary Conversion! We will now convert, " << d << ", to binary!";
		cout << "\n-------------------------------------------------\n";

		//Explain to the user what hexadecimal is
		cout << "Hexadecimal is a base sixteen numeral system. "
			<< "\nThis means it has 16 symbols that can represent a single digit, "
			<< "\nadding A, B, C, D, E, and F on top of the usual ten numerals. \n\n";

		//Call the convertDecimalToOctal function, and set the value of it equal to o.
		h = convertDecimalToHexadecimal(d);

		cout << "\n\nThe decimal value you inputted, " << d << ", in hexadecimal: " << h << endl;
	}

	//If the user didn't input either b, o, or h, tell them that they can't do a conversion and the input is invalid
	else
	{
		//Inform the user that he didn't enter the right char. Have user try again.
		cout << "\nYou entered " << decision << " which isn't a valid option!";
		cin.ignore();
		cin.clear();
		goto conversion;
	}

	//Keep the screen up
	system("PAUSE");
	return 0;
}


/*
The convertDecimalToBinary function, this will take the user input (a decimal value) and convert it to binary.
@param decimal, the decimal value the user inputted
@return binary, the converted binary value.
*/
int convertDecimalToBinary(int decimal)
{
	//Declare variables for the function
	int x = decimal;
	int i = 0;
	int a = 1;
	int remainder;
	int binary = 0;
	int step;

	//Do the binary conversion until x=0
	while (x != 0)
	{
		//Do the what was just explained. Set int step equal to x/2, set int remainder to x%2. Include counter addition, i++.
		i++;
		step = x / 2;
		remainder = x % 2;
		cout << "| Stage " << i << ": " << x << " / 2 = " << step << " | Remainder: " << remainder << " | " << endl;

		//This is to prevent and infinite loop
		x /= 2;

		//This will print out the remainder digits and form it in decimal
		//We need to do last remainder first, to first remainder last.
		binary += remainder * a;
		a *= 10;
	}

	//Return the conversion
	return binary;
}

/*
The convertDecimalToOctal function, this will take the user input (a decimal value) and convert it to octal.
@param decimal, the decimal value the user inputted
@return octal, the converted octal value.
*/
int convertDecimalToOctal(int decimal)
{
	//Declare variables for the function
	int x = decimal;
	int i = 0;
	int a = 1;
	int remainder;
	int octal = 0;
	int step;

	//Do the while loop until x = 0
	while (x != 0)
	{
		i++;
		step = x / 8;
		remainder = x % 8;
		cout << "| Stage " << i << ": " << x << " / 8 = " << step << " | Remainder: " << remainder << " | " << endl;

		//This is to prevent and infinite loop
		x /= 8;

		//This will print out the remainder digits and form it in octal. 
		//We need to do last remainder first, to first remainder last.
		octal += remainder * a;
		a *= 10;
	}


	//Return the conversion
	return octal;
}

/*
The convertDecimalToHexadecimal function, this will take the user input (a decimal value) and convert it to hexadecimal.
@param decimal, the decimal value the user inputted
@return hexadecimal, the converted hexadecimal value.
*/
int convertDecimalToHexadecimal(int decimal)
{
	//Declare variables for the function
	int x = decimal;
	int i = 0;
	int a = 1;
	int remainder;
	int hexadecimal = 0;
	int step;

	//Do the binary conversion until x=0
	while (x != 0)
	{
		//Do the what was just explained. Set int step equal to x/2, set int remainder to x%2. Include counter addition, i++.
		i++;
		step = x / 16;
		remainder = x % 16;
		cout << "| Stage " << i << ": " << x << " / 16 = " << step << " | Remainder: " << remainder << " | " << endl;
		cout << "| Hexadecimal value: " << hex << remainder << " | " << endl;

		//This is to prevent and infinite loop
		x /= 16;

		//This will print out the remainder digits and form it in decimal
		//We need to do last remainder first, to first remainder last.
		hexadecimal += remainder * a;
		a *= 16;
	}

	//Return the conversion
	return hexadecimal;
}