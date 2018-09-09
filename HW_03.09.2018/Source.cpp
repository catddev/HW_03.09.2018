#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>

using namespace std;

// 1.	**Даны два массива : А[M] и B[N](M и  N вводятся с клавиатуры).
// Необходимо создать третий массив минимально возможного размера, в котором нужно собрать элементы массива A, которые не включаются в массив B
void onlyA(int* a, int *b, int n, int m){
	int *pa = a;
	int *pb = b;
	
	int prove = 0, k = 0;
	for (int i = 0; i < n; i++)
	{
		prove = 0;
		for (int j = 0; j < m; j++)
		{
			if (a[i] == b[j])
				prove++;
		}
		if (prove == 0) k++;
	}

	int *c = new int[k];
	int h = 0;
	for (int i = 0; i < n; i++)
	{
		prove = 0;
		for (int j = 0; j < m; j++)
		{
			if (a[i] == b[j]) prove++;
		}
		if (prove == 0) c[h++] = a[i];
	}

	for (int i = 0; i < k; i++)
		cout << c[i] << " ";
	cout << endl << endl;

	delete[] c;
}
// 2.	**Даны два массива : А[M] и B[N](M и  N вводятся с клавиатуры).
// Необходимо создать третий массив минимально возможного размера, в котором нужно собрать общие элементы массивов A и B
// Рекомендации :
// ***Исключить повторяющиеся элементы. Пусть дано два массива
// А : 5 4 2 4 2
// В : 4 2 3 4 4
// Результат : 4 2 4
// т.к. 4 входит два раза в оба массива, 2 входит один раз в оба массива
void del_index(int *&aa, int &n, int index) {
	int *tmp = new int[n - 1];
	for (int i = 0; i < index; i++)
	{
		tmp[i] = aa[i];
	}
	for (int i = index; i < n; i++)
		tmp[i] = aa[i + 1];

	n -= 1;
	delete[] aa;
	aa = tmp;
}
void common_el(int *a, int *b, int n, int m) {
	int prove = 0, k = 0;
	int index = 0;
	int nn = m;
	int mm = m;
	int *copy = new int[nn];
	int *copy2 = new int[mm];

	for (int i = 0; i < nn; i++)
	{
		copy[i] = b[i];
		copy2[i] = b[i];
	}

	for (int i = 0; i < n; i++)
	{

		prove = 0;
		for (int j = 0; j < nn; j++)
		{
			if (a[i] == copy[j])
			{
				prove++;
				index = j;
			}
		}
		if (prove != 0)
		{
			k++;
			del_index(copy, nn, index);
		}

		/*for (int i = 0; i < nn; i++)
			cout << copy[i] << " ";
		cout << endl;*/
	}
	cout << "k (минимальный размер нового массива) = " << k << endl;

	int *tmp = new int[k];
	int h = 0;
	index = 0;
	for (int i = 0; i < n; i++)
	{
		prove = 0;
		for (int j = 0; j < mm; j++)
		{
			if (a[i] == copy2[j])
			{
				prove++;

				index = j;
			}
		}
		if (prove != 0)
		{
			tmp[h++] = a[i];

			del_index(copy2, mm, index);
		}
		/*for (int i = 0; i < mm; i++)
			cout << "&&" << copy2[i] << " ";
		cout << endl;*/

	}

	for (int i = 0; i < k; i++)
		cout << tmp[i] << " ";
	cout << endl << endl;

	delete[] tmp;
	delete[] copy;
	delete[] copy2;
}


int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn;

		switch (tn)
		{
		case 1:
		{
			int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
			int b[] = { 2, 4, 6, 8, 0 };
			int n, m;
			cin >> n >> m;

			onlyA(a, b, n, m);
		}
		break;
		case 2:
		{

			int a[] = { 5, 4, 2, 4, 2 };
			int b[] = { 4, 2, 3, 4, 4 };
			int n, m;
			/*cin >> n >> m;*/

			common_el(a, b, 5, 5);
		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}