#include<iostream>
#include<windows.h>
#include<vector>
#include<set>
#include"task3.h"


using namespace std;



int main()
{
	setlocale(LC_ALL, "RU");

cout << "Работа с шаблонным классом Pair:" << endl;
StringValuePair<int> svp("Amazing", 7);
std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
}
