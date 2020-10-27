#include <bits/stdc++.h>

using namespace std;


// Using Iterative function
int fib(int n)
{
	int t1 = 0, t2 = 1, s;
	if (n <= 1) return n;

	for (int i = 2; i <= n; i++)
	{
		s = t1 + t2;
		t1 = t2;
		t2 = s;
	}
	return s;
}

//Using Recurrsive Call

int fib_r(int n)
{
	if (n <= 1) return n;

	return fib_r(n - 2) + fib_r(n - 1);
}


//Recurrsive call with memoization

int F[10];
int fib_r_mem(int n)
{
	if (n <= 1)
	{
		F[n] = n;
		return n;
	}
	if (F[n - 2] == -1)
		F[n - 2] = fib_r_mem(n - 2);
	if (F[n - 1] == -1)
		F[n - 1] = fib_r_mem(n - 1);
	F[n] = F[n - 2] + F[n - 1];
	return F[n - 2] + F[n - 1];

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	for (int i = 0; i < 10; i++) {
		F[i] = -1;
	}
	int p = fib_r_mem(7);
	cout << "Result is " << p;

	return 0;
}
