#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include "stdlib.h"
#include <fstream>
using namespace std;

const int MAX = 1000;

bool isEven(int a)
{
	return (a & 1 == 0);
}

bool isPrime(int a)
{
	if (a < 2) return false;

	for (int i = 2; i <= sqrt(a); i++)
	{
		if (a % i == 0) return false;
	}

	return true;
}

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int countDivisible(int N, int k)
{
	int cnt = 0;
	
	for (int i = 1; i <= N; i++)
	{
		if (i % k == 0) ++cnt;
	}

	return cnt;
}

int sumDigits(int n)
{
	int sum = 0;
	while(n != 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

void triangle(double a, double b, double c)
{
	if (a + b > c && a + c > b && b + c > a)
	{
		if (a*a + b*c == c*c || a*a + c*c == b*b || b*b + c*c == a*a)
		{
			if (a == b || a == c || b == c)
			{
				cout << "Tam giac vuong can";
			}
			else
			{
				cout << "Tam giac vuong";
			}
		}
		else
		{
			if (a == b)
			{
				if (a == c)
				{
					cout << "Tam giac deu";
				}
				else
				{
					cout << "Tam giac can";
				}
			}
			else
			{
				if (b == c)
				{
					cout << "Tam giac can";
				}
				else if (a == c)
				{
					cout << "Tam giac can";
				}
				else cout << "Tam giac thuong";
			}
		}
	}
	else
	{
		cout << "Ba canh khong tao nen duoc 1 tam giac";
	}
}

void inputArray(int a[], int &n)
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
}

void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++) cout << a[i] << " ";
}

double sumArray(double a[], int n)
{
	double sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}

	return sum;
}

bool isArraySortedAscending(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		if (a[i] > a[i - 1]) return false;
	}
	return true;
}

bool isArraySortedDescending(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		if (a[i] < a[i - 1]) return false;
	}
	return true;
}

void input2DArray(int A[][MAX], int &m, int &n)
{
	cin >> m >> n;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}
}

void print2DArray(int A[][MAX], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << ' ';
		}
		cout << endl;
	}
}

void matrixMultiplication(int A[][MAX], int B[][MAX], int result[][MAX], int m, int n, int p)
{
	// m*n * n*p => m*p
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < p; j++)
		{
			result[i][j] = 0;
			
			for (int k = 0; k < n; k++)
			{
				result[i][j] += A[i][k] * B[k][j];
			}
			
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}

bool isDiagonalMatrix(int A[][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				if (A[i][j] == 0) return false; 
			}
			else
			{
				if (A[i][j] != 0) return false;
			}
		}
	}
	return true;
}

bool isUpperTriangularMatrix(int A[][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i >= j)
			{
				if (A[i][j] == 0) return false; 
			}
			else
			{
				if (A[i][j] != 0) return false;
			}
		}
	}
	return true;
}

bool isLowerTriangularMatrix(int A[][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i < j)
			{
				if (A[i][j] == 0) return false; 
			}
			else
			{
				if (A[i][j] != 0) return false;
			}
		}
	}
	return true;
}

void printString(char c[100])
{
	cout << c;
}

int countCapitalInString(char c[100])
{
	int cnt = 0;
	
	for (int i = 0; i < 100; i++)
	{
		if (c[i] >= 'A' && c[i] <= 'Z') ++cnt;
	}

	return cnt;
}

int countCharacterAppearance(char C[100], char c)
{
	int cnt = 0;
	
	for (int i = 0; i < 100; i++)
	{
		if (C[i] == 'c') ++cnt;
	}

	return cnt;
}

struct PhanSo
{
	int tu, mau;
};

void input(PhanSo &phanSo)
{
	cin >> phanSo.tu;
	cin >> phanSo.mau;
}

bool valid(PhanSo phanSo)
{
	return (phanSo.mau != 0);
}

PhanSo rutGon(PhanSo &phanSo)
{
	int ucln = gcd(phanSo.tu, phanSo.mau);
	phanSo.tu /= ucln;
	phanSo.mau /= ucln;

	PhanSo newPS;
	newPS.tu = phanSo.tu;
	newPS.mau = phanSo.mau;

	return newPS;
}

double tong(PhanSo &ps1, PhanSo &ps2)
{
	ps1 = rutGon(ps1);
	ps2 = rutGon(ps2);

	int tuMoi = ps1.tu*ps2.mau + ps2.mau*ps1.tu;
	int mauMoi = ps1.mau * ps2.mau;

	return 1.0*tuMoi/mauMoi;
}

double tich(PhanSo ps1, PhanSo ps2)
{
	int tuMoi = ps1.tu * ps2.tu;
	int mauMoi = ps1.mau * ps2.mau;

	return 1.0*tuMoi/mauMoi;
}

int lcm(int a, int b)
{
	return a*b/gcd(a, b);
}

void soSanhPhanSo(PhanSo &ps1, PhanSo &ps2)
{
	int mauMoi = lcm(ps1.mau, ps2.mau);
	ps1.tu = ps1.tu*(mauMoi/ps1.mau);
	ps2.tu = ps2.tu*(mauMoi/ps2.mau);

	if (ps1.tu < ps2.tu) cout << "Phan so dau tien nho hon phan so thu hai";
	else if (ps1.tu > ps2.tu)
	{
		cout << "Phan so dau tien lon hon phan so thu hai";
	} 
	else
	{
		cout << "Hai phan so bang nhau";
	}
}
