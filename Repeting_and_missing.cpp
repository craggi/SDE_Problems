#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int *findTwoElement(int *a, int n) {
		//Solution 1

		int temp[n + 1] = {0};
		static int c[2];
		for (int i = 0; i < n; i++)
		{
			if (temp[a[i]] == 1)
				c[0] = a[i];
			else
				temp[a[i]] = 1;

		}
		for (int i = 1; i <= n; i++)
		{
			if (temp[i] == 0)
				c[1] = i;


		}
		return c;

		// Solution 2:

		//sum of first n number - sum of array
		//sum of first n2 number - sum of array square
		//x2-y2 and x-y solving these two equation we get the answer.

		// solution 3:

		int x = 0, y = 0;
		static int ans[2];
		int xo = a[0];
		for (int i = 1; i < n; i++)
			xo ^= a[i];
		for (int i = 1; i <= n; i++)
			xo ^= i;
		int setbit = xo & ~(xo - 1);
		for (int i = 0; i < n; i++)
		{
			if (a[i] & setbit)
				x = x ^ a[i];
			else
				y = y ^ a[i];

		}
		for (int i = 1; i <= n; i++)
		{
			if (i & setbit)
				x = x ^ i;
			else
				y = y ^ i;
		}
		ans[0] = x;
		ans[1] = y;
		return ans;
	}
};

int main() {
	std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		Solution ob;
		auto ans = ob.findTwoElement(a, n);
		cout << ans[0] << " " << ans[1] << "\n";
	}
	return 0;
}
