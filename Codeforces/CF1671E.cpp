/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;

const int maxn = (1 << 18) + 10;
const int p = 998244353;
int n, f[maxn];
string order[maxn], s;

#define lson ((u) << 1)
#define rson ((u) << 1 | 1)

void dfs(int u)
{
    f[u] = 1;
    if (lson > n)
    {
        order[u] = s[u];
        return;
    }
    dfs(lson), dfs(rson);
    if (order[lson] == order[rson])
        f[u] = 1ll * f[lson] * f[rson] % p;
    else
        f[u] = 2ll * f[lson] * f[rson] % p;
    if (order[lson] < order[rson])
        order[u] = s[u] + order[lson] + order[rson];
    else
        order[u] = s[u] + order[rson] + order[lson];
}

#undef lson
#undef rson

int main()
{
    cin >> n;
    n = (1 << n) - 1;
    cin >> s;
    s = " " + s;
    dfs(1);
    cout << f[1] << "\n";
    return 0;
}