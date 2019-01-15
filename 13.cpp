#include <iostream>
#include <vector>

using namespace std;

template <typename Iterator, typename T>

/*
* В функции первый итератор будет налажен на i-тое число,
* а второе будет пробегать все элементы коллекции, кроме
* i - го элемента, суммировать их и сравнивать с числом с
*/

pair<bool, pair<Iterator, Iterator>>find_two_elements_with_sum(Iterator first, Iterator last, T c)
{
	pair<bool, pair<Iterator, Iterator>> temp;
	Iterator temp_iter1;
	Iterator temp_iter2;
	
	for (temp_iter1 = first; temp_iter1 != last; temp_iter1++)
	{
		for (temp_iter2 = first; temp_iter2 != last; temp_iter2++)
		{
			if (*temp_iter1 + *temp_iter2 == c && temp_iter2 != temp_iter1)
			{
				temp.first = true;
				temp.second.first = temp_iter1;
				temp.second.second = temp_iter2;
				return temp;
			}
		}
	}

	if (!temp.first)
	{
		cout << "Не найдено" << endl;
		temp.first = false;
		temp.second.first = first;
		temp.second.second = last - 1;
		return temp;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	vector<int> v = { 1, 2, 3, 4, 8, 6, 9, 0 };
	auto it1 = v.begin();
	auto it2 = v.end();
	pair<bool, pair<vector<int>::iterator, vector<int>::iterator>> val;
	val = find_two_elements_with_sum<vector<int>::iterator, int>(it1, it2, 10);
	cout << "Найдены значения: ";
	cout << *val.second.first << " ; " << *val.second.second << endl;
}
