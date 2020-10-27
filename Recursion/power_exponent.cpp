#include <bits/stdc++.h>

using namespace std;


int pow(int m, int n)
{
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return pow(m * m, n / 2);
	else
		return m * pow(m * m, (n - 1) / 2);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int p = pow(2, 5);
	cout << "Result is " << p;

	return 0;
}
