/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <bitset>

using std::bitset;

int n;
bitset<1010> f[5]; 

inline void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < 5; ++i)
        f[i].reset();
    for (int i = 1, x; i <= n; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            scanf("%d", &x);
            f[j] <<= 1;
            f[j][0] = x;
        }
    }
    bool flag = false;
    for (int i = 0; i < 5; ++i)
    {
        if (f[i].count() < n / 2)
            continue;
        for (int j = i + 1; j < 5; ++j)
        {
            if (f[j].count() < n / 2)
                continue;
            if ((f[i] | f[j]).count() == n)
            {
                flag = true;
                break;
            }
        }
    }
    puts(flag ? "YES" : "NO");
}

int main()
{   
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}