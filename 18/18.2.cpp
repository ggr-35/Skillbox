#include <iostream>
using namespace std;

int countWaysUtil(int n, int m)
{
	if (n <= 1)
	{
		return n;
	}
	
	int res = 0;
	for(int i = 1; i <= m && i <= n; i++)
	{
	res += countWaysUtil(n - i, m);
	}
	return res;
}


int countWays(int s, int m)
{
	return countWaysUtil(s + 1, m);
}

int main()
{
	int s = 3, m = 2;
	cout << "Number of ways = " << countWays(s, m);

	return 0;
}

