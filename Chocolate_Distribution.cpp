#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		ll a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		ll m;
		cin >> m;
		sort(a, a + n);
		ll ans = INT_MAX;
		for (int i = 0; i <= n - m; i++)
		{
			ans = min(abs(a[i] - a[i + m - 1]), ans);
		}
		cout << ans << endl;
	}
}