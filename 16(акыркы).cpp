#include <iostream>

using namespace std;

template <typename T>
class my_vec
{
public:
	my_vec(my_vec & other)
	{
		my_vec temp;
		this->size = other.size;
		this->capacity = other.capacity;
		for (int i = 0; i < other.size; i++)
		{
			
		}
	}
private:
	int capacity; //переменный capacity
	int size;
	T * mas = new T[capacity];
};
