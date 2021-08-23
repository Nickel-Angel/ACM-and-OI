/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::sort;
using std::vector;

const int maxn = 1e5 + 10;
int n, cnt[2];
vector<int> num[2];

int main()
{
    scanf("%d", &n);
    long long ans = 0;
    for (int i = 0, x; i < n; ++i)
    {
        scanf("%d", &x);
        ans += x;
        if (x < 0)
            num[(-x) & 1].push_back(x);
        else
            num[(x & 1) ^ 1].push_back(x);
    }
    sort(num[0].begin(), num[0].end(), [](int x, int y){return abs(x) > abs(y);});
    sort(num[1].begin(), num[1].end(), [](int x, int y){return abs(x) > abs(y);});
    int i = 1, id;
    for (; i <= n; ++i)
    {
        id = i & 1;
        if (cnt[id] == num[id].size())
            break;
        ans += 1ll * (n - i) * abs(num[id][cnt[id]]);
        ++cnt[id];
    }
    bool flag = false;
    id = (i & 1) ^ 1;
    for (int j = (int)num[id].size() - 1; i <= n; ++i, flag ^= 1)
    {
        if (flag)
        {
            ans += 1ll * (n - i) * abs(num[id][cnt[id]]);
            ++cnt[id];
        }
        else
        {
            ans -= 1ll * (n - i) * abs(num[id][j]);
            --j;
        }
    }
    printf("%lld\n", ans);
    return 0;
}