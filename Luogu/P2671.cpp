/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int p = 10007;
const int maxn = 1e5 + 10;
int n, m, num[maxn];
std::vector<int> pos[maxn << 1];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", num + i);
    for (int i = 1, c; i <= n; ++i)
    {
        scanf("%d", &c);
        pos[c + i % 2 * m].push_back(i);
    }
    int ans = 0;
    for (int i = 1, x, sum; i <= 2 * m; ++i)
    {
        if (pos[i].size() < 2)
            continue;
        x = pos[i].size() - 2, sum = 0;
        for (int j : pos[i])
            sum = (sum + num[j]) % p;
        for (int j : pos[i])
            ans = (ans + 1ll * j * sum % p + 1ll * x * j % p * num[j] % p) % p;
    }
    printf("%d\n", ans);
    return 0;
}