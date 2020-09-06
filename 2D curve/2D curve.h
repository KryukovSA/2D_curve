#pragma once
#include <string>
#include <iostream>

#define PI 3.1417

using namespace std;

//базовый абстрактый класс
class Figure
{
public:
	virtual double CalculateArea() = 0;      //Вычисление площади
	virtual void printNAME() = 0;  //Вывод информации о фигуре
};


//класс элипса
class elips : public Figure
{
public:
	//инициализатор
	elips(double a_, double b_) : a(a_), b(b_){ }

	double CalculateArea(); //Вычисление площади
	void printNAME(); //Вывод названия (информации)
private:
	double a, b; // Длины полуосей
	const char name[8] =  " элипс ";
};


//класс окружности 
class circle : public Figure
{
	
	public:
		//инициализатор
		circle(double r_) : r(r_) { }

		double CalculateArea(); //Вычисление площади

		void printNAME(); //Вывод информации о фигуре


	private:
		double r; //Радиус окружности
		const char name1[13] = " окружность ";


};

