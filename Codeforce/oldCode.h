#pragma once

#include <iostream>
#include <fstream>

void countTiles()
{
	using namespace std;
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