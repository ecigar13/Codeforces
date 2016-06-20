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

//Here's the problem: http://codeforces.com/problemset/problem/1/B
void spreadsheet()
{
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