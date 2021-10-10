/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 10000005;
int n, id[maxn];
int a[maxn], b[maxn];
unsigned seed;

inline unsigned rnd(unsigned x)
{
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return x;
}

inline int rad(int x, int y)
{
	seed = rnd(seed);
	return seed % (y - x + 1) + x;
}

inline void init_data()
{
	scanf("%u", &seed);
	for (int i = 1; i <= n; ++i)
		a[i] = 1, b[i] = rad(1, 500000);
	for (int i = 1; i <= n - 2; ++i)
		a[rad(1, n)]++;
}

int main()
{
    int type;
    scanf("%d%d", &type, &n);
    if (type)
        init_data();
    else
    {
        for (int i = 1; i <= n; ++i)
            scanf("%d", a + i);
        for (int i = 1; i <= n; ++i)
            scanf("%d", b + i);
    }
    for (int i = 1; i <= n; ++i)
        id[i] = i;
    std::sort(id + 1, id + n + 1, [&](int x, int y){return b[x] < b[y];});
    long long ans = 0;
    int bound = 2;
    for (int i = 1, j = 2, k = 2; i <= n; ++i)
    {
        if (a[id[i]] == 0)
            continue;
        j = std::max(j, i + 1);
        while (a[id[i]] > 1)
        {
            while (a[id[j]] == 0 && j < n)
                ++j;
            ans += 1ll * b[id[i]] * b[id[j]];
            if (a[id[j]] > 1)
                bound = j;
            --a[id[i]], --a[id[j]], ++j;
        }
        if (i < bound)
        {
            if (a[id[i]] == 0)
                continue;
            while (a[id[j]] == 0 && j < n)
                ++j;
            ans += 1ll * b[id[i]] * b[id[j]];
            if (a[id[j]] > 1)
                bound = j;
            --a[id[i]], --a[id[j]], ++j;
        }
        else
        {
            k = std::max(k, j);
            while (a[id[k]] <= 1 && k < n)
                ++k;
            ans += 1ll * b[id[i]] * b[id[k]];
            --a[id[i]], --a[id[k]], i = j;
            while (i < k && a[id[k]] > 1)
            {
                ans += 1ll * b[id[i]] * b[id[k]];
                --a[id[i]], --a[id[k]], ++i;
            }
            bound = a[id[k]] > 1 ? k : i;
            --i;
        }
    }
    printf("%lld\n", ans);
    return 0;
}