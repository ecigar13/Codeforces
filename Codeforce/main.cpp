using namespace std;
#define LOOP(A,B,C) for (long long i = A; i < B; i += C)

#define MIN(X, Y)  ((X) < (Y) ? (X) : (Y))
#define MAX(X, Y)  ((X) > (Y) ? (X) : (Y))

//#include "oldCode.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <istream>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <math.h>
#include <numeric>
#include <list>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <cstdio>
#include <cstring>



void problem686B()
{
	//http://codeforces.com/contest/686/problem/B
	int size(0);
	cin >> size;
	vector<long long> zoo(size);
	LOOP(0, size, 1)
	{
		cin >> zoo[i];
	}

	while (true)
	{
		int biggest = -1;
		LOOP(0, size - 1, 1)
		{
			if (zoo[i] > zoo[i + 1])
				biggest = i;
		}
		if (biggest == -1)
			return;

		LOOP(0, size - 1, 1)
		{
			if (zoo[i] > zoo[i + 1])
			{
				cout << i+1 << ' ' << i + 2<<'\n';
				swap(zoo[i], zoo[i + 1]);
			}
		}
	}
	//for (int i = 0; i < size; i++)
	//{
	//	out << zoo[i];
	//}
	//sort(zoo.begin(), zoo.end());

	//for (int i = 0; i < size; i++)
	//{
	//	out << zoo[i];
	//}


}
int main()
{
	//ifstream in("input.txt");
	//ofstream out("output.txt");
	//problem686B(in, out);
	problem686B();
	//cin.clear();
	//cin.ignore(sizeof(long long), '\n');
	//cin.get();
}

