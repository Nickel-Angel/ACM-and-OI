/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n;
char s[110], t[110];

inline void solve()
{
    scanf("%d%s", &n, s + 1);
    memset(t, 0, sizeof(t));
    for (int i = 1; i <= n; ++i)
    {
        if (s[i] == 'U')
            t[i] = 'D';
        else if (s[i] == 'D')
            t[i] = 'U';
        else if (s[i] == 'L')
            t[i] = 'L', t[i + 1] = 'R'; 
    }
    printf("%s\n", t + 1);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}