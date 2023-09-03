// CS255
// P00 Complex Numbers
//		Calculates mathematical operations for complex numbers
// Samantha Roldan
//

#include <iostream>
using namespace std;

struct ComplexNumber {
	double real;
	double img;
};

ComplexNumber addComplexNumbers(ComplexNumber num1, ComplexNumber num2) { //adds the complex numbers
	ComplexNumber result;

	result.real = num1.real + num2.real;
	result.img = num1.img + num2.img;

	return result;
};

ComplexNumber subtractComplexNumbers(ComplexNumber num1, ComplexNumber num2) { //subtracts the complex numbers
	ComplexNumber result;

	result.real = num1.real - num2.real;
	result.img = num1.img - num2.img;

	return result;
};

ComplexNumber multiplyComplexNumbers(ComplexNumber num1, ComplexNumber num2) { //multiplies the complex numbers
	ComplexNumber result;

	result.real = num1.real * num2.real - num1.img * num2.img;
	result.img = num1.real * num2.img + num1.img * num2.real;

	return result;
};

ComplexNumber divideComplexNumbers(ComplexNumber num1, ComplexNumber num2) { //divides the complex numbers
	double divisor;
	ComplexNumber result;

	divisor = pow(num2.real, 2) + pow(num2.img, 2);
	result.real = (num1.real * num2.real + num1.img * num2.img) / divisor;
	result.img = (num1.img * num2.real - num1.real * num2.img) / divisor;

	return result;
};

void displayComplexNumber(ComplexNumber num) { //displays the complex numbers in correct format
	cout << num.real << " " << num.img << "i\n";
};

int main() {
	ComplexNumber num1;
	ComplexNumber num2;
	ComplexNumber num;
	char repeat;

	cout << "***** Complex Numbers *****\n";

	do {
		

		cout << "\nEnter 1st complex number real and imaginary parts separated by space: ";
		cin >> num1.real >> num1.img;
		cout << "\nEnter 2nd complex number real and imaginary parts (non-zero) separated by space: ";
		cin >> num2.real >> num2.img;

		while (num2.real == 0 || num2.img == 0) { //checks to see if num2 is a 0 and repeats until it isn't
			cout << ">>> ERROR: Both numbers must be non-zero -- try again! <<<\n";
			cout << "\nEnter 2nd complex number real and imaginary parts (non-zero) separated by space: ";
			cin >> num2.real >> num2.img;
		}


		cout << endl;
		cout << "Results: \n"; //below outputs all the results using the print function

		num = addComplexNumbers(num1, num2);
		cout << "   Addition Results: ";
		displayComplexNumber(num);

		num = subtractComplexNumbers(num1, num2);
		cout << "   Subtraction Results: ";
		displayComplexNumber(num);

		num = multiplyComplexNumbers(num1, num2);
		cout << "   Multiplication Results: ";
		displayComplexNumber(num);

		num = divideComplexNumbers(num1, num2);
		cout << "   Division Results: ";
		displayComplexNumber(num);


		cout << endl;
		cout << "\nRun again (y or Y) or any other character to end? ";
		cin >> repeat;

	} while (repeat == 'Y' || repeat == 'y');

	return 0;
}