#include "2D curve.h"

using namespace std;

double circle::CalculateArea() {
	return PI * r * r;
}

double elips::CalculateArea() {
	return PI * a * b;
}
void circle::printNAME() {
	cout << name1 << ": r = " << r << endl;
}
void elips::printNAME() {
	cout << name << ": a = " << a << "b = " << b << endl;
}