#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
public:
    vector <int> commonElements (int ar1[], int ar2[], int ar3[], int n1, int n2, int n3)
    {
        /* set<int>s;
         s.insert(a,a+n1);
         set<int>t;
         set<int>x;
         vector<int>ans;
         for(int i=0;i<n2;i++)
         {
             if(s.find(b[i])  != s.end())
             t.insert(b[i]);
         }
         for(int i=0;i<n3;i++)
         {
             if(t.find(c[i]) != t.end())
             {
                 x.insert(c[i]);
             }
         }
         ans.assign(x.begin(),x.end());
         return ans;*/
        int i = 0, j = 0, k = 0;
        vector<int>ans;
        set<int>s;
        while (i < n1 && j < n2 && k < n3)
        {
            if (ar1[i] == ar2[j] && ar2[j] == ar3[k])
            {
                if (s.find(ar1[i]) == s.end())
                    s.insert(ar1[i]);
                i++; j++; k++;

            }

            else if (ar1[i] < ar2[j])
                i++;

            else if (ar2[j] < ar3[k])
                j++;
            else
                k++;
        }
        ans.assign(s.begin(), s.end());
        return ans;
    }

};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];

        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];

        Solution ob;

        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0)
            cout << -1;
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout << endl;
    }
}  // } Driver Code Ends