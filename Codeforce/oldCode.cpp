
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
	for (int i =	static_cast<int> (a.size()) - 1; i >= 0; i--) {
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
void problem4A()
{
	//http://codeforces.com/problemset/problem/4/A
	int weight;
	cin >> weight;
	string result;
	if (weight % 2 || (weight <3))
		result = "NO";
	else result = "YES";

	cout << result;

}
void problem678A()
{
	//http://codeforces.com/problemset/problem/678/A
	long long n, k, result;
	cin >> n >> k;
	cout << (n / k + 1)*k;
}
void problem686A()
{
	//http://codeforces.com/problemset/problem/686/A
	long long n, x, stressed(0);
	cin >> n >> x;
	//cout << n << ' ' << x;
	LOOP(0, n, 1)
	{
		char sign;
		long long amt;
		cin >> sign >> amt;
		amt = (sign == '-') ? -abs(amt) : abs(amt);
		//cout << sign << " " << amt;
		if ((x + amt) < 0)
			stressed++;
		else x += amt;
	}
	cout << x << ' ' << stressed;
}

void problem369A()
{
	//http://codeforces.com/problemset/problem/369/A
	//1st type: bowl, 2nd type: dish
	//input: days, clean bowl, clean dish
	//1st type: only use bowl. 2nd type: can use both dish and bowl

	int days, bowl, dish;
	cin >> days >> bowl >> dish;
	int choice, wash(0);
	LOOP(0, days, 1)
	{
		cin >> choice;
		if (choice == 1)
		{
			if (bowl > 0)
				bowl--;
			else wash++;
		}
		else if (choice == 2)
		{
			if (dish > 0)
				dish--;
			else if (bowl > 0)
				bowl--;
			else wash++;
		}

	}
	cout << wash;
	//if 1st, if bowl >= 0, bowl--, else wash++
	//if 2nd, if dish>=0, dish--, else if bowl >=0, bowl--, else wash++

}

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
				cout << i + 1 << ' ' << i + 2 << '\n';
				swap(zoo[i], zoo[i + 1]);
			}
		}
	}
}
void problem703B()
{
	//http://codeforces.com/problemset/problem/703/B
	int cities(1), capCities(0);

	using namespace std;
	cin >> cities >> capCities;
	vector<int> cityList(cities);
	vector<int> capList(capCities);

	for (int i = 0; i < cities; i++)
	{
		cin >> cityList[i];
	}
	for (int i = 0; i < capCities; i++)
	{
		cin >> capList[i];
	}

	for (int i = 0; i < capCities; i++)
	{
		capList[i] -= 1;
	}
	int total(0);
	int capCap(0);

	for (int i(0); i < capCities - 1; i++)
	{
		for (int j = i + 1; j < capCities; j++)
		{
			int a = (cityList[capList[i]] * cityList[capList[j]]);
			capCap += a;
		}
	}

	total += capCap;

	if (cities == capCities)
	{
		cout << total << endl;
		return;
	}

	int capCity(0);
	for (int i(0); i < capCities; i++)
	{
		for (int j(0); j < cities; j++)
		{
			if (!binary_search(capList.begin(), capList.end(), j))
			{
				int a = (cityList[capList[i]] * cityList[j]);
				capCity += a;

			}
		}
	}

	total += capCity;


	int cityCity(0);
	for (int i(0); i < cities; i++)
	{
		if (binary_search(capList.begin(), capList.end(), i))
		{
			cityList[i] = 0;
		}
	}
	for (int i(1); i < cities; i++)
	{
		int a = (cityList[i - 1] * cityList[i]);
		cityCity += a;
	}

	total += cityCity;
	int a = (cityList[0] * cityList[cities - 1]);
	total += a;

	cout << total << endl;
}
void problem709B()
{
	//http://codeforces.com/contest/709/problem/B
	using namespace std;
	long long pt(0), start(0);
	cin >> pt >> start;

	if (pt <2)
	{
		cout << 0 << endl; return;
	}
	vector<long long> points(pt);
	for (long long i(0); i < pt; i++)
	{
		cin >> points[i];
	}
	sort(points.begin(), points.end());
	long long dist1(0), dist2(0);
	if (pt == 2)
	{
		dist1 = abs(start - points[0]);
		dist2 = abs(start - points[1]);
		//cout << dist1 << ' ' << dist2 << endl;
	}
	else //(pt > 2)
	{
		dist1 = min(abs(start - points[0]), abs(start - points[pt - 2])) + abs(points[pt - 2] - points[0]);
		dist2 = min(abs(start - points[pt - 1]), abs(start - points[1])) + abs(points[pt - 1] - points[1]);
		//cout << dist1 << ' ' << dist2 << endl;;
	}

	if (dist1 > dist2)
	{
		cout << dist2 << endl;
		return;
	}
	cout << dist1 << endl;
}
void problem707A()
{
	//http://codeforces.com/problemset/problem/707/A
	int row(0), col(0);
	cin >> row >> col;
	bool color(false);		//true= color
	for (int i{ 0 }; i < row; i++)
		for (int j{ 0 }; j < col; j++)
		{
			char c;
			cin >> c;
			if (c != 'W' && c != 'B' && c != 'G')
				color = true;
		}

	if (color)
		cout << "#Color";
	else
		cout << "#Black&White";

}
void euler1()
{
	int a(3), b(5), c(15), max(0), total(0);
	max = 1000 / a;
	total += 3 * (max*(max + 1) / 2);
	max = 1000 / b;
	total += 5 * (max*(max + 1) / 2);
	max = 1000 / c;
	total -= 15 * (max*(max + 1) / 2);
	cout << total;
}
void euler2()
{
	long long first(1), second(2), total(0);
	while (first<4000000) {
		if (first % 2 == 0)
			total += first;

		long long temp = second;
		second += first;
		first = temp;
	};
	cout << "Total is:" << total << '\n';
	cout << "First: " << first << '\n' << "Second: " << second << '\n';

}
void euler3()
{
	long long num = 600851475143, max(0), div(0);
	max = (int)floor(sqrt(num));

	long long i(1);
	while (i <= max)
	{
		if (num%i == 0)
		{
			num /= i;
			div = i;
		}
		i++;
	}
	cout << div;
}
void problem707B()
{
	struct Route
	{
		int cityA;
		int cityB;
		int dist;
	};
	long long cities(0), road(0), storage(0);
	vector<Route> routeList;
	vector<long long> sto;

	cin >> cities >> road >> storage;
	Route a = { 0,0,0 };

	for (long long i = 0; i < road; i++)
	{
		cin >> a.cityA >> a.cityB >> a.dist;
		routeList.push_back(a);
	}
	//cout << "NO!" << endl;
	if (storage > 0)
	{
		long long temp(0);
		for (long long i = 0; i < storage; i++)
		{
			cin >> temp;
			sto.push_back(temp);
		}
	}
	else {
		cout << -1; return;
	}

	//cout << "YES!" << endl;
	long long small = LLONG_MAX;
	for (long long i = 0; i < road; i++)
	{
		vector<long long>::iterator it1 = find(sto.begin(), sto.end(), routeList[i].cityA);
		vector<long long>::iterator it2 = find(sto.begin(), sto.end(), routeList[i].cityB);
		if (it1 != sto.end() ^ it2 != sto.end())
		{
			long long j = routeList[i].dist;
			small = min(j, small);
		}
	}
	if (small == LLONG_MAX)
		cout << -1;
	else cout << small;

}
void problem707B1()
{
	int a, b, c;
	cin >> a >> b >> c;

	if (c == 0)
	{
		cout << -1;
		return;
	}
	int d, mi(INT_MAX);
	vector<int> cityA(b);
	vector<int>cityB(b);
	vector<int>dist(b);
	vector<int>storage(a + 1, 0);

	for (int i = 0; i < b; i++)
	{
		cin >> cityA[i] >> cityB[i] >> dist[i];
	}
	for (int i = 0; i < c; i++)
	{
		cin >> d;
		storage[d] = 1;
	}
	for (int i = 0; i < b; i++)
	{
		if (storage[cityA[i]] != storage[cityB[i]])
		{
			mi = min(mi, dist[i]);
		}
	}
	if (mi == INT_MAX)
		cout << -1 << endl;
	else cout << mi;
}
