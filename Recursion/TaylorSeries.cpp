#include <bits/stdc++.h>

using namespace std;


double TalorSeries(int x, int n)
{
	static double p = 1, f = 1;
	double r;
	if (n == 0)
		return 1;
	else {
		r = TalorSeries(x, n - 1);
		p = p * x;
		f = f * n;
		return r + p / f;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	double p = TalorSeries(3, 10);
	cout << "Result is " << p;

	return 0;
}
