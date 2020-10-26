#include "2D curve.h"
#include <cstdlib>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	srand(static_cast<unsigned int>(time(0)));
	int size = 5;//размер вектора
	vector<Figure *> vec;

	//заполнение вектора указателями на объекты---------------
	for (int i = 0; i < size; i++)
	{
		if ((int)getRandomNumber(0, 5) % 2 == 0)
			vec.push_back(new circle(getRandomNumber(0, 8)));
		else
			vec.push_back(new elips(getRandomNumber(0, 7), getRandomNumber(0, 6)));

	}

	cout << " площади созданных фигур " << endl;
	vector <double> array(size);
	for (int i = 0; i < size; i++)
	{
		array[i] = vec[i]->CalculateArea();
		vec[i]->printNAME();
		cout << "площадь " << vec[i]->CalculateArea() << "\n";
	}

	cout << "\n" << "кривые по возрастанию площадей" << "\n";
	sortArea(array);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			if (array[i] == vec[j]->CalculateArea())
			{
				cout << "площадь: " << vec[j]->CalculateArea();
				vec[j]->printNAME();
				break;
			}
		}

	cout << "\n" << "площадь всех фигур " << area_all_figures(array) << endl;
	return 0;
}





