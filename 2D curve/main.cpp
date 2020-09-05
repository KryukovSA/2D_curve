// 2D curve.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "2D curve.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

double getRandomNumber(int min, int max);

int main()
{
	setlocale(LC_CTYPE, "Russian");
	//заполнение вектора указателями на объекты
	srand(static_cast<unsigned int>(time(0)));
	int size = 5;//размер вектора

	vector<Figure *> vec;
	for (int i = 0; i < size; i++)
	{
		if ((int)getRandomNumber(0, 5) % 2 == 0)
			vec.push_back(new circle(getRandomNumber(0, 3254625)));
		else
			vec.push_back(new elips(getRandomNumber(0, 3254625), getRandomNumber(0, 3254625)));

	}

	// создадим массив площадей
	vector <double> array;
	for (int i = 0; i < size; i++)
		array[i] = vec[i]->CalculateArea();

	//отсортируем вектор указателей на объекты по возрастанию площадей
	Figure* temp;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = temp;
			}
		}

	//вычисляем площадь всех фигур(в пункте 4 не понятно сформулировано каких именно)

	double Ssum = 0;

	for (int i = 0; i < size; i++)
		Ssum += array[i];



	//осталось проверить на деле






	return 0;
}



double getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<double>(rand() * fraction * (max - min + 1) + min);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
