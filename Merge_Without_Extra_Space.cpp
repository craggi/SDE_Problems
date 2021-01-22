#include <bits/stdc++.h>
using namespace std;

int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}
void merge(int a[], int b[], int n, int m)
{
    //Solution 1:
    // Time Complexity : o(mn) space : o(1)
    int i = 0, j = 0;
    while (i < n)
    {
        if (a[i] > b[j])
        {
            swap(a[i], b[j]);

            int f = b[j], k;

            for (k = 1; k < m && b[k] < f; k++)
            {
                b[k - 1] = b[k];
            }
            b[k - 1] = f;
        }
        i++;

    }
    //Solution 2:
    //Time Complexity : o(m+n) Space : o(1)

    int gap = m + n;
    int i, j;
    for (gap = nextGap(gap);
            gap > 0; gap = nextGap(gap))
    {
        for (i = 0; i + gap < n; i++)
        {
            if (a[i] > a[i + gap])
                swap(a[i], a[i + gap]);
        }
        for (j = gap > n ? gap - n : 0; i < n && j < m ; i++, j++)
        {
            if (a[i] > b[j])
                swap(a[i], b[j]);
        }
        if (j < m)
        {
            for (j = 0; j + gap < m; j++)
                if (b[j] > b[j + gap])
                    swap(b[j], b[j + gap]);
        }
    }

}

int main()
{
    std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        int arr1[n], arr2[m];

        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }

        for (int i = 0; i < m; i++) {
            cin >> arr2[i];
        }

        merge(arr1, arr2, n, m);

        for (int i = 0; i < n; i++)
            printf("%d ", arr1[i]);


        for (int i = 0; i < m; i++)
            printf("%d ", arr2[i]);

        cout << endl;
    }

    return 0;
}