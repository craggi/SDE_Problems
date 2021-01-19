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
	ll a[n + 1];
	for (i, 0, n + 1)
		cin >> a[i];
	//solution 1:
	sort(a, a + n + 1);
	for (i, 0, n)
	{
		if (a[i] == a[i + 1])
		{
			cout << a[i];
			break;
		}
	}
	//solution 2:
	set<int>s;
	for (i, 0, n + 1)
	{
		if (s.find(a[i]) != s.end())
		{	cout << a[i];
			break;
		}
		s.insert(a[i]);
	}
	//solution 3:
	ll i = a[0];
	ll j = a[0];
	do {
		i = a[i];
		j = a[a[j]];
	} while (i != j);
	i = a[0];
	while (i != j)
	{
		i = a[i];
		j = a[j];
	}
	cout << j;

}