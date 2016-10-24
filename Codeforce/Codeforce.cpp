#include "stdafx.h"
#include "oldCode.h"



using namespace std;

void euler8()
{
	//open file

	string myStr(13,0);
	char temp;

	for (int i(0); i < 13; i++)
	{
		//read the first 13 chars into the string.
	}
	/*read file
		
	1 string, size 13. 
	fgets initial string, size 13.
	int curMax = 0;

	for(int i(13); i<(1000-13);i++
		
		int product(0);
		for(int i=0, i<13,i++)
		{
			
			product*=i (i is each character in string, use atoi, stoi)
		}
		curMax = product>curMax?product:curMax;

		remove first number in string
		getchar and append to the end of string

		rof.

	cout<<string<<endl;
	*/
}


int main()
{
	clock_t t = clock();
	euler8();


	t = clock() -t;
	cout << setprecision(3);
	cout << '\n' << "Program time: " << t << endl;
	system("pause");
	return 0;
}
