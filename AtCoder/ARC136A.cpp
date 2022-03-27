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
int n;
char s[maxn], t[maxn];

int main()
{
    scanf("%d%s", &n, s);
    int cnta = 0, cntb = 0, k = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'C')
        {
            for (int j = 1; j <= cnta; ++j)
                t[++k] = 'A';
            for (int j = 1; j <= cntb / 2; ++j)
                t[++k] = 'A';
            if (cntb & 1)
                t[++k] = 'B';
            cnta = 0, cntb = 0;
            t[++k] = 'C';
            continue;
        }
        cnta += s[i] == 'A';
        cntb += s[i] == 'B';
    }
    for (int i = 1; i <= cnta; ++i)
        t[++k] = 'A';
    for (int i = 1; i <= cntb / 2; ++i)
        t[++k] = 'A';
    if (cntb & 1)
        t[++k] = 'B';
    puts(t + 1);
    return 0;
}