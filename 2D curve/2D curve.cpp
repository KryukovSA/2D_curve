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
	cout << name << ": a = " << a << " b = " << b << endl;
}

elips::~elips(){}
circle::~circle(){}


double getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<double>(rand() * fraction * (max - min + 1) + min);
}

void sortArea(vector<double>&array)
{
	double temp;
	for (int i = 0; i < array.size(); i++)
		for (int j = 0; j < array.size() - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
}

double area_all_figures(vector<double>&array) {
	double Ssum = 0;
	for (int i = 0; i < array.size(); i++)
	{
		Ssum += array[i];
	}
	return Ssum;
}