#include <iostream>

using namespace std;

template <typename T>
class my_vec
{
public:
	my_vec(const my_vec & other)
	{
		my_vec temp;
		this->size = other.size;
		this->capacity = other.capacity;
		mas = new T[size];
		for (int i = 0; i < other.size; i++)
		{
			mas[i] = other.mas[i]; //здесь ошибка
		}
	}

	my_vec(my_vec && other)
	{
		mas = other; //присваивается адрес
		other.mas = nullptr;
		other.capacity = other.size = 0;
	}

	my_vec()
	{
		size = 0;
		capacity = 8;
		mas = new T[capacity];
	}

	~my_vec()
	{
		delete mas;
		capacity = size = 0;
	}

	void push_back(T data)
	{
		if (size < capacity)
		{
			*mas[size] = data;
			size++;
		}

		else
		{
			capacity *= 2;
			T * temp = new T[capacity];
			for (int i = 0; i < size; i++)
			{
				temp[i] = mas[i];
			}
			mas = temp;
		}
	}
private:
	int capacity; //переменный capacity
	int size;
	T * mas;
};

int main()
{
	my_vec<int> mv1;
	//mv1.push_back(2);
	my_vec<int> mv2(mv1);
}
