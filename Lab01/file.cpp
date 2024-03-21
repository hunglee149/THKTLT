#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include "stdlib.h"
#include <fstream>
#include <iomanip>
using namespace std;

int n1, n2;

void ReadFile1(char fileInName[], char fileOutName[])
{
	fstream inFile;
	inFile.open(fileInName);
	inFile >> n1;

	string a, b, oprt;

	fstream outFile;
	outFile.open(fileOutName, fstream::out | fstream::trunc);

	if (!outFile.is_open())
	{
		cout << "Khong mo duoc file!";
		return;
	}

	outFile << fixed << setprecision(2);

	while(inFile >> a)
	{
		inFile >> oprt;
		inFile >> b;

		double a1 = stod(a);
		double b1 = stod(b);

		if (oprt == "+")
		{
			outFile << a1 + b1 << endl;
		}
		else if (oprt == "*")
		{
			outFile << a1 * b1 << endl;
		}
		else if (oprt == "-")
		{
			outFile << a1 - b1 << endl;
		}
		else
		{
			if (b1 == 0)
			{
				outFile << "INVALID" << endl;
			}
			else
			{
				outFile << a1/b1 << endl;
			}
		}
	}
	
	outFile.close();
	return;
}

void ReadFile2(char fileInName[], char fileOutName[])
{
	fstream inFile;
	inFile.open(fileInName);
	inFile >> n2;

	fstream outFile;
	outFile.open(fileOutName, fstream::out | fstream::trunc);

	if (!outFile.is_open())
	{
		cout << "Khong mo duoc file!";
		return;
	}
	int it = 0;

	string s[n2];
	string temp;

	for (int i = 0; i < n2; i++)
	{
		inFile >> s[i];
	}
	
	string w; inFile >> w;
	int cnt = 0;

	for (int i = 0; i < n2; i++)
	{
		if (s[i] == w) ++cnt;
	}
	
	outFile << cnt;
	outFile.close();
	return;
}

int main()
{
	char in1[] = "math.txt";
	char out1[] = "result1.txt";
	char in2[] = "keywords.txt";
	char out2[] = "result2.txt";
	
	ReadFile1(in1, out1);
	ReadFile2(in2, out2);
}
