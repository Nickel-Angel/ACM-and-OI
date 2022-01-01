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

const int maxn = 3e5 + 10;
int n, sum[maxn];
char s[maxn], t[maxn];

int main()
{
    scanf("%*d%*d");
    scanf("%s%s", s + 1, t + 1);
    n = strlen(s + 1);
    int ans = 0;
    for (int S = 0; S <= 1; ++S)
    {
        int sx = 0, sy = 0, tx = 0, ty = 0, x = 0, y = 0, dir = S;
        int res = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (s[i] == '0')
                ++sx;
            else
                ++sy;
            if (t[i] == '0')
                ++tx;
            else
                ++ty;
            if (dir == 0)
            {
                if (x + 1 > max(sx, tx))
                {
                    dir = 1;
                    ++y;
                }
                else
                {
                    ++res;
                    ++x;
                }
            }
            else
            {
                if (y + 1 > max(sy, ty))
                {
                    dir = 0;
                    ++x;
                }
                else
                {
                    ++res;
                    ++y;
                }
            }
            //printf("%d %d %d\n", x, y, res);
        }
        ans = max(ans, res - 1);
    }
    printf("%d\n", ans);
    return 0;
}