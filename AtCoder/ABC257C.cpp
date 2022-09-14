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
int n, m;
char s[maxn], t[maxn];

int main()
{
    scanf("%s%s", s + 1, t + 1);
    n = strlen(s + 1), m = strlen(t + 1);
    if (s[1] != t[1])
    {
        puts("No");
        return 0;
    }
    for (int i = 2, j = 2; j <= m; ++j)
    {
        if (s[i] == t[j])
        {
            ++i;
            continue;
        }
        else
        {
            if (s[i - 1] == t[j] && s[i - 1] == s[i - 2])
                continue;
            else
            {
                puts("No");
                return 0;
            }
        }
    }
    puts("Yes");
    return 0;
}