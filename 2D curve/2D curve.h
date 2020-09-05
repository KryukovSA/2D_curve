#pragma once

#include <iostream>

#define PI 3.1417

using namespace std;

//базовый абстрактый класс
class Figure
{
public:
	virtual double CalculateArea() = 0;      //Вычисление площади
	//virtual void Print(const char* name) = 0;  //Вывод информации о фигуре
};

//класс элипса
class elips : public Figure
{
public:
	//инициализатор
	elips(double a_, double b_) : a(a_), b(b_){ }

	double CalculateArea(); //Вычисление площади

private:
	double a, b; // Длины полуосей
};

//класс окружности 
class circle : public Figure
{
	
	public:
		//инициализатор
		circle(double r_) : r(r_) { }

		double CalculateArea(); //Вычисление площади

		//void Print(const char* name); //Вывод информации о фигуре


	private:
		double r; //Радиус окружности



};

