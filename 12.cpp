#include <iostream>
#include <future>
#include <vector>

using namespace std;

template <class T>
using Matrix = vector<vector <T>>;

template <class T>
Matrix<T>mult(const Matrix<T> & M1, const Matrix<T> & M2)
{
	M1.reserve(100);
	M2.reserve(100);
	Matrix<T> M_temp;
	M_temp.reserve(100);

	for (int i = 0; i < M1.size(); i++)
	{
		for (int j = 0; j < sizeof(M2.size()) / sizeof(T); j++) 
		{
			M_temp[i][j] = 0;

			for (int k = 0; k < sizeof(M1.size()) / sizeof(T); k++)
				M_temp[i][j] += M1[i][k] * M2[k][j];
		}
	}
	return M_temp;
}

int main()
{
	Matrix<int> M1;
	Matrix<int> M2;
	Matrix<int> M_rez;
	M_rez.reserve(100);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			M1[i][j] = rand() % 10;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			M2[i][j] = rand() % 50;
		}
	}

	M_rez = mult(M1, M2);
}
