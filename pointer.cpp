#include <iostream>
#include<iomanip>
#include <vector>
#include<algorithm>
#include<set>

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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	setDemo();

	return 0;
}
