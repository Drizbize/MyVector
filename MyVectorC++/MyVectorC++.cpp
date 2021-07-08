// MyVectorC++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>

class Vector
{
public:
	const int DEFAULT_ARRAY_SIZE = 5;
	const int CAPACITY_INCREASE = 2;

	int capacity = DEFAULT_ARRAY_SIZE;
	int size = 0;	
	int* array;

	void Push(int value)
	{
		if (!array)
		{
			array = new int[DEFAULT_ARRAY_SIZE];
		}
		if (size == capacity)
		{
			capacity = capacity * CAPACITY_INCREASE;
			int* newArray = new int[capacity];
			for (int i = 0; size > i; i++)
			{
				newArray[i] = array[i];
			}
			delete[] array;
			array = newArray;		
		}
		array[size++] = value;
	}

	int Find(int FindNumber)
	{
		for (int i = 0; size > i; i++)
		{
			if (array[i] == FindNumber)
			{
				return i;
			}
		}
		return nullptr;
	}

	void Print()
	{
		for (int i = 0; size > i; i++)
		{
			std::cout << array[i] << " ";
		}
		std::cout << "\n";
	}
};

int main()
{
	Vector vector;
	vector.Push(10);
	vector.Push(20);
	vector.Push(30);
	vector.Push(40);
	vector.Push(50);
	vector.Push(60);
	vector.Push(70);

	vector.Print();
	std::cout << vector.Find(110);
}