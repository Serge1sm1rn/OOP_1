#include<iostream>
#include<windows.h>
#include<vector>
#include<set>
#include"task1.h"


using namespace std;

int main() 
{
	setlocale(LC_ALL, "RU");

	cout << "Работа с шаблонным классом Pair1:" << endl;
	Pair1<int> p1(6, 9);
	cout << "Pair: " << p1.first() << ' ' << p1.second() << endl;
	const Pair1<double> p2(3.4, 7.8);
	cout << "Pair: " << p2.first() << ' ' << p2.second() << endl;
}
