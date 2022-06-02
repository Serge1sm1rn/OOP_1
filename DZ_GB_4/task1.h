#pragma once
#include<iostream>
#include<string>
#include<vector>
#include <cassert>

using namespace std;

#undef max

namespace myLib
{
	template <typename _Ty>
	inline _Ty getUserInput(bool allowZero = false);
	std::string getUserInputTxt();
	unsigned short getUserSelectedTask(unsigned short qtyTask);

	template <typename T>
	void printArr(size_t size, T* Arr);

	void printArr(size_t size, bool NeedCnt, unsigned short* Arr);
	void printArr(size_t size, bool NeedCnt, int* Arr);
	void printArr(size_t size, bool NeedCnt, int* Arr, size_t medianPos);

	template <typename T>
	void printVect(const std::vector<T>& vec);

	string getNameFileFromUser(unsigned short indexF);
}

template <typename _Ty>
_Ty myLib::getUserInput(bool allowZero)
{
	while (true)
	{
		_Ty input;
		cin >> input;
		if (cin.fail() || (input <= 0) && !allowZero || (input < 0) && allowZero)
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

template<typename T>
void myLib::printArr(size_t size, T* Arr)
{
	cout << "Кол-во элементов = " << size << endl;
	for (size_t i = 0; i < size; i++)
	{
		cout << Arr[i] << ' ';
	}
	cout << endl;
}

template<typename T>
void myLib::printVect(const std::vector<T>& vec)
{
	cout << "Кол-во элементов = " << vec.size() << endl;
	for (auto i : vec)
	{
		cout << i << ' ';
	}
	cout << endl;
}

class ArrayInt
{
public:
	ArrayInt() : m_length(0), m_data(nullptr), m_arrPointer(nullptr)
	{}
	ArrayInt(int length);
	~ArrayInt() { delete[] m_arrPointer; };

	void erase();
	int getLength() { return m_length; };
	void resize(int newLength);
	void insertBefore(int value, int index);
	void push_back(int value) { insertBefore(value, m_length); }
	void pop_back();
	void pop_front();
	void sort();
	void print() const;

	int& operator[](int index);

private:
	int m_length;
	int* m_data;
	int* m_arrPointer;

	void transferDataAtoB(int* A, int* B, int amount);
	void qSort(int* s_arr, int first, int last);
};