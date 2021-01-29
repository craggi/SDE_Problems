// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// function to find the triplet which sum to x
// arr[] : The input Array
// N : Size of the Array
// X : Sum which you need to search for

bool find3Numbers(int a[], int n, int x)
{
  sort(a, a + n);
  int l, r;
  for (int i = 0; i < n - 2; i++)
  {
    int t = x - a[i];
    l = i + 1;
    r = n - 1;
    while (l < r)
    {
      if ( a[l] + a[r] == t)
        return true;
      else if (a[l] + a[r] > t)
        r--;
      else
        l++;
    }
  }
  return false;
}


// { Driver Code Starts.

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int N, sum;
    cin >> N >> sum;
    int i, A[N];
    for (i = 0; i < N; i++)
      cin >> A[i];
    cout <<  find3Numbers(A, N, sum) << endl;
  }
}
// } Driver Code Ends