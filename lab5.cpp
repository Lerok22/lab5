#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <locale.h>

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "rus");
	int n;
	int k = 0;
	printf("Введите количество элементов для матрицы:");
	scanf("%d", &n);
	int* b = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		b[i] = 0;
	}
	int** a = (int**)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		a[i] = (int*)malloc(n * sizeof(int));
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			a[i][j] = rand() % 2;

			if (i == j)
			{
				a[i][j] = 0;

			}
			a[j][i] = a[i][j];

		}

	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%-5d  ", a[i][j]);

		}
		printf("\n");
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (a[i][j] == 1)
			{
				k++;
			}
		}
	}
	printf("\n");
	printf("\n");
	printf("Размер графа:%d", k);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{

				if (a[i][j] == 1)
				{
					b[i]++;
				}


		}
		
	}
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("Степень вершины %d: %d ", i+1, b[i]);
		printf("\n");
	}
	printf("\n");
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		if(b[i]==0)
			printf("Изолированная вершина: %d \n", i + 1);
		
		if (b[i] == 1)
			printf("Концевая вершина: %d \n", i + 1);
		
		if (b[i] == n - 1)
			printf("Доминирующая вершина: %d\n", i + 1);
	}
	printf("\n");
	printf("\n");
	int** In = (int**)malloc(n * sizeof(int));
	for (int p = 0; p < n; p++)
	{
		In[p] = (int*)malloc(k * sizeof(int));
	}
	for (int p = 0; p < n; p++)
	{
		for (int j = 0; j < n; j++)
		{
			In[p][j] = 0;
		}
	}
	
	int p = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (a[i][j] == 1)
			{
				In[p][j] = a[i][j];
				In[p][i] = a[i][j];
				p++;
			}
		}
	}
	for (int p = 0; p < k; p++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%-5d  ", In[p][j]);

		}
		printf("\n");
	}
	for (int j = 0; j < n; j++)
	{
		b[j] = 0;
	}
	for (int j = 0; j < n; j++)
	{
		for (int p = 0; p < n; p++)
		{

			if (In[p][j] == 1)
			{
				b[j]++;
			}

		}
	}
	for (int j = 0; j < n; j++)
	{
		printf("Степень вершины %d: %d ", j + 1, b[j]);
		printf("\n");
	}
	printf("\n");
	printf("\n");
	for (int j = 0; j < n; j++)
	{
		if (b[j] == 0)
			printf("Изолированная вершина: %d \n", j + 1);

		if (b[j] == 1)
			printf("Концевая вершина: %d \n", j + 1);

		if (b[j] == n - 1)
			printf("Доминирующая вершина: %d\n", j + 1);
	}
	return 0;

}