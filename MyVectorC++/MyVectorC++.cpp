// MyVectorC++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>

class Vector
{
private:
	void CheckArray()
	{
		if (!array)
		{
			array = new int[DEFAULT_ARRAY_SIZE];
		}

		if (size == capacity)
		{
			capacity *= CAPACITY_INCREASE;
			int* newArray = new int[capacity];

			for (int i = 0; i < size; i++)
			{
				newArray[i] = array[i];
			}

			delete[] array;
			array = newArray;
		}
	}
public:
	const int DEFAULT_ARRAY_SIZE = 5;
	const int CAPACITY_INCREASE = 2;

	int capacity = DEFAULT_ARRAY_SIZE;
	int size = 0;	
	int* array;

	void Push(int value)
	{
		CheckArray();
		array[size++] = value;
	}

	void Insert(int value, int index)
	{
		if (index < 0)
		{
			return;
		}
		CheckArray();

		if (index == size + 1 || index == 0 && size == 0)
		{
			Push(value);
			return;
		}

		int current = size - 1;

		if (index > size)
		{
			for (int i = 0; i < size; i++)
			{
				CheckArray();
				if (current + 1 == index)
				{
					array[current++] = value;
				}
				array[current++] = 0;
				size++;
			}
			return;
		}

		for (int i = 0; i < size && index <= current; i++)
		{
			array[current + 1] = array[current];
			current--;
		}
		size++;
		array[index] = value;
	}

	int Find(int FindNumber)
	{
		for (int i = 0; i < size; i++)
		{
			if (array[i] == FindNumber)
			{
				return i;
			}
		}
		return -1;
	}

	int FindAt(int index)
	{
		return array[index];
	}

	void Print()
	{
		for (int i = 0; i < size; i++)
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
	vector.Insert(5,8);
	vector.Print();
}