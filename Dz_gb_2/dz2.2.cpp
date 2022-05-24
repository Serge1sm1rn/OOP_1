
#include<iostream>
#include <cstdint>

class Fruit
{
public:
    std::string name;
    std::string color;

    Fruit(std::string name, std::string color) : name(name), color(color) {}

    std::string getName() { return name; }
    std::string getColor() { return color; }
};

class Banana : public Fruit
{
public:
    Banana(std::string name = "Banana", std::string color = "Yellow") : Fruit(name, color) {}
};

class Apple : public Fruit
{
protected:
    Apple(std::string name, std::string color): Fruit(name, color) {}

public:
    Apple(std::string color = "red")
        : Fruit("apple", color)
    {
    }
};

class GrannySmith : public Apple
{
public:
    GrannySmith()
        : Apple("Granny Smith apple", "green") {}
};

int main()
{
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";


    return 0;
};
