#include <bits/stdc++.h>

using namespace std;


// Using Iterative function
int fact(int n)
{
	if (n == 0)
		return 1;
	else
		return fact(n - 1) * n;
}

int nCr(int n, int r)
{
	int num = fact(n);
	int den = fact(r) * fact(n - r);
	return num / den;
}

//Recurrsive call
int NCR(int n, int r)
{
	if (r == 0 || n == r)
		return 1;
	else
		return NCR(n - 1, r - 1) + NCR(n - 1, r);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int p = nCr(4, 2);
	cout << "Result is " << p << " Using recurrsive call " << NCR(4, 2);

	return 0;
}
