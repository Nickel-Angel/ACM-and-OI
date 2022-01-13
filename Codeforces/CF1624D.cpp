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
int n, k, cnt[26];
char s[maxn];

inline void solve()
{
    scanf("%d%d%s", &n, &k, s + 1);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; ++i)
        ++cnt[s[i] - 'a'];
    int sum = 0, rem = 0;
    for (int i = 0; i < 26; ++i)
        sum += cnt[i] / 2, rem += cnt[i] % 2;
    printf("%d\n", sum / k * 2 + (sum % k * 2 + rem >= k));
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}