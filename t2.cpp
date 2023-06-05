// Вариант 4;
// Решение СЛАУ методом Жордана - Гаусса;
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


void PrintMatrix(double* ptr[], const unsigned char SIZE_R, const unsigned char SIZE_C)
{
	for (int i = 0; i < SIZE_R; i++) {
		for (int j = 0; j < SIZE_C; j++) {
			cout << setw(9) << ptr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


int main()
{
	const unsigned char SIZE = 5;

	double matrix[][SIZE + 1] = { {-0.69, -0.04, 0.52, -0.7, 0.53, 0.59},
								{-0.22, -0.49, -0.96, 0.95, 0.27, 0.81},
								{0.15, 0.55, 0.33, -0.18, 0.14, 0.93},
								{0.47, -0.53, 0.0, 0.97, -0.26, 0.52},
								{0.4, 0.94, -0.41, -0.04, 0.52, -0.74} };
	double result[] = { 0.0, 0.0, 0.0, 0.0, 0.0 };

	// создание массива указателей массива matrix
	double* ptr[SIZE]{};
	for (int i = 0; i < SIZE; i++)
		ptr[i] = matrix[i];



	PrintMatrix(ptr, SIZE, SIZE + 1);

	int m = 0;
	//прямой ход;
	for (int k = 0; k < SIZE; k++)
	{
		// проверка на 0;
		if (abs(matrix[k][k] < 0.000001))
		{
			m = k + 1;
			while (abs(matrix[m][k] < 0.000001))
			{
				m += 1;
			}
			for (int j = 0; j < SIZE + 1; j++)
			{
				double temp_var = matrix[k][j];
				matrix[k][j] = matrix[m][j];
				matrix[m][j] = temp_var;
			}
		}


		// правило прямоугольника по Жордану-Гауссу;
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = k + 1; j < SIZE + 1; j++)
			{
				if (i != k)
					matrix[i][j] = (matrix[i][j] * matrix[k][k] - matrix[k][j] * matrix[i][k]) / matrix[k][k];
			}
		}


		// обнуление k-го столбца;
		for (int i = 0; i < SIZE; i++)
		{
			if (i != k)
			{
				matrix[i][k] = 0;
			}
		}

		// деление элементов k-й строки на matrix[k][k];
		for (int j = SIZE; j >= 0; j--)
		{
			matrix[k][j] /= matrix[k][k];
		}

		// вывод матрицы в консоль;
		PrintMatrix(ptr, SIZE, SIZE + 1);

	}


	cout << "Answer:" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << "x" << i + 1 << " = " << matrix[i][5] << endl;
	}
	return 0;
}
