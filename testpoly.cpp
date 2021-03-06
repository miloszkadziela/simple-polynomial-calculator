#include "Poly.h"
#include <iostream>

using namespace std;

int main(void) {
    Poly p1; //Declare object representing polynomial p1

	//p1[3] = 1;
	//p1[2] = 1;
	p1[1] = -2;
	p1[0] = -3; //Specify coefficients of p1 = 2x^3 + 3.6x + 7

	Poly p2 = 5; //Declare object representing polynomial p2 = 5
	p2[1] = 4;
	//p2[2] = 1;
	//p2[4] = 1; //Specify additional coefficients of p2 = x^4 + 6x^2 + 3x + 5

	cout << "Polynomial p1: " << p1 << endl; //Print p1 	
	cout << "Polynomial p2: " << p2 << endl; //Print p2

	Poly p3 = p1 + p2; //Add p1 and p2 	
	cout << "Sum of polynomials p1 and p2: " << p3 << endl; //Print sum of p1 and p2 :::: x^4 + 2x^3 + 6x^2 + 6.6x + 12

	p3 = p1 * p2; //Multiply p1 by p2 	
	cout << "Product of polynomials p1 and p2: " << p3 << endl; //Print product of p1 and p2

	p3 = 2 * p1; //Multiply p1 by 2 	
	cout << "Polynomial p1 multiplied by 2: " << p3 << endl; //Print product of p1 and 2

	double val = p1(3.14); //Calculate the value of p1 at point 3.14
	cout << "Value of polynomial p1 at point 3.14: " << val << endl; //Print the value of p1 at point 3.14

	
}
