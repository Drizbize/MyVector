#include <iostream>

class Vector
{
public:
	const int DEFAULT_ARRAY_SIZE = 5;
	const int CAPACITY_INCREASE = 2;

	int capacity = DEFAULT_ARRAY_SIZE;
	int size = 0;
	int* array = nullptr;

	void Push(int value)
	{
		CheckArray(size + 1);
		array[size++] = value;
	}

	void Insert(int value, int index)
	{
		if (index < 0)
		{
			return;
		}

		if (index == size)
		{
			Push(value);
			return;
		}

		if (index > size)
		{
			CheckArray(index);

			for (int i = size; i < index; i++)
			{
				array[i] = 0;
			}

			array[index] = value;
			size = index + 1;
		}
		else
		{
			CheckArray(size + 1);

			for (int i = size; i >= index; i--)
			{
				array[i + 1] = array[i];
			}

			array[index] = value;
			size++;
		}
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

private:
	void CheckArray(int cap = 0)
	{
		if (!array)
		{
			array = cap < DEFAULT_ARRAY_SIZE ? new int[DEFAULT_ARRAY_SIZE] : new int[cap];
			size = 0;
		}

		if (capacity <= cap)
		{
			while (capacity <= cap)
			{
				capacity *= CAPACITY_INCREASE;
			}

			int* newArray = new int[capacity];

			for (int i = 0; i < size; i++)
			{
				newArray[i] = array[i];
			}

			delete[] array;
			array = newArray;
		}
	}
};

int main()
{
	Vector vector;
	vector.Push(10);
	vector.Push(20);
	vector.Push(30);
	vector.Push(40);

	vector.Insert(5, 0);
	vector.Insert(15, 3);
	vector.Insert(25, 20);
	vector.Print();
}