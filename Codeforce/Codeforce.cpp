#include "stdafx.h"
#include "oldCode.h"



using namespace std;




int main()
{
	clock_t t = clock();
	euler7();


	t = clock() -t;
	cout << setprecision(3);
	cout << '\n' << "Program time: " << t << endl;
	system("pause");
	return 0;
}
