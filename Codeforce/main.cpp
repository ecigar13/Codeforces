
#include "oldCode.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <istream>

void convertRRCC(int &column)
{
	using namespace std;
	//minh co 1 so column 
	//divisible by 26
	//recursion
	if (column)
	{
		int newCol = column / 26;
		convertRRCC(newCol);

		cout << column % 26;
	}

}


int main()
{
	using namespace std;
	int lines, row, column;
	char oneLine[32], *p;

	ifstream inf("input.txt");

	inf >> lines;
	while (lines > 0)
	{
		getline(inf, oneLine);
		if (sscanf(oneLine, "%s%d%s%d", &row, &column) == 2)
		{
			//convert to RRCC type
			convertRRCC(column);
			cout << row << '\n';
		}
		else
		{
			//convert to R__C__ type
			for (row = 0, p = oneLine; *p>64; ++p)
				row = row * 26 + *p - 64;
			cout << 'R' << row << 'C' << row << '\n';
		}
		lines--;
	}

	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user

	return 0;
}