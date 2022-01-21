/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 10;
int m, d, s[maxn], id[maxn], top;

int main()
{
    cin >> m >> d;
    char opt;
    int tot = 0, ans = 0, pos, x;
    while (m--)
    {
        cin >> opt >> x;
        if (opt == 'A')
        {
            x = (1ll * x + ans) % d;
            while (top > 0 && s[top] <= x)
                --top;
            s[++top] = x;
            id[top] = ++tot;
        }
        else
        {
            x = tot - x + 1;
            pos = std::lower_bound(id + 1, id + top + 1, x) - id;
            ans = s[pos];
            printf("%d\n", ans);
        }
    }
    return 0;
}