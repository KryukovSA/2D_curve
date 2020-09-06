
//для контроля утеечк памяти______________

#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
//_________________________________________________




#include <iostream>
#include "2D curve.h"
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

double getRandomNumber(int min, int max);

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


	// создадим массив площадей------------------
	vector <double> array(size);
	for (int i = 0; i < size; i++)
	{
		array[i] = vec[i]->CalculateArea();
		vec[i]->printNAME();
		cout << "площадь " << vec[i]->CalculateArea() << "\n";

	}


	//отсортируем вектор указателей на объекты по возрастанию площадей-------------------
	cout << "\n" << "кривые по возрастанию площадей" << "\n";
	double temp;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}

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


	//вычисляем площадь всех фигур(в пункте 4 не понятно сформулировано каких именно)----------------------------

	double Ssum = 0;

	for (int i = 0; i < size; i++)
	{
		Ssum += array[i];
	}
	cout << "\n" << "площадь всех фигур " << Ssum << endl;

	_CrtDumpMemoryLeaks(); //контроль утечек памяти

	return 0;
}



double getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<double>(rand() * fraction * (max - min + 1) + min);
}

