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
	for (e; e < n; e++)
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

void problem675C()
{
	//http://codeforces.com/contest/675/problem/C
	//This is not my code. Only for reference.
	typedef long long ll;
	ll i, j, k, l, m, n;
	while (cin >> n)
	{
		ll sum = 0, ans = n - 1;
		printf("\nAns: %d", ans);
		map<ll, ll>arr;
		for (i = 1; i <= n; i++)
		{
			ll input;
			cin >> input;
			sum += input;
			arr[sum]++;
			ans = min(ans, n - arr[sum]);   //if you can get to a certain sum as many times as possible, then it must be the min times.
			cout << "\nInput: " << input << "\tSum: " << sum << "\tAns: " << ans << "\tarr[sum]" << arr[sum];
		}
		cout << ans << endl;
	}

}

bool check(long long cookies, long long ingredients, long long powder, vector<long long> & need, vector<long long>&have, long long totalEach)
{
	//1 = possible
	//0 = impossible
	long long usedIngredient = 0;
	for (long long i(0); i < ingredients; i++)
	{
		usedIngredient += min(have[i], need[i] * cookies);
	}
	return (totalEach * cookies - usedIngredient) <= powder ? true : false;
}
void problem670D1()
{
	//http://codeforces.com/problemset/problem/670/D1
	//http://codeforces.com/problemset/problem/670/D2  just use the long long instead of int

	//need to know loop condition
	//need to know condition that a number is possible.

	//acceptance condition?
	//maxCookies will always go down. minCookies don't change.
	//first, loop through ingredient, and find available ingredient for the no. of cookies, no exccess.
	//acceptance condition: if selected number * recipe - available ingredient for the number of cookies (not the total)
	//< mPowder, ok! min = mid
	//else max = mid (> mPowder)
	//keep count of the loop
	//if count > (max - min) break
	//choose the min

	//ifstream in("input.txt");
	//ofstream out("output.txt");
	long long nIngredients(0), mPowder(0), totalEach(0), totalAvail(0);
	cin >> nIngredients >> mPowder;

	vector<long long>need(nIngredients);
	vector<long long>have(nIngredients);
	for (long long i = 0; i < nIngredients; i++)   //read in recipe
	{
		cin >> need[i];
		totalEach += need[i];
	}

	for (long long i = 0; i < nIngredients; i++)  //read in available ingredient
	{
		cin >> have[i];
		totalAvail += have[i];
	}

	long long maxCookies = (totalAvail + mPowder) / totalEach;
	long long minCookies(maxCookies), midCookies(0);

	for (long long i = 0; i < nIngredients; i++)
	{
		minCookies = have[i] / need[i] < minCookies ? have[i] / need[i] : minCookies;
	}
	//out << minCookies << " " << maxCookies << " " << midCookies << " " <<totalEach<<" " << endl;
	long long count = log2((maxCookies - minCookies) + 1) + 1;
	//out << count;
	while (count--)
	{
		//out << count << endl;
		midCookies = (minCookies + maxCookies) / 2;
		bool test = check(midCookies, nIngredients, mPowder, need, have, totalEach);

		if (test)
			minCookies = midCookies;
		else
			maxCookies = midCookies - 1;

	}
	//out << minCookies << " " << midCookies << " " << maxCookies << endl;
	bool test = check(maxCookies, nIngredients, mPowder, need, have, totalEach);
	if (test)
		cout << maxCookies << endl;
	else
		cout << minCookies << endl;


}
