// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int sb(int arr[], int n, int x);

int main() {
	// your code goes here
	int t;
	cin >> t;
	while (t--)
	{
		int n, x;
		cin >> n >> x;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		cout << sb(a, n, x) << endl;
	}
	return 0;
}// } Driver Code Ends




int sb(int a[], int n, int x)
{
	int ans = n + 1;
	int sum = 0;
	int i = 0, j = 0;
	while (i < n)
	{
		while (sum <= x && i < n)
			sum += a[i++];
		while (sum > x && j < n)
		{
			ans = min(ans, i - j);
			sum -= a[j++];
		}
	}
	return ans;

}