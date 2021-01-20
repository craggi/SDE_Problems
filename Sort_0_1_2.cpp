#include <bits/stdc++.h>
#define MAX INT_MAX
#define MIN INT_MIN
#define ll long long int
#define for(i,s,e) for(ll i=(s);i<(e);i++)
#define  mod 1e9+7
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll n;
	cin >> n;
	ll a[n];
	for (i, 0, n)
		cin >> a[i];
	//solution 1:
	/*sort(a, a + n);
	for (i, 0, n)
		cout << a[i] << " ";
	//Time Complexity Nlog(n) Space o(1)*/

	//Solution 2:
	//counting sort
	ll b = 0, c = 0, d = 0;
	for (i, 0, n)
	{
		if (a[i] == 0)
			b++;
		else if (a[i] == 1)
			c++;
		else
			d++;

	}
	for (i, 0, n)
	{
		if (i <= b - 1)
			a[i] = 0;
		else if (i > b - 1 && i <= b + c - 1)
			a[i] = 1;
		else
			a[i] = 2;
	}
	for (i, 0, n)
		cout << a[i] << " ";
	//solution 3:
	ll i = 0;
	ll j = n - 1;
	ll k = 0;
	while (k <= j)
	{
		if (a[k] == 0)
		{	swap(a[k], a[i]);
			i++;
			k++;
		}
		else if (a[k] == 2)
		{
			swap(a[k], a[j]);
			j--;

		}
		else
			k++;
	}
	for (i, 0, n)
		cout << a[i] << " ";

}