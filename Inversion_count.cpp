#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// Function to find inversion count in the array

// arr[]: Input Array
// N : Size of the Array arr[]
long long int merge(long long a[], long long t[], long long mid, long long l, long long r)
{
	long long i, j, k;
	long long inv = 0;
	i = l;
	j = mid;
	k = l;
	while ((i <= mid - 1) && (j <= r))
	{
		if (a[i] <= a[j])
		{	t[k++] = a[i++];
		}

		else
		{
			t[k++] = a[j++];
			inv = inv + (mid - i);
		}

	}
	while (i <= mid - 1)
		t[k++] = a[i++];
	while (j <= r)
		t[k++] = a[j++];
	for (long long i = l; i <= r; i++)
		a[i] = t[i];

	return inv;

}
long long int mergesort(long long a[], long long t[], long long l, long long r)
{
	long long mid ;
	long long count = 0;
	if (r > l)
	{
		mid = (l + r) / 2;
		count += mergesort(a, t, l, mid);
		count += mergesort(a, t, mid + 1, r);
		count += merge(a, t, mid + 1, l, r);

	}
	return count;
}
long long int inversionCount(long long a[], long long n)
{
	// solution 1:
	//Time O(n^2) Space O(1)
	/*long long int ans=0;
	for(long long i=0;i<n-1;i++)
	{
	    for(long long j=i+1;j<n;j++)
	    {
	        if(a[i]>a[j])
	        ans++;
	    }
	}
	return ans;*/


	//solution 2:
	//Time O(nlog(n)) Space O(n)
	long long t[n];
	return mergesort(a, t, 0, n - 1);

}


// { Driver Code Starts.

int main() {

	std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	long long T;
	cin >> T;

	while (T--) {
		long long N;
		cin >> N;

		long long A[N];
		for (long long i = 0; i < N; i++) {
			cin >> A[i];
		}

		cout << inversionCount(A, N) << endl;
	}

	return 0;
}
// } Driver Code Ends