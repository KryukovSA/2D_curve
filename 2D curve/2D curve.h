#pragma once

#include <iostream>

#define PI 3.1417

using namespace std;

//������� ���������� �����
class Figure
{
public:
	virtual double CalculateArea() = 0;      //���������� �������
	//virtual void Print(const char* name) = 0;  //����� ���������� � ������
};

//����� ������
class elips : public Figure
{
public:
	//�������������
	elips(double a_, double b_) : a(a_), b(b_){ }

	double CalculateArea(); //���������� �������

private:
	double a, b; // ����� ��������
};

//����� ���������� 
class circle : public Figure
{
	
	public:
		//�������������
		circle(double r_) : r(r_) { }

		double CalculateArea(); //���������� �������

		//void Print(const char* name); //����� ���������� � ������


	private:
		double r; //������ ����������



};

