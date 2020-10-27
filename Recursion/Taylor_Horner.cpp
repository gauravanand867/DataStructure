#include <bits/stdc++.h>

using namespace std;

double TalorSeries_Iterative(int x, int n)
{
	double s = 1;
	for (; n > 0; n--) {
		s = 1 + s * x / n;
	}
	return s;
}
double TalorSeries(int x, int n)
{
	static double s = 1;
	if (n == 0)
		return s;
	else {
		s = 1 + (s  * x / n);
		return TalorSeries(x, n - 1);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	double p = TalorSeries_Iterative(1, 10);
	double q = TalorSeries_Iterative(1, 10);
	cout << "Result is " << p << " using Iterative function " << q;

	return 0;
}
