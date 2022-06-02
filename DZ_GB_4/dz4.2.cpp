#include"task2.h"

#include<iostream>

#include<vector>
#include<set>


using namespace std;
using namespace myLib;


namespace myLib
{
	std::string getUserInputTxt()
	{
		while (true)
		{
			std::string input;
			cin >> input;
			if (cin.fail())
			{
				cout << "Ошибка ввода, повторите ввод: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				return input;
			}
		}
	}

	unsigned short getUserSelectedTask(unsigned short qtyTask)
	{
		unsigned short taskNumber = 0;
		do
		{
			cout << "Введите номер задачи от 1 до " << qtyTask << ":" << endl;
			taskNumber = getUserInput<int>(false);
		} while (taskNumber > qtyTask || taskNumber < 1);

		cout << endl;

		return taskNumber;
	}

	void printArr(size_t size, bool NeedCnt, unsigned short* Arr)
	{
		if (NeedCnt) cout << "Кол-во элементов = " << size << endl;
		for (size_t i = 0; i < size; i++)
		{
			cout << Arr[i] << ' ';
		}
		cout << endl;
	}

	void printArr(size_t size, bool NeedCnt, int* Arr)
	{
		if (NeedCnt) cout << "Кол-во элементов = " << size << endl;
		for (size_t i = 0; i < size; i++)
		{
			cout << Arr[i] << ' ';
		}
		cout << endl;
	}

	void printArr(size_t size, bool NeedCnt, int* Arr, size_t medianPos)
	{
		if (NeedCnt) cout << "Кол-во элементов = " << size << endl;
		for (size_t i = 0; i < size; i++)
		{
			if (medianPos > 0 && medianPos == i) cout << "|| ";
			cout << Arr[i] << ' ';
		}
		cout << endl;
	}

	string getNameFileFromUser(unsigned short indexF)
	{
		cout << "Введите имя";
		switch (indexF)
		{
		case 0:
			break;
		case 100:
			cout << " Конечного";
			break;
		default:
			cout << " " << indexF << "го";
			break;
		}
		cout << " файла(без расширения): ";
		string s;
		cin >> s;

		return s;
	}
}


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