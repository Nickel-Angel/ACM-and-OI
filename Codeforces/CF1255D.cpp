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

const char alphabet[] = "1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
int r, c, k;
char s[110][110], ans[110];

inline void solve()
{
    int tot = 0;
    memset(ans, 0, sizeof(ans));
    scanf("%d%d%d", &r, &c, &k);
    for (int i = 1; i <= r; ++i)
    {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= c; ++j)
        {
            if (s[i][j] == 'R')
                ++tot;
        }
    }
    int cnt = tot % k, avg = tot / k;
    int id = 0, rice = cnt > 0 ? avg + 1 : avg;
    --cnt;
    for (int i = 1; i <= r; ++i)
    {
        if (i & 1)
        {
            for (int j = 1; j <= c; ++j)
            {
                ans[j - 1] = alphabet[id];
                if (s[i][j] == 'R')
                    --rice;
                if (rice == 0 && id != k - 1)
                {
                    ++id;
                    rice = cnt > 0 ? avg + 1 : avg;
                    --cnt;
                }
            }
        }
        else
        {
            for (int j = c; j > 0; --j)
            {
                ans[j - 1] = alphabet[id];
                if (s[i][j] == 'R')
                    --rice;
                if (rice == 0 && id != k - 1)
                {
                    ++id;
                    rice = cnt > 0 ? avg + 1 : avg;
                    --cnt;
                }
            }
        }
        puts(ans);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}