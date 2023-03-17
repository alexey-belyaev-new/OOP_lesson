#include <iostream>

using namespace std;
//-------------Задание 1.-------------//
/*1. Создать класс Person (человек) с полями: имя, возраст, пол и вес. 
Определить методы переназначения имени, изменения возраста и веса. 
Создать производный класс Student (студент), имеющий поле года обучения. 
Определить методы переназначения и увеличения этого значения. 
Создать счетчик количества созданных студентов. 
В функции main() создать несколько (не больше трёх) студентов. Вывести информацию о них*/
class Person
{
public:
	Person() {};
	~Person() {};

protected:
	string name;
	int age;
	char gender;
	double weight;
};

class Student : public Person
{
public:
	Student(string _name, int _age, char _gender, double _weignt, int _year_of_study) {
		name = _name;
		age = _age;
		gender = _gender;
		weight = _weignt;
		year_of_study = _year_of_study;
		count_students++;
	};
	~Student() { count_students--; };
	void setYear(int _year) { year_of_study = _year; }
	void inc_year_of_study(int _inc_year) { year_of_study = year_of_study + _inc_year; }
	void print_stud() { cout << "№" << count_students << " "
						<< "Имя: " << name << " "
						<< "возраст: " << age << " " 
						<< "пол: " << gender << " " 
						<< "рост: " << weight << " " 
						<< "год поступления: " <<year_of_study << " " << endl; }
private:
	int year_of_study;
	static int count_students;
};
int Student::count_students = 0;

//-------------Задание 2.-------------//
/*2. Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт).
У Fruit есть две переменные-члена: name (имя) и color (цвет). 
Добавить новый класс GrannySmith, который наследует класс Apple.*/
class Fruit
{
public:
	Fruit() {};
	~Fruit() {};
	string getName() { return name; }
	string getColor() { return color; }

protected:
	string name;
	string color;
};

class Apple : public Fruit
{
public:
	Apple(string _color) { name = "Apple"; color = _color; };
	Apple() {};
	~Apple() {};

private:

};

class Banana : public Fruit
{
public:
	Banana() { name = "Banana"; color = "yellow"; };
	~Banana() {};

private:

};

class Granny_Smith : public Apple
{
public:
	Granny_Smith() { name = "Granny Smith", color = "green"; };
	~Granny_Smith() {};

private:

};

int main()
{
	setlocale(LC_ALL, "RU");
	cout << "Задание 1." << endl;
	Student Ivanov("Ivanov", 20, 'M', 175.5, 2015);
	Ivanov.print_stud();
	Student Petrov("Petrov", 22, 'M', 172.8, 2014);
	Petrov.print_stud();
	Student Sidorov("Sidorov", 25, 'M', 181.2, 2010);
	Sidorov.print_stud();
	cout << endl;

	cout << "Задание 2." << endl;
	Apple a("red");
	Banana b;
	Granny_Smith c;
	cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	cout << "My " << c.getName() << " is " << c.getColor() << ".\n";


}
