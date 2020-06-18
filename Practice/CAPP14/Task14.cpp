#include <iostream>
using namespace std;
int main()
{
	int s, l1, r1, l2, r2;
	bool flag = false;
	cin >> s>> l1>> r1>> l2>> r2;
	int l2_2 = l2;
	for (; l1 <= r1; l1++)//проверка первого диапозона (0-3=0,1,2,3)
	{
		for (l2=l2_2; l2 <= r2; l2++)//проверка второго диапозона 
		{
			if (l1 + l2 == s)// 
			{ 
				flag = true;
				break;
			}
		}
		if (flag)break;
	}
	if (flag)cout << l1 << ' ' << l2 << endl;
	else cout << -1 << endl;
}
