#include <iostream>
#include <fstream>
#include <clocale>
#include <Windows.h>
#include <ctime>
using namespace std;

//1
void add_line(int **&p, int &n, int m)
{
	int** tmp;
	//выделили место дл€ массива указателей на одно место больше
	tmp = new int*[n + 1];
	//перекопировали адреса дл€ всех одномерных массивов
	for (size_t i = 0; i < n; i++)
		tmp[i + 1] = p[i];
	//под последнюю новую €чейку выдел€ем место дл€ массива целых чисел
	tmp[0] = new int[m];
	//заполн€ем нул€ми
	for (size_t i = 0; i < m; i++)
		tmp[0][i] = 0;

	delete[] p;
	p = tmp;
	n++;
}
//2
void add_stolb(int **&p, int &n, int m, int k)
{
	int** tmp = new int*[n + 1];
	for (size_t i = 0; i < k; i++)
	{
		tmp[i] = p[i];
	}
	tmp[k] = new int[m];
	for (size_t i = 0; i < m; i++)
	{
		tmp[k][i] = 0;
	}
	for (size_t i = k; i < n; i++)
	{
		tmp[i + 1] = p[i];
	}

	delete[] p;
	p = tmp;
	n++;
}
//3
//void delete_line()
//{
//	int **a;
//	int  n, h, l, i, j;
//	cout << "vvedite nomer stroki kotoryjy xotite ydalit' : ";
//	cin >> h;
//	cout << endl;
//	cout << "vvedite nomer stolbca kotorij xotite ydalit' : ";
//	cin >> l;
//	cout << endl;
//
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = l - 1; j<n - 1; j++)
//		{
//			a[i][j] = a[i][j + 1];
//		}
//	}
//	a = new int*[n];
//	for (int i = h - 1; i<n - 1; i++)
//		a[i] = a[i + 1];
//	cout << endl << endl;
//	for (int i = 0; i<n - 1; i++)
//	{
//		for (int j = 0; j<n - 1; j++)
//		{
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
//}

void add_first_colomn(int** &p, int n, int &m)
{
	int **tmp = new int *[n];
	for (size_t i = 0; i < n; i++)
	{
		tmp[i] = new int[n + 1];
	}
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			tmp[i][j + 1] = p[i][j];
		}
	}
	for (size_t i = 0; i < n; i++)
	{
		tmp[i][0] = 0;
	}
	for (size_t i = 0; i < n; i++)
	{
		delete[] p[i];
	}
	delete[] p;
	p = tmp;
	n++;
}

void fill_matrix(int** pp, int n, int m)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			pp[i][j] = rand() % 21;
		}
	}
}
void print_matrix(int** pp, int n, int m)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			cout << pp[i][j] << " ";
		}
		cout << endl;
	}
}


int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));

	/*
	ѕод одинарный указатель можно записать только одинарный динамический массив.
	ƒвумерный массив - двойной указатель.
	*/

	/*int *p, **pp;

	pp = new int*[5];

	for (size_t i = 0; i < 5; i++)
	{
	pp[i] = new int[i+1];
	cout << **pp << endl;
	}
	for (size_t i = 0; i < 5; i++)
	{
	delete[] pp[i];
	}
	delete[] pp;*/

	int **arr;
	int n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (size_t i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	fill_matrix(arr, n, m);
	cout << "»сходна€ матрица: " << endl;
	print_matrix(arr, n, m);
	add_first_colomn(arr, n, m);
	cout << "ћатрица после модификации" << endl;
	print_matrix(arr, n, m);


	for (size_t i = 0; i < n; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

	system("pause");
	return 0;
}