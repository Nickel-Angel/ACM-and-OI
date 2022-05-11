/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int maxn = 1e5 + 10;
int n, a[maxn], unknown[maxn][2], pre[maxn][2], next[maxn][2];
std::vector<int> ans;

class Segtree
{
    #define lson (u << 1)
    #define rson (u << 1 | 1)
  private:
    int v[maxn << 2], bound;

    void build(int l, int r, int u)
    {
        if (l == r)
        {
            v[u] = 0;
            return;
        }
        int mid = (l + r) >> 1;
        build(l, mid, lson), build(mid + 1, r, rson);
    }

    inline void pushdown(int u)
    {
        if (!lazy[u])
            return;
        lazy[lson] = std::max(lazy[lson], lazy[u]);
        lazy[rson] = std::max(lazy[rson], lazy[u]);
    }
  public:
    
    #undef lson
    #undef rson
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        if (a[i] == -1)
            unknown[i][0] = unknown[i - 1][0] + 1;
        else
            unknown[i][0] = 0;
    }
    for (int i = n; i > 0; --i)
    {
        if (a[i] == -1)
            unknown[i][1] = unknown[i + 1][1] + 1;
        else
            unknown[i][1] = 0;
    }
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] == -1 || a[i - 1] == a[i])
        {
            pre[i][0] = pre[i - 1][0] + 1;
            pre[i][1] = pre[i - 1][1] + 1;
        }
        else
        {
            if (a[i - 1] == -1)
            {
                pre[i][0] = unknown[i - 1][0];
                pre[i][1] = unknown[i - 1][0];
                continue;
            }
            if (a[i - 1] < a[i])
            {
                pre[i][0] = 0;
                pre[i][1] = pre[i - 1][1] + 1;
            }
            else
            {
                pre[i][0] = pre[i - 1][0] + 1;
                pre[i][1] = 0;
            }
        }
    }
    for (int i = n - 1; i > 0; --i)
    {
        if (a[i] == -1 || a[i] == a[i - 1])
        {
            next[i][0] = next[i + 1][0] + 1;
            next[i][1] = next[i + 1][1] + 1;
        }
        else
        {
            if (a[i + 1] == -1)
            {
                next[i][0] = unknown[i + 1][1];
                next[i][1] = unknown[i + 1][1];
                continue;
            }
            if (a[i] < a[i + 1])
            {
                next[i][0] = 0;
                next[i][1] = next[i + 1][1] + 1;
            }
            else
            {
                next[i][0] = next[i + 1][0] + 1;
                next[i][1] = 0;
            }
        }
    }
    bool flag;
    for (int i = 3, l, r; i <= n; ++i)
    {
        if (n - i * ((n + i - 1) / i - 1) < 3)
            continue;
        flag = true;
        for (int j = 1; j <= (n + i - 1) / i; ++j)
        {
            l = i * (j - 1) + 1, r = std::min(i * j, n);
            if (next[l][1])
            {
                flag &= (l + next[l][1] >= r && pre[r][0]) || (l + next[l][1] < r && l + next[l][1] + next[l + next[l][1]][0] >= r);
                if (i == 9)
                    printf("a [%d, %d] %d %d\n", l, r, l + next[l][1], l + next[l][1] + next[l + next[l][1]][0]);
            }
            else
            {
                if (i == 9)
                    printf("b [%d, %d] %d %d\n", l, r, l + next[l][1], l + next[l][1] + next[l + next[l][1]][0]);
                flag = false;
                break;
            }
        }
        if (flag)
            ans.push_back(i);
    }
    printf("%zu\n", ans.size());
    for (int i : ans)
        printf("%d\n", i);
    return 0;
}