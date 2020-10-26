#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <ctime>

#define PI 3.1417

using namespace std;

//базовый абстрактый класс
class Figure
{
public:
	virtual double CalculateArea() = 0;      //Вычисление площади
	virtual void printNAME() = 0;  //Вывод информации о фигуре
	virtual ~Figure() {};
};


//класс элипса
class elips : public Figure
{
public:
	elips(double a_, double b_) : a(a_), b(b_){ 
		if (a_ < 0 || b_ < 0) {
			throw std::runtime_error("semiaxis is a positive number");
		}
	}
	double CalculateArea() override;
	void printNAME() override;
	~elips() override;
private:
	double a, b; 
	const char name[8] =  " элипс ";
};


//класс окружности 
class circle : public Figure
{
	
	public:
		circle(double r_) : r(r_) { 
			if (r_ < 0) {
				throw std::runtime_error("radius is a positive number");
			}
		}
		double CalculateArea() override;
		void printNAME() override;
		~circle() override;
	private:
		double r; //Радиус окружности
		const char name1[13] = " окружность ";


};

double getRandomNumber(int min, int max);
void sortArea(vector<double>&array);
double area_all_figures(vector<double>&array);