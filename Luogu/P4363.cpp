/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <map>
#include <iostream>

typedef unsigned long long ull;

const int base = 11;
const int inf = 0x3f3f3f3f;
int n, m;
int deployed[15], a[15][15], b[15][15];

std::map<ull, int> score;

inline int max(int x, int y)
{
    return x > y ? x : y;
}

inline int min(int x, int y)
{
    return x < y ? x : y;
}

inline ull hash()
{
    ull res = 0;
    for (int i = 1; i <= n; ++i)
        res = res * base + deployed[i];
    return res;
}

inline void unzip(ull state)
{
    for (int i = n; i > 0; --i)
    {
        deployed[i] = state % base;
        state /= base;
    }
}

inline int gettype()
{
    int res = 0;
    for (int i = 1; i <= n; ++i)
        res += deployed[i];
    return res & 1;
}

int dfs(ull state)
{
    if (score.find(state) != score.end()) return score[state];
    unzip(state);
    int type = gettype();
    int res = type ? inf : -inf;
    for (int i = 1; i <= n; ++i)
    {
        if (deployed[i - 1] <= deployed[i]) continue;
        ++deployed[i];
        ull cur = hash();
        if (type) res = min(res, dfs(cur) - b[i][deployed[i]]);
        else res = max(res, dfs(cur) + a[i][deployed[i]]);
        --deployed[i];
    }
    score[state] = res;
    return res;
}

int main()
{
    score.clear();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", a[i] + j);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", b[i] + j);
        }
    }
    for (int i = 0; i <= n; ++i)
        deployed[i] = m;
    score[hash()] = 0;
    dfs(0);
    printf("%d\n", score[0]);
    return 0;
}