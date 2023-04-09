#include "Exception.h"
#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
	try
	{
		Game().Run();
	}
	catch (const string& e)
	{
		cout << e << endl;
		system("pause");
	}
	return 0;
}