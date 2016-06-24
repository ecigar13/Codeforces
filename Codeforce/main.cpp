using namespace std;
template<typename T>

#define LOOP(A,B,C) for (int i = A; i < B; i += C)

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


void problem686B(ifstream &in, ofstream &out)
{
	//http://codeforces.com/contest/686/problem/B
	long long size(0);
	in >> size;
	vector<long long> zoo(size);
	for (int i = 0; i < size; i++)
	{
		in >> zoo[i];
	}
	for (int i = 0; i < size; i++)
	{
		out << zoo[i];
	}
	sort(zoo.begin(), zoo.end());

	for (int i = 0; i < size; i++)
	{
		out << zoo[i];
	}
}
int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	//problem686B(in, out);
	int a = 4;
	int b = 2;
	SWAP(a, b);
	cout << a << ' ' << b;
	//cin.clear();
	//cin.ignore(sizeof(long long), '\n');
	//cin.get();
}

