/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
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

const int maxn = 1e5 + 10;
char s[maxn], t[maxn];

int main()
{
    scanf("%s%s", s, t);
    int n = strlen(s), diff = (t[0] - s[0] + 26) % 26;
    for (int i = 1; i < n; ++i)
    {
        if (diff != (t[i] - s[i] + 26) % 26)
        {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}