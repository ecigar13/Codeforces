
#include "oldCode.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <istream>

void convertRRCC(int &column)
{

}


int main()
{
	using namespace std;
	int lines, row, column;
	char oneLine[32];
	cin >> lines;
	while (lines > 0)
	{
		getline(cin, oneLine);
		if (sscanf(oneLine, "%s%d%s%d", &row, &column) == 2)
		{
			//convert to RRCC type
			convertRRCC(column);
			cout << row << '\n';
		}
		else
		{
			//convert to R__C__ type
			int newCol; //compute the column here
			cout << 'R' << row << 'C' << newCol << '\n';
		}
		lines--;
	}

	return 0;
}