using namespace std;


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
#include <random>

void problem707B()
{
	struct Route
	{
		int cityA;
		int cityB;
		int dist;
	};
	long long cities, road, storage(0);
	vector<Route> routeList;
	cin >> cities >> road >> storage;
	Route a = { 0,0,0 };
	for (long long i = 0; i < road; i++)
	{
		cin >> a.cityA >> a.cityB >> a.dist;
		routeList.push_back(a);
	}
	vector<long long> sto;
	if (storage > 0)
	{
		for (long long i = 0; i < storage; i++)
		{
			cin >> sto[i];
		}
	}
	long long min((int)numeric_limits<int>::max);
	for (long long i = 0; i < road; i++)
	{
		if (find(sto.begin(), sto.end(), routeList[i].cityA) || find(sto.begin(), sto.end(), routeList[i].cityB))
		{
			long long j = routeList[i].dist;
			min = min(j, min);
		}
	}


}
int main()
{
	problem707B();
	cin.clear();
	cin.ignore(sizeof(long long), '\n');
	cin.get();
}