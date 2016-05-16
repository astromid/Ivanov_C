#include <numeric>
#include <vector>
#include <array>

#define N 3
using namespace std;

array< array<float, N>, N> matrix{ {
	{2,1,-1},
	{-3,-1,2},
	{-2,1,2}
} };

array<float, N> Solve(array< array<float, N>, N> matrix)
{
	array<float, N> x;
	//приведение матрицы к верхнетреугольному виду
	for (int i = 0; i < N; ++i)
	{
		float coeff = matrix[i][i];
		for (int j = N; j >= i; j--)
		{
			matrix[i][j] /= coeff;
		}
		for (int j = i + 1; j < N; j++)
		{
			float coef = matrix[j][i];
			for (int k = N; k >= i; --k)
			{
				matrix[j][k] -= coef*matrix[i][k];
			}
		}
	}
	//последовательное исключение неизвестных
	x[N - 1] = matrix[N - 1][N];
	for (int i = N - 2; i >= 0; --i)
	{
		x[i] = matrix[i][N];
		for (int j = i + 1; j < N; j++)
		{
			x[i] -= matrix[i][j] * x[j];
		}
	}
	return x;
}

int main()
{
	array<float, N> x = Solve(matrix);
	return 0;
}