/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 10;
int n, a[maxn], f[512], g[512];
std::vector<int> ans;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        memcpy(g, f, sizeof(f));
        for (int j = 0; j < 512; ++j)
        {
            if (f[a[i] ^ j] < a[i])
                g[j] = std::min(g[j], a[i]);
        }
        memcpy(f, g, sizeof(g));
    }
    for (int i = 0; i < 512; ++i)
    {
        if (f[i] < inf)
            ans.push_back(i);
    }
    printf("%zu\n", ans.size());
    for (int e : ans)
        printf("%d ", e);
    return 0;
}