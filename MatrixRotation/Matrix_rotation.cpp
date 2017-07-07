//============================================================================
// Name        : Matrix_rotation.cpp
// Author      : anirudh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int M = 9;

void print(int a[M][M], int n);
void rotate(int a[M][M], int n);
//int* r2(int a[M][M], int n);
void r3(int a[M][M], int n, int b[M][M]);

int main() {
	int n = 9;
	int a[M][M];

	//Initially, giving a random input.
	srand(time(0));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i == j)
				a[i][j] = rand()%100;
			else
				a[i][j] = rand()%100;
		}
	}
	a[0][0] = 4;

//	print(a, n);
//	cout << endl;
//	rotate(a, n);
//	print(a, n);
//	cout << endl;
//	rotate(a, n);
//	print(a, n);

	int b[M][M], c[M][M];
	print(a, n);
	cout << endl;
	r3(a, n, b);
	print(b, n);
	cout << endl;
	r3(b, n, c);
	print(c, n);


	return 0;
}

void print(int a[M][M], int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << setw(3) << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void rotate(int a[M][M], int n) //rotating boundaries one by one and going inside till the center! doing the process in the same array! by saving the previous values!
{
	int l;
	int  k;
	for(int i = 0; i < n/2; i++)
	{
		l = n-i-1;
		k = l;
		for(int j = i; j < l; j++)
		{
			int temp = a[j][l];
			int temp1 = a[l][k];
			int temp2 = a[k][i];
			a[j][l] = a[i][j];
			a[l][k] = temp;
			a[k][i] = temp1;
			a[i][j] = temp2;
			k--;
		}
	}

}


void r3(int a[M][M], int n, int b[M][M]) // rotating each row from first to the column from the last! by copying the values to a new array!
{
	int k = M-1;
	int l = 0;
	for(int i = 0; i < M && k >= 0; i++)
	{
		l = 0;
		for(int j = 0; j < M && l < M; j++)
		{
			b[l][k] = a[i][j];
			l++;
		}
		k--;
	}
}

//int* r2(int a[M][M], int n)
//{
//	int b[M][M];
//	int k = M;
//	int l = 0;
//	for(int i = 0; i < M && k > 0; i++ && k--)
//	{
//		l = 0;
//		for(int j = 0; j < M && l < M; j++ && l++)
//		{
//			b[l][k] = a[i][j];
//		}
//	}
//	int *p = &b[M][M];
//	return p;
//}

