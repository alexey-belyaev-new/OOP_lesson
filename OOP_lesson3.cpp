#include <iostream>
#include <cmath>
#include <algorithm>

double pi = 3.14159265;

using namespace std;

/*1. Создать абстрактный класс Figure (фигура). Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг). 
	Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб). Для всех классов создать конструкторы. 
	Для класса Figure добавить чисто виртуальную функцию area() (площадь). 
	Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.*/
class Figure
{
public:
	Figure() {};
	~Figure() {};
	virtual double area() = 0;
	virtual void print() {};
};
class Parallelogram : public Figure
{
public:
	Parallelogram() {};
	~Parallelogram() {};
	Parallelogram& set(double _a, double _b, double _corner) { a = _a; b = _b; corner = _corner; return *this; }
	virtual double area() override	{return a * b * sin(corner * pi / 180);}
	virtual void print() {
		cout << "Площадь параллелограмма, со сторонами a = "
			<< a << " , b = " << b << " и углом  между ними " 
			<< corner << " градусов равна: " << area() << endl;
	}
private:
	double a{}, b{}, corner{};
};

class Circle : public Figure
{
public:
	Circle() {};
	Circle& set(double _radius) { radius = _radius; return *this; };
	~Circle() {};
	virtual double area() override {return radius * radius * pi;}
	virtual void print()override { cout << "Площадь круга радиусом " << radius << " равна:" << area() << endl; }
private:
	double radius{};
};

class Rectangle : public Parallelogram 
{
public:
	Rectangle() {};
	~Rectangle() {};
	Rectangle& set(double _a, double _b) { a = _a; b = _b; return *this; }
	virtual double area() override { return a * b; }
	virtual void print()override {
		cout << "Площадь прямоугольника со сторонами а = " << a
			<< " и b = " << b << " равна:" << area() << endl;
	}

private:
	double a{}, b{};
};

class Square : public Parallelogram 
{
public:
	Square() {};
	~Square() {};
	Square set(double _a) { a = _a; return *this; }
	virtual double area() override { return a * a; }
	virtual void print()override { cout << "Площадь квадрата со стороной " << a << " равна:" << area() <<endl; }
private:
	double a{};
};

class Rhombus : public Parallelogram 
{
public:
	Rhombus() {};
	~Rhombus() {};
	Rhombus& set(double _d1, double _d2) { d1 = _d1; d2 = _d2; return *this; }
	virtual double area() override { return d1 * d2 / 2; }
	virtual void print()override {
		cout << "Площадь ромба с диагоналями d1 = " << d1
			<< " и d2 = " << d2 << " равна:" << area() << endl;
	}
private:
	double d1{}, d2{};
};

/*2. Создать класс Car (автомобиль) с полями company (компания) и model (модель).
	Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус). 
	От этих классов наследует класс Minivan (минивэн). 
	Создать конструкторы для каждого из классов, чтобы они выводили данные о классах. 
	Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы. 
	Обратить внимание на проблему «алмаз смерти».*/

class Car
{
public:
	
	Car(string _company, string _model)
	{
		company = _company;
		model = _model;
		cout << company << " " << model << endl; 
	};
	~Car() {};

protected:
	string company{}, model{};
};

class PassengerCar : virtual public Car
{
public:
	PassengerCar(string _company, string _model, int _weight ) : Car(_company, _model), weight(_weight)
	{
		cout << company << " " << model<<" " <<weight << endl; 
	};
	~PassengerCar() {};

protected:
	int weight{};
};

class Bus : virtual public Car
{
public:
	Bus(string _company, string _model, int _nomber_of_seats) : Car(_company, _model), nomber_of_seats(_nomber_of_seats)
	{
		cout << company << " " << model << " " << nomber_of_seats << endl;
	};
	~Bus() {};

protected:
	int nomber_of_seats{};
};

class Minivan : public PassengerCar, public Bus
{
public:
	Minivan (string _company, string _model, int _weight, int _nomber_of_seats, string _color) : 
		Car(_company, _model), PassengerCar(_company, _model, _weight), Bus(_company, _model, _nomber_of_seats), color(_color)
	{
		cout << company << " " << model << " " << weight << " " << nomber_of_seats << " " << color << endl;
	};
	~Minivan() {};

private:
	string color{};
};

/*3. Создать класс: Fraction (дробь). 
	Дробь имеет числитель и знаменатель (например, 3/7 или 9/2). Предусмотреть, чтобы знаменатель не был равен 0. 
	Перегрузить:
	математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
	унарный оператор (-)
	логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
	Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности, попробуйте перегрузить один через другой.
	Продемонстрировать использование перегруженных операторов.*/
class Fraction
{
public:
	Fraction(int _numerator, int _denominator) : numerator(_numerator), denominator(_denominator) 
	{
		if (_numerator == 0 || _denominator == 0) { cout << "введите числа отличные от 0" << endl; }
	};
	~Fraction() {};
	void print() { cout << numerator << " " << denominator << endl; };

	Fraction operator+ (Fraction fr) const
	{
		int newDen = NOK(denominator, fr.denominator);
		int newNum = (newDen / denominator) * numerator + (newDen / fr.denominator) * fr.numerator;
		
		return Fraction(newNum, newDen);
	}
	Fraction operator- (Fraction fr) const
	{
		int newDen = NOK(denominator, fr.denominator);
		int newNum = ((newDen / denominator) * numerator) - ((newDen / fr.denominator) * fr.numerator);
		if (newNum == 0) newDen = newNum;

		return Fraction(newNum, newDen);
	}
	Fraction operator* (Fraction fr) const
	{
		int newDen = denominator * fr.denominator;
		int newNum = numerator * fr.numerator;
		return Fraction(newNum, newDen);
	}
	Fraction operator/ (Fraction fr)
	{
		swap (fr.denominator, fr.numerator);
		int newDen = denominator * fr.denominator;
		int newNum = numerator * fr.numerator;
		return Fraction(newNum, newDen);
	}
	bool operator== (Fraction fr) 
	{
		if (numerator == fr.numerator && denominator == fr.denominator) return true;
		else return false;
	}
	bool operator!= (Fraction fr)
	{
		if (numerator != fr.numerator && denominator != fr.denominator) return true;
		else return false;
	}
	bool operator < (Fraction fr)
	{
		if (denominator == fr.denominator)
		{
			if (numerator < fr.numerator) return true;
			else return false;
		}
		else if(numerator == fr.numerator)
		{
			if (denominator > fr.denominator) return true;
			else return false;
		}
		else
		{
			int newDen = NOK(denominator, fr.denominator);
			int newNum = (newDen / denominator) * numerator;
			int newNum1 = (newDen / fr.denominator) * fr.numerator;
			if (newNum < newNum1) return true;
			else return false;
		}
	}

private:
	int numerator{}, denominator{};
	int NOK(int a, int b) const
	{
		int a1 = a, b1 = b;
		while (a != 0 && b != 0)
		{
			if (a > b) a %= b; else b %= a;
		}
		int nod = a + b;
		int nok = a1 * b1 / nod;
		return nok;
	};
};

int main()
{
	setlocale(0,"");
	cout << "---Задание 1.---" << endl;
	Parallelogram par;
	par.set(3,3,30).print();
	Circle cir;
	cir.set(5).print();
	Rectangle rec;
	rec.set(2, 3).print();
	Square sq;
	sq.set(4).print();
	Rhombus  rh;
	rh.set(5, 5).print();

	cout << "---Задание 2.---" << endl;
	Minivan mini("BMW", "Active Tourer", 2000, 6, "red");
	cout << endl;
	Bus bus("Mercedes-Benz", "Sprinter", 33);
	cout << endl;
	PassengerCar pas("KIA", "Rio", 1560);
	cout << endl;
	Car car("company", "model");
	
	Fraction fr(0, 7);
	Fraction fr1(6, 7);
	Fraction fr2(5, 9);
	Fraction fr5(18, 13);
	Fraction fr3 = fr + fr1;
	fr3.print();
	fr3 = fr - fr1;
	fr3.print();
	fr3 = fr * fr1;
	fr3.print();
	fr3 = fr / fr1;
	fr3.print();
	if (fr == fr1) cout << "Дроби равны!" << endl;
	if (fr2 != fr5) cout << "Дроби не равны!" << endl;
	if (fr2 < fr5) cout << "Дроби справа больше!" << endl;
}