//#include "2D curve.h"
#include "DLL_curve.h"
#include <cstdlib>
#include <algorithm>
#include <typeinfo>
#define PI 3.1417

int main()
{
	setlocale(LC_CTYPE, "Russian");
	srand(static_cast<unsigned int>(time(0)));
	int size = 6;//размер вектора
	double t = PI / 4;

	//2-------------------------------------
	vector<Figure *> vec;
	//заполнение вектора указателями на объекты---------------
	for (int i = 0; i < size; i++)
	{
		if ((int)getRandomNumber(0, 5) % 3 == 0)
			vec.push_back(new circle(getRandomNumber(0, 8)));
		else if((int)getRandomNumber(0, 5) % 3 == 1)
			vec.push_back(new elips(getRandomNumber(0, 7), getRandomNumber(0, 6)));
		else
			vec.push_back(new spiral(getRandomNumber(0, 6), getRandomNumber(0, 6)));
	}
	size += 2;
	vec.push_back(new circle(getRandomNumber(0, 8)));
	vec.push_back(new circle(getRandomNumber(0, 8)));

	//3-------------------------------------
	for (int i = 0; i < size; i++) {
		cout << "\n";
		vec[i]->printNAME();
		cout  << "coordinates: ";
		print_vec(vec[i]->get_coordinates(t));
		cout << "derivative ";
		print_vec(vec[i]->get_first_derivative(t));
	}

	//4---------------------------------------------
	vector <Figure *> circle_array;
	for (int i = 0; i < size; i++) {
		if (typeid(*vec[i]) == typeid(circle)) {
			circle_array.push_back(vec[i]);
			//circle_array.push_back(static_cast<circle&>(*vec[i]));
			cout << "адрес исходого " << vec[i] << " адрес из нового " << circle_array.back() << endl;
		}

	}


	//5---------------------------------------------------
	sort(circle_array.begin(), circle_array.end(), pred());
	cout << "\n" << "круги отсортированные по радиусам" << "\n";
	for (int i = 0; i < circle_array.size(); i++) {
		circle_array[i]->printNAME();
	}

	//6----------------------------------------------------------
	cout << "\n" << "сумма радиусов "  << endl;
	cout << radii_all_figures(circle_array);

	
	return 0;
}





