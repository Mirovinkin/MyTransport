// MyTransport.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <math.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <typeinfo>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
//#include <cstdlib>
#include <ctype.h>

using namespace std;

class Car
{
private:
    unsigned int _size;
    char* _make = new char[_size];
    int _cylindr;
    double _power;
    string str;
    

public:

    Car() {};
    Car(const char* Make, const int& Cylindr, const double& Power, const int& Size)
    {
        _size = Size;
        for (int i = 0; i < _size; i++)
        {
            _make[i] = Make[i];
        }
        _cylindr = Cylindr;
        _power = Power;
    }
    char* GetMake() { return _make; };
    int GetCylindr() { return _cylindr; };

    void PrintData() {
        str = _make;
        cout << "Модель: " << str << "\nКоличество цилиндров" << _cylindr << "\nМощность: " << _power << "\n";
    }
    Car( Car&& CarN):_cylindr(CarN._cylindr) {
        _cylindr = CarN._cylindr;
        CarN._cylindr = 0;
    }
    ~Car() {};
};

class Truck : public Car
{
private:
    double _bodylift;
public:
    Truck() {};
    Truck(const double& Bodylift) :_bodylift(Bodylift) {};

    double GetBodylift() { return _bodylift; };
    void PrintTruckData() {
        cout << "Грузоподъемность: " << _bodylift << endl;
    }

    Truck(Truck&& TruckN) : _bodylift(TruckN._bodylift) {
        _bodylift = TruckN._bodylift;
        TruckN._bodylift = 0;
    }

    ~Truck() {};
};
int main()
{
    setlocale(LC_ALL, "RUS");

    Truck truck1;
}