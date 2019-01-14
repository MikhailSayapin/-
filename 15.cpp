#include <iostream>

using namespace std;

class my_string
{
	int size;
	int capacity;
	char *str = nullptr;

public:
	my_string(const my_string & other)
	{
		size = other.size;
		capacity = other.capacity;
		str = new char[size];
		for (int i = 0; i < size; i++)
		{
			str[i] = other.str[i];
		}
	}

	my_string()
	{
		str = nullptr;
		size = capacity = 0;
	}

	my_string(my_string && other)
	{
		str = other.str;
		other.str = nullptr;
		other.size = other.capacity = 0;
	}

	~my_string()
	{
		delete str;
		capacity = size = 0;
	}

	my_string(const char * other) //вопрос
	{
		size = sizeof(other)+100;
		capacity = size + 10;
		str = new char[capacity];

		for (int i = 0; i < size; i++)
		{
			str[i] = other[i]; //Вопрос
		}
	}

	char & operator[](int curr)
	{
		return str[curr];
	}

	my_string & operator=(const my_string & other) //оператор перемещения
	{
		this->size = other.size;
		this->capacity = other.capacity;
		str = new char[size];
		for (int i = 0; i < size; i++)
		{
			str[i] = other.str[i];
		}
		return *this;
	}

	my_string & operator=(my_string && other) // перегрузка оператора для перемещения
	{
		str = other.str;
		other.str = 0;
		other.capacity = other.size = 0;
	}

	void append(const char * other)
	{
		for (int i = size; i < sizeof(other); i++)
		{
			if(size < capacity)
				str[i] = other[i];
			else
			{
				capacity *= 2;
				char * str_temp = new char[capacity];
				for (int i = 0; i < sizeof(str); i++)
				{
					str_temp[i] = str[i];
				}
				str = str_temp;
				delete str_temp;

				str[i] = other[i];
			}
		}
	}
};


int main()
{
	my_string str1("thisisstr1");
	my_string str2(str1);

	my_string str3("this_is_str3");
	my_string str4 = str3;
	str3.append("dopolnenie");
	for (int i = 0; i < 50; i++)
		cout << str3[i];
	
}
