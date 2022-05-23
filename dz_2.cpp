#include<iostream>
#include <cstdint> 
#include <string> 
using namespace std;

enum  Gender
{
    GENDER_MAN = 0,
    GENDER_WOMAN = 0
};

class Person
{
private:
    string m_name;
    int m_age;
    Gender m_gender;
    float m_weight;
public:
    Person(string name, int age, Gender gender, float weight) :
        m_name(name), m_age(age), m_gender(gender), m_weight(weight) {}

    void setName(string name = "") // Имя
    {
        if (name == "")
        {
            cout << "Введите  имя: ";
            cin >> name;
        }
        else
            name = name;
    }

    void setAge(int age = 0) //Возраст
    {
        if (age == 0)
        {
            cout << "Введите возраст: ";
            cin >> age;
        }
        else
            age = age;
    }

    void setWeight(float weight = 0.0) //Вес
    {
        if (weight == 0)
        {
            cout << "Введите вес: ";
            cin >> weight;
        }
        else
            weight = weight;
    }

    void printInfo() const
    {
        cout << "Имя: " << m_name << std::endl
             << "Возраст: " << m_age << std::endl
             << "Пол: " << (m_gender == GENDER_MAN ? "муж" : "жен") << endl
             << "Вес: " << m_weight << std::endl;
    }
};

class Student : public Person
{
private:
    static int count;
    int year; 
public:
    Student(string name, int age, Gender gender, float weight, int year) : Person(name, age, gender, weight), year(year)
    {
        count++;
    }

    static void printCount() // Кол-во студентов
    {
        cout << "Количество студентов: " << count << endl;
    }

    void setYearStudy(int yos = 0)
    {
        if (yos == 0)
        {
            cout << "Введите год обучения: ";
            cin >> year;
        }
        else
            year = yos;
    }

    void incYear()
    {
        year++;
    }

    void printInfo() const //Год начала обучения
    {
        Person::printInfo();
        cout << "Год обучения: " << year << endl;
    }

    ~Student()
    {
        count--;
    }
};
int Student::count = 0;

int main()
{
    setlocale(LC_ALL, "Russian");

    Student First("Николай", 18, GENDER_MAN, 64., 2018);
    First.printInfo();
    Student::printCount();

    cout <<   endl;

    Student Sekond("Андрей", 22, GENDER_MAN, 97., 2014);
    Sekond.printInfo();
    Student::printCount();
    
    cout << endl;

    Student Third ("Мария", 31, GENDER_WOMAN, 54., 2020);
    Third.printInfo();
    Student::printCount();

   
    
    cout << endl;
    
    return 0;

};
