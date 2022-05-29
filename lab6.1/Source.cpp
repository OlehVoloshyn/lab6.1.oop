#include "Array.h"
#include <iostream>
#include <time.h>
#include <stdexcept>
#include <exception>
#include <cmath>
using namespace std;
typedef Array::value_type* TArray;
int main()
{
	int n;
	cout << "n= "; cin >> n;
	Array c = Array(2 * n);
	srand((unsigned)time(NULL));
	Array::value_type A = -50;
	Array::value_type B = 50;
	TArray a = new Array::value_type[2*n];
	for (int i = 0; i < 2 * n; i++)
		a[i] = A + rand() % int(B - A + 1);
	Array::iterator l = const_cast<Array::iterator>(c.begin());
	for (int j = 0; j < 2 * n; j++, l++)
		*l = a[j];


	for (int j = 0; j < 2 * n; j++)
		cout << "\t" << a[j];
	cout << "\n\n";
	int max = a[0];
	for (int j = 0; j < 2 * n; j++)
	{
		if (max < a[j])
			max = a[j];
	}
	for (int j = 0; j < 2 * n; j++)
	{
		a[j] = a[j] - max;
		cout << "\t" << a[j];
	}

	cout << "\n";
	cout << c;
	c.pop_back();
	//c.assign(10);
	cout << c;
	cout << "\n";

	cin.get();
	cin.get();
	return 0;
}