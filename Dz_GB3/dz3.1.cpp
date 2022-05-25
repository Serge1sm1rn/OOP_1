#include"var1.h"
#define _USE_MATH_DEFINES
#include<math.h>
#include<iostream>
#include<windows.h>
#include"MyLib.h"

using namespace myLib;
using namespace std;
using namespace figures;

float Parallelogram::area()
{
	return static_cast<float>(a) * h;
}

void Figure::printArea()
{
	std::cout << "Площадь S = " << area() << std::endl;
}

float Circle::area()
{
	return M_PI * powl(r, 2);
}

float Rhombus::area()
{
	return static_cast<float>(a) * h / 2;
}
int main()
{
	setlocale(LC_ALL, "Russian");

	uint16_t val = 0;
	cout << "Считаем площади фигур:";
	do
	{
		cout << endl << endl;
		cout << "Выберите фигуру:" << endl
			<< "1 - Параллелограмм" << endl
			<< "2 - Прямоугольник" << endl
			<< "3 - Квадрат" << endl
			<< "4 - Ромб" << endl
			<< "5 - Круг" << endl << endl
			<< "0 - Выход" << endl << endl
			<< "Ввод: ";
		val = getUserInput<uint16_t>(true);
		cout << endl;

		uint16_t a, b, h, d1, d2, r;
		Figure* rFig = nullptr;

		switch (val)
		{
		case 1:
			cout << "Параллелограмм:" << endl;
			cout << "Основание a = ";
			a = getUserInput<uint16_t>();
			cout << "Высота h = ";
			h = getUserInput<uint16_t>();
			rFig = new Parallelogram(a, h);
			break;
		case 2:
			cout << "Прямоугольник:" << endl;
			cout << "Длинна a = ";
			a = getUserInput<uint16_t>();
			cout << "Ширина b = ";
			b = getUserInput<uint16_t>();
			rFig = new figures::Rectangle(a, b);
			break;
		case 3:
			cout << "Квадрат:" << endl;
			cout << "Длинна a = ";
			a = getUserInput<uint16_t>();
			rFig = new Square(a);
			break;
		case 4:
			cout << "Ромб:" << endl;
			cout << "Диагональ d1 = ";
			d1 = getUserInput<uint16_t>();
			cout << "Диагональ d2 = ";
			d2 = getUserInput<uint16_t>();
			rFig = new Rhombus(d1, d2);
			break;
		case 5:
			cout << "Круг:" << endl;
			cout << "Радиус r = ";
			r = getUserInput<uint16_t>();
			rFig = new Circle(r);
			break;
		}

		if (val)
		{
			rFig->printArea();
			delete rFig;
		}
	} while (val != 0);

	return 0;
}