/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::max;
using std::min;
using std::pair;
using std::sort;
using std::swap;
using std::vector;

typedef long long ll;

const int maxn = 1e6 + 20;
char s[maxn], t[20];
int n, q, next[maxn], fail[maxn][26];

int main()
{
    scanf("%s%d", s + 1, &q);
    n = strlen(s + 1);
    next[1] = 0, fail[0][s[1] - 'a'] = 1;
    for (int i = 2; i <= n; ++i)
    {
        next[i] = fail[next[i - 1]][s[i] - 'a'];
        fail[i - 1][s[i] - 'a'] = i;
        for (int j = 0; j < 26; ++j)
        {
            if (s[i] == 'a' + j)
                continue;
            fail[i - 1][j] = fail[next[i - 1]][j];
            // printf("%d%c", fail[i][j], " \n"[j == 25]);
        }
    }
    int m;
    while (q--)
    {
        scanf("%s", t + 1);
        m = strlen(t + 1);
        for (int i = n + 1; i <= n + m; ++i)
        {
            s[i] = t[i - n];
            next[i] = fail[next[i - 1]][s[i] - 'a'];
            fail[i - 1][s[i] - 'a'] = i;
            for (int j = 0; j < 26; ++j)
            {
                if (s[i] == 'a' + j)
                    continue;
                fail[i - 1][j] = fail[next[i - 1]][j];
                // printf("%d%c", fail[i][j], " \n"[j == 25]);
            }
            printf("%d%c", next[i], " \n"[i == n + m]);
        }
    }
    return 0;
}