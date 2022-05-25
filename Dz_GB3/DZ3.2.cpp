#include"var2.h"
#include<iostream>

using namespace std;

void Car::carCreated()
{
	cout << "Create class car: Company = '" << company << "', Model = '" << model << "'" << endl;
}

Car::~Car()
{
	cout << "Class Car " << company << " " << model << " crashed" << endl;
}

void PassengerCar::pasCarCreated()
{
	cout << "Create class PassengerCar: Company = '" << company << "', Model = '" << model << "'" << endl;
}

PassengerCar::~PassengerCar()
{
	cout << "Class PassengerCar " << company << " " << model << " crashed" << endl;
}

void Bus::busCreated()
{
	cout << "Create class Bus: Company = '" << company << "', Model = '" << model << "'" << endl;
}

Bus::~Bus()
{
	cout << "Class Bus " << company << " " << model << " crashed" << endl;
}

void Minivan::minivanCreated()
{
	cout << "Create class Minivan: Company = '" << company << "', Model = '" << model << "'" << endl;
}

Minivan::~Minivan()
{
	
	cout << "Class Minivan " << company << " " << model << " crashed" << endl;
}
int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Работа с классом Car и его наследниками:" << endl << endl;
	Car car;
	PassengerCar pasCar("Audi", "A5");
	Bus bus("Mercedess", "E-200");
	Minivan minivan("Opel", "Omega B");

	return 0;
};