#include <iostream>
#include<iomanip>
#include <vector>
#include<algorithm>
#include<set>
#include<map>
#include<bits/stdc++.h>

using namespace std;


bool fn(int x, int y)
{
	return x < y;
}


void vectorDemo()
{
	vector<int> a = {20, 5, 96, 78, 59, 105, 624, 521, 41, 9, 5, 100};
	cout << a[0] << endl;
	sort(a.begin(), a.end(), fn);
	cout << a[3] << endl;
	bool present = binary_search(a.begin(), a.end(), 78);
	cout << present << endl;
	a.push_back(100);
	a.push_back(133);
	cout << a[a.size() - 1] << endl;

	auto it = lower_bound(a.begin(), a.end(), 100);				 		//auto = vector<int>::iterator
	auto it1 = upper_bound(a.begin(), a.end(), 100);					//auto=vector<int>::iterator
	cout << *it << endl;
	cout << it1 - it << endl;

	//vector<int>::iterator it3;

	for (int &x : a)									//it3 = a.begin(); it3 != a.end(); it3++
	{
		cout << x << endl;								//*it3
		x += 1;
	}
	for (int x : a)
	{
		cout << x << endl;
	}
}
void setDemo()

{
	set<int> s = {5, 8, 9, 3, 1, 8};
	s.insert(5);
	s.insert(-9);

	for (int x : s)
	{
		cout << x << endl;
	}

	auto in = s.find(8);
	if (in == s.end())
	{
		cout << "Number not present" << endl;
	}
	else
	{
		cout << "Present " << *in << endl;
	}
	auto in1 = s.upper_bound(5);
	auto in2 = s.upper_bound(6);
	cout << *in1 << setw(5) << *in2 << endl;

	auto in3 = s.upper_bound(8);

	if (in3 == s.end())
	{
		cout << "Opps Not present" << endl;
	}
	else
	{
		cout << "Found" << endl;
	}

}
void mapDemo()
{
	map<int, int> a;
	a[1] = 18;
	a[2] = 02;
	a[59] = 3;

	map<char, int> c;

	string x = "Gaurav Anand";

	for (char i : x)
	{
		c[i]++;
	}
	cout << c['a'] << setw(7) << c['G'] << endl;						// 3 & 1
	cout << a[1] << endl;
}

void powerstl()
{
	set<pair<int, int> > s;
	s.insert({401, 450});
	s.insert({10, 20});
	s.insert({2, 3});
	s.insert({30, 400});

	int point = 2;

	auto it = s.upper_bound({point, INT_MAX});
	if (it == s.begin())
	{
		cout << "the given point not Found" << endl;
		return;
	}
	it--;
	pair<int, int>current = *it;
	if (current.first <= point && point <= current.second) {
		cout << "Yes Present in range : " << current.first << "  " << current.second << endl;
	}
	else {
		cout << "Point not lying on interval";
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	long long TS = 0;
	vector<int> A(n + 5, 0);			// size=n & initialised with 0
	for (int i = 0; i < n; i++) cin >> A[i], TS += A[i];
	if (TS & 1) {
		cout << "NO";
		return 0;
	}

	map<long long, int> first, second;
	first[A[0]] = 1;

	for (int i = 1; i < n; i++) second[A[i]]++;

	long long p = 0;
	for (int i = 0; i < n - 1; i++) {
		p += A[i];
		if (p == TS / 2) {
			cout << "YES";
			return 0;
		}
		if (p < TS / 2) {
			long long x = TS / 2 - p;
			if (second[x] > 0) {
				cout << "YES\n";
				return 0;
			}
		}
		else {
			long long y = p - TS / 2;
			if (first[y] > 0) {
				cout << "YES\n";
				return 0;
			}
		}
		first[A[i + 1]]++;
		second[A[i + 1]]--;
	}
	cout << "NO\n";



	return 0;
}
