#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

//������� ���������� �����
class Figure
{
public:
	virtual vector<double> get_first_derivative(double t) = 0;
	virtual vector<double> get_coordinates(double t) = 0;
	virtual void printNAME() = 0;  //����� ���������� � ������
	virtual ~Figure() {};
};


//����� ������
class elips : public Figure
{
public:
	elips(double a_, double b_) : a(a_), b(b_){ 
		if (a_ < 0 || b_ < 0) {
			throw std::runtime_error("semiaxis is a positive number");
		}
	}
	vector<double> get_coordinates(double t) override;
	vector<double> get_first_derivative(double t) override;
	void printNAME() override;
	~elips() override;
private:
	double a, b; 
	string name =  " ����� ";
};


//����� ���������� 
class circle : public Figure
{
	
	public:
		circle(double r_) : r(r_) { 
			if (r_ < 0) {
				throw std::runtime_error("radius is a positive number");
			}
		}
		vector<double> get_coordinates(double t) override;
		vector<double> get_first_derivative(double t) override;
		double get_radius() const { return r; }
		void printNAME() override;
		~circle() override;
	private:
		double r; //������ ����������
		string name = " ���������� ";
};

class spiral : public Figure {
	public:
		spiral(double r_, double step_) : r(r_), step(step_) {
			if (r_ < 0) {
				throw std::runtime_error("radius is a positive number");
			}
			if (step < 0) {
				throw std::runtime_error("step is a positive number");
			}
		}
		vector<double> get_coordinates(double t) override;
		vector<double> get_first_derivative(double t) override;
		void printNAME() override;
		~spiral() override;
	private:
		double r; //������ �������
		double step; //���
		string name = " ������� ";
};

double getRandomNumber(int min, int max);
double radii_all_figures(vector <Figure*>& circle_array);
void print_vec(vector<double> v);

struct pred
{
	bool operator()(Figure* dot1, Figure* dot2)
	{
		return static_cast<circle&>(*dot1).get_radius() < static_cast<circle&>(*dot2).get_radius();
	}
};