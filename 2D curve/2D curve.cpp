#include "2D curve.h"


void circle::printNAME() {
	cout << name << ": r = " << r << endl;
}

void elips::printNAME() {
	cout << name << ": a = " << a << " b = " << b << endl;
}

void spiral::printNAME() {
	cout << name << ": r = " << r << " step = " << step << endl;
}

vector<double> circle::get_first_derivative(double t) {
	double x = 0;
	double y = 0;
	x = r * -sin(t); //производная x по t
	y = r * cos(t);
	return { x, y, 0 };
}

vector<double> elips::get_first_derivative(double t) {
	double x = 0;
	double y = 0;
	x = a * -sin(t);
	y = b * cos(t);
	return { x, y, 0 };
}

vector<double> spiral::get_first_derivative(double t) {
	double x = 0;
	double y = 0;
	double z = 0;
	x = r * -sin(t);
	y = r * cos(t);
	z = step;
	return { x, y, z };
}

vector<double> circle::get_coordinates(double t) {
	double x = 0;
	double y = 0;
	x = r * cos(t);
	y = r * sin(t);
	return { x, y, 0 };
}

vector<double> elips::get_coordinates(double t) {
	double x = 0;
	double y = 0;
	x = a * cos(t);
	y = b * sin(t);
	return { x, y, 0 };
}

vector<double> spiral::get_coordinates(double t) {
	double x = 0;
	double y = 0;
	double z = 0;
	x = r * cos(t);
	y = r * sin(t);
	z = step * t;
	return { x, y, z };
}

elips::~elips(){}
circle::~circle(){}
spiral::~spiral(){}


double getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<double>(rand() * fraction * (max - min + 1) + min);
}



double radii_all_figures(vector <Figure*>& circle_array) {
	double sum_radii = 0;
	for (int i = 0; i < circle_array.size(); i++)
	{
		sum_radii += static_cast<circle&>(*circle_array[i]).get_radius();
	}
	return sum_radii;
}

void print_vec(vector<double> v) {
	cout << endl;
	for (vector<double>::iterator it = v.begin(); it != v.end(); ++it)
		cout << *it << " ";
	cout << endl;
}