/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

const int maxn = 2e5 + 10;
int n, a[maxn], cnt[maxn], pre[maxn], next[maxn];

inline void del(int x)
{
    pre[next[x]] = pre[x];
    next[pre[x]] = next[x];
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        pre[i] = i - 1, next[i] = i + 1;
    }
    next[n] = 0;
    puts("1");
    cnt[1] = 1;
    int d = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] == a[pre[i]])
        {
            cnt[i] = cnt[pre[i]] + 1;
            if (cnt[i] == a[i])
            {
                int pos = i;
                for (int j = 1; j <= cnt[i]; ++j)
                {
                    del(pos);
                    pos = pre[pos];
                }
                d += cnt[i];
            }
        }
        else
            cnt[i] = 1;
        printf("%d\n", i - d);
    }
    return 0;
}