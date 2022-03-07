/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

const int maxn = 2e5 + 10;
const int p = 1e9 + 7;
int n, m, a[maxn], f[maxn];
std::set<int> s;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    bool flag = false;
    for (int i = 1, x; i <= n; ++i)
    {
        x = a[i];
        flag = false;
        while (x)
        {
            if (s.count(x))
            {
                flag = true;
                break;
            }
            if (x & 1)
                x >>= 1;
            else if (x & 2)
                break;
            else
                x >>= 2;
        }
        if (!flag)
        {
            s.insert(a[i]);
            int cnt = 0;
            while (a[i])
            {
                a[i] >>= 1;
                ++cnt;
            }
            ++f[cnt];
        }
    }
    int ans = 0;
    for (int i = 0; i <= m; ++i)
    {
        if (i > 0)
            f[i] = (f[i - 1] + f[i]) % p;
        if (i > 1)
            f[i] = (f[i - 2] + f[i]) % p;
        ans = (ans + f[i]) % p;
    }
    printf("%d\n", ans);
    return 0;
}