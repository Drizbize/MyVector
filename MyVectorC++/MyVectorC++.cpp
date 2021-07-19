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

		if (size <= capacity)
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

		if (index == size || index == 0 && size == 0)
		{
			Push(value);
			return;
		}

		int current = size - 1;

		if (index > size)
		{
			if (index >= capacity)
			{
				capacity = index;
				CheckArray();
			}
			for (int i = 0; i < size; i++)
			{
				size++;
				if (current + 1 == index)
				{			
					array[++current] = value;
					return;
				}
				array[++current] = 0;
			}
		}

		CheckArray();
		for (int i = 0; i < size && index <= current; i++)
		{
			array[current + 1] = array[current];
			current--;
		}
		size++;
		array[index] = value;
	}

	void Delete()
	{
		delete[] array;
		array = nullptr;
		capacity = DEFAULT_ARRAY_SIZE;
		size = 0;
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

	vector.Insert(5,1000);
	vector.Print();
}