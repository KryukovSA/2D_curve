#include "2D curve.h"



using namespace std;

double circle::CalculateArea() {
	return PI * r * r;
}

double elips::CalculateArea() {
	return PI * a * b;
}