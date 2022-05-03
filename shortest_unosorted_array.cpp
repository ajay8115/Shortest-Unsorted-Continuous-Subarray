#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &a)
    {
        int n = a.size();

        int f = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > a[i + 1])
            {
                f = 1;
            }
        }

        if (f == 0)
        {
            return 0;
        }

        int minr[n];
        int maxl[n];

        int maxi = a[0];
        for (int i = 0; i < n; i++)
        {
            maxl[i] = max(a[i], maxi);
            maxi = max(maxi, a[i]);
        }

        int mini = a[n - 1];

        for (int i = n - 1; i >= 0; i--)
        {
            minr[i] = min(a[i], mini);
            mini = min(mini, a[i]);
        }

        int i;
        for (i = 0; i < n; i++)
        {
            if (a[i] != minr[i])
            {
                break;
            }
        }

        int j;
        for (j = n - 1; j >= 0; j--)
        {
            if (a[j] != maxl[j])
            {
                break;
            }
        }

        return (j - i + 1);
    }
};