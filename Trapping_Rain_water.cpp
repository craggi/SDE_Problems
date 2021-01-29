#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends




// function to find the trapped water in between buildings
// arr: input array
// n: size of array
int trappingWater(int a[], int n) {

  //solution 1:
  //Time complexity O(n) Space O(2n)
  /*int p[n],s[n],ans=0;
  s[n-1]=a[n-1];
  p[0]=a[0];
  for(int i=1;i<n;i++)
  {
    p[i]=max(p[i-1],a[i]);
    s[n-i-1]=max(s[n-i],a[n-i-1]);
  }
   for(int i=0;i<n;i++)
   {
       ans+=(min(s[i],p[i])-a[i]);
   }
   return ans;*/

  //Solution 2:
  //Time Complexity O(n) Space O(1)

  int l = 0, r = n - 1, lm = 0, rm = 0, ans = 0;
  while (l <= r)
  {
    if (a[l] < a[r])
    {
      if (a[l] >= lm)
        lm = a[l];
      else
        ans += lm - a[l];
      l++;
    }
    else
    {
      if (a[r] >= rm)
        rm = a[r];
      else
        ans += rm - a[r];
      r--;
    }
  }
  return ans;

}

// { Driver Code Starts.

int main() {

  int t;
  //testcases
  cin >> t;

  while (t--) {
    int n;

    //size of array
    cin >> n;

    int a[n];

    //adding elements to the array
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    //calling trappingWater() function
    cout << trappingWater(a, n) << endl;

  }

  return 0;
}  // } Driver Code Ends