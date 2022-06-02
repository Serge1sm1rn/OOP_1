#include"task2.h"

#include<iostream>

#include<vector>
#include<set>


using namespace std;
using namespace myLib;

int main()
{
	setlocale(LC_ALL, "RU");

	cout << "Поиск кол-ва различных элементов: " << endl;
	vector<int32_t> vecArr{ 0,1,2,4,1,5,3,8,1,-9,1,6,7,5,3,2,11,6,3,1,2 };
	printVect<int32_t>(vecArr);

	set<int32_t> s(&vecArr[0], &vecArr[20]);
	cout << "Различных элементов = ";
	cout << s.size() << endl;
}
