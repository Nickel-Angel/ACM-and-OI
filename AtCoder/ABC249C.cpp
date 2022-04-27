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

int n, k, cnt[20][30], cur[30];
char s[30];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0, len; i < n; ++i)
    {
        scanf("%s", s);
        len = strlen(s);
        for (int j = 0; j < len; ++j)
            ++cnt[i][s[j] - 'a'];
    }
    int ans = 0, res;
    for (int S = 0; S < (1 << n); ++S)
    {
        res = 0;
        memset(cur, 0, sizeof(cur));
        for (int i = 0; i < n; ++i)
        {
            if ((S >> i) & 1)
            {
                for (int j = 0; j < 26; ++j)
                    cur[j] += cnt[i][j];
            }
        }
        for (int i = 0; i < 26; ++i)
        {
            if (cur[i] == k)
                ++res;
        }
        ans = max(ans, res);
    }
    printf("%d\n", ans);
    return 0;
}