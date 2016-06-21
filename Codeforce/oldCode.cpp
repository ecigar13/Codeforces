#pragma once

#include "oldCode.h"

using namespace std;

//here's the problem: http://codeforces.com/problemset/problem/1/A
void countTiles()
{

	int length, width, tileEdge;
	std::cin >> length >> width >> tileEdge;

	long long lengthA{ length / tileEdge }, widthA{ width / tileEdge };
	if (length % tileEdge != 0)
		lengthA = length / tileEdge + 1;

	if (width % tileEdge != 0)
		widthA = width / tileEdge + 1;

	cout << widthA * lengthA << endl;
	ofstream outf("result.txt");
	outf << widthA * lengthA << endl;
}

//convert int to string
string con(int a) {
	string r = "";
	while (a > 0) {
		int m = a % 26;
		if (m == 0) {
			r = 'Z' + r;
		}
		else {
			char a = m - 1 + 'A';
			r = a + r;
		}
		a /= 26;
		if (m == 0) a--;
	}
	return r;
}

//convert string to int, in the form of int
int con2(string& a) {
	int r = 0;
	int po = 1;
	for (int i = a.size() - 1; i >= 0; i--) {
		int order = a[i] - 'A' + 1;
		r += order * po;
		po *= 26;
	}
	return r;
}


void spreadsheet()
{
	//Here's the problem: http://codeforces.com/problemset/problem/1/B
	int n = 1;
	cin >> n;   //read in first line, prevent infinite loop.
				//determined the RRCC form or RC form
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		int change = 0;  //number of change
		int change1(0);
		for (int j = 0; j < temp.size() - 1; j++)
		{
			if ((!isdigit(temp[j])) && (isdigit(temp[j + 1])))
			{
				change++;
				change1 = j;
			}
			else if (isdigit(temp[j]) && !isdigit(temp[j + 1]))
			{
				change++;
			}
		}
		if (change > 1)  //form R1C1
		{
			//convert R1C1 to A1
			int row = stoi(temp.substr(1, change1 - 1));
			int col = stoi(temp.substr(change1 + 1));
			cout << con(col) << row << "\n";
		}

		else
		{
			//convert A1 to R1C1
			string col = temp.substr(0, change1 + 1);
			int row = stoi(temp.substr(change1 + 1));
			cout << 'R' << row << 'C' << con2(col) << '\n';
		}
	}
}

void problem675A()
{
	//http ://codeforces.com/problemset/problem/675/A

	int x, y, z;
	cin >> x >> y >> z;

	if (z != 0)
	{
		if ((y - x) % z == 0 && (y - x) / z >= 0)
		{
			cout << "YES";
		}
		else cout << "NO";
	}
	else
	{
		if (x == y)
		{
			cout << "YES";
		}
		else cout << "NO";
	}
}

void problem675B_1()
{
	//http://codeforces.com/contest/675/problem/B
	printf("e\ta\tf\nb\tt\tc\ng\td\th\n\n");

	long long n, a, c, b, d, e(0), f, g, h;
	long long sol{ 1 };
	cin >> n >> a >> b >> c >> d;
	for (e;e < n; e++)
	{
		f = (b - d) + e;
		g = (a - c) + e;
		h = (a + b) - (c + d) + e;
		if (f >= 1 && f < n && g >= 1 && g < n&&h >= 1 && h < n)
			sol++;
	}

	cout << sol*n << endl;
}

void problem675B_2()
{
	//http://codeforces.com/contest/675/problem/B
	//printf("e\ta\tf\nb\tt\tc\ng\td\th\n\n");
	long long n, a, c, b, d;

	cin >> n >> a >> b >> c >> d;

	//e f g h are constrained by ab ac bd cd. ad and bc are not possible (see the 3x3 picture)
	//reduce n by the difference between any two of them, we have the rest of the possible pair values.
	//find the solution and make sure there's a 0 possibility.


	int hi = max(max(a + b, c + d), max(a + c, b + d));
	int low = min(min(a + b, c + d), min(a + c, b + d));
	int possibleCombination = n - (hi - low);
	cout << max((long long)0, possibleCombination*n) << endl;
}
