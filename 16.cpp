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
			mas[i] = other.mas[i];
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
		size = 6;
		capacity = 8;
		mas = nullptr;
	}

	~my_vec()
	{
		delete mas;
	}

	void push_back(T data)
	{
		mas = new T[size];

		if (size <= capacity)
		{
			*mas[size] = data;
			size++;
		}

		else
			capacity *= 2;
	}
private:
	int capacity; //переменный capacity
	int size;
	T * mas;
};

int main()
{
	my_vec<int> mv1;
	my_vec<int> mv2(mv1);

	//mv1.push_back(2);
}
