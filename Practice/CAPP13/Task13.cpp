#include <iostream>
using namespace std;
int main()
{
	int n, x = 1, counter = 0;
	cin >> n;
	if (n != 0) 
	{
		while (x <= n) 
		{
			counter++;// кол-во степеней
			x *= 2;// увеличение степени двойки
		}
	}
	cout << counter << endl;
}
