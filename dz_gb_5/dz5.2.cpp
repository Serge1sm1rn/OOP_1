#include<iostream>
#include<windows.h>
#include<vector>
#include<set>
#include"task2.h"


using namespace std;




int main()
{
	setlocale(LC_ALL, "RU");

	cout << "Работа с шаблонным классом Pair:" << endl;
	Pair<int, double> p1(6, 7.8);
	cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
	const Pair<double, int> p2(3.4, 5);
	cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
}