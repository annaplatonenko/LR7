// Лабораторная работа №7
// Вариант 5
// Для каждого варианта разработать шаблон соответствующего класса, 
// где поля могут иметь различные типы данных (некоторые поля могут быть статическими).
// Предусмотреть наличие в классе указанных методов и перегруженных операций.
// Название класса - множество;
// Поля: Элементы множества, текущее количество элементов
// Методы: Проверка на включение элемента в множество, вывод на экран, удаление элемента из множества
// Перегружаемые функции: += (добавление элемента в множество), * (пересечение множеств)

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

template <class T>
class Set
{
private:
	T* mass;
	int size;

public:
	Set()
	{
		mass = new T[0];
		size = 0;
	}
	~Set()
	{
	}

	Set<T> operator+= (T x)
	{
		if (!Proverka (x))
		{
			T* buff = new T[size + 1];

			for (int i = 0; i < size; i++)
			{
				buff[i] = mass[i];
			}
			buff[size] = x;
			++size;

			delete mass;
			mass = buff;
		}

		return *this;
	}

	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << mass[i] << " ";
		}
		cout << endl;
	}

	bool Proverka(T a)
	{
		for (int i = 0; i < size; i++)
		{
			if (mass[i] == a)
			{
				return true;
			} 
			
		}
		return false;
	}

	Set<T> operator *(Set<T> setone)
	{
		Set<T> result;
		for (T i = 0; i < size; i++)
		{
			if (setone.Proverka(this->mass[i]))
			{
				result += this->mass[i];
			}
		}
		return result;
	}

	Set<T> Delete (T num)
	{
		if (num>=0 && num<size)
		{
			--size;
			T* buff = new T[size];

			for (T i = 0; i < num; i++)
			{
				buff[i] = mass[i];
			}

			for (T i = num; i < size; i++)
			{
				buff[i] = mass[i+1];
			}

			delete mass;
			mass = buff;
		}

		return *this;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	Set<int> set;
	set += 1;
	set += 2;
	set += 3;
	set += 4;
	set += 5;
	set += 6;
	set += 7;
	set += 8;
	set += 9;
	set += 10;
	cout << "Первое множество: ";
	set.Print();
	cout << "Есть ли число 6 в первом множестве? " << (set.Proverka(6)?"Yes":"No") << endl; 
	
	Set<int> setone;
	setone += 4;
	setone += 5;
	setone += 6;
	setone += 7;
	setone += 8;
	cout << "Второе множество: ";
	setone.Print();

	Set<int> set3 = set * setone;
	cout << "Пересечение множеств: ";
	set3.Print();

	set.Delete(3);
	cout << "Удаление третьего элемента: ";
	set.Print();

	Set<char> setone4;
	setone4 += 'h';
	setone4 += 'e';
	setone4 += 'l';
	setone4 += 'p';
	cout << "Буквенное множество: ";
	setone4.Print();
}