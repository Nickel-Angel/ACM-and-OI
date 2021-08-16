/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <iostream>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::isdigit;
using std::isalpha;
using std::memset;
using std::memcpy;

typedef std::pair<int, int> P;

inline void input_number(int &x)
{
    x = 0;
    char ch = getchar();
    bool f = false;
    while (!isdigit(ch))
    {
        f |= (ch == '-');
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar(); 
    }
    x = f ? -x : x;
}

inline void input_alpha(char &ch)
{
    ch = getchar();
    while (!isalpha(ch)) ch = getchar();
}

const int maxn = 1e5 + 10, bound = 1e4 + 10, p = 998244353;
int n, id[maxn], tot = 0;
int root[maxn][26], longest[maxn][26], len[maxn], ans[maxn];
P key[maxn], cur[maxn];
std::vector<int> e[maxn];

class Peresistable_Tree
{
  private:
    int ch[maxn * 50][2], lazy[maxn * 50], sum[maxn * 50], fail[maxn * 50], tot;
  
    inline void copy(int u, int model)
    {
        ch[u][0] = ch[model][0], ch[u][1] = ch[model][1];
        lazy[u] = lazy[model], sum[u] = lazy[model], fail[u] = fail[model];
    }

    inline void pushdown(int u, int s, int e)
    {
        if (!lazy[u]) return;
        int mid = (s + e) >> 1;
        ++tot, copy(tot, ch[u][0]), ch[u][0] = tot;
        sum[ch[u][0]] = 1ll * lazy[u] * (mid - s + 1) % p;
        ++tot, copy(tot, ch[u][1]), ch[u][1] = tot;
        sum[ch[u][1]] = 1ll * lazy[u] * (e - mid) % p;
        lazy[ch[u][0]] = lazy[u], lazy[ch[u][1]] = lazy[u];
        lazy[u] = 0;
    }

  public:
    inline void clear()
    {
        tot = 0;
    }

    void modify(int s, int e, int &u, int pos, int key, int next)
    {
        ++tot;
        copy(tot, u), u = tot;
        if (e < pos)
        {
            sum[u] = 1ll * key * (e - s + 1) % p;
            lazy[u] = key;
            return;
        }
        if (s == e)
        {
            fail[u] = next;
            sum[u] = key, lazy[u] = key;
            return;
        }
        pushdown(u, s, e);
        int mid = (s + e) >> 1;
        modify(s, mid, ch[u][0], pos, key, next);
        if (pos > mid) modify(mid + 1, e, ch[u][1], pos, key, next);
        sum[u] = (sum[ch[u][0]] + sum[ch[u][1]]) % p;
    }

    void query(int s, int e, int u, int pos, int &res, int &next)
    {
        if (e < pos) 
        {
            res = (res + sum[u]) % p;
            return;
        }
        if (s == e) 
        {
            res = (res + sum[u]) % p, next = fail[u];
            return;
        }
        pushdown(u, s, e);
        int mid = (s + e) >> 1;
        query(s, mid, ch[u][0], pos, res, next);
        if (pos > mid) query(mid + 1, e, ch[u][1], pos, res, next);
    }
}tree;

inline int calc(int x)
{
    return ((1ll * (x + 1) * x) >> 1) % p;
}

void dfs(int u)
{
    ++tot;
    int x, c, next = 0;
    x = key[u].first, c = key[u].second;
    cur[tot] = key[u], len[tot] = len[tot - 1] + x;
    if (tot == 1) ans[u] = calc(x - 1);
    else
    {
        ans[u] = (ans[u] + calc(min(x, longest[tot][c]))) % p;
        tree.query(1, bound, root[tot][c], x, ans[u], next);
        if (!next && cur[1].second == c && len[1] < x) 
        {
            next = 1;
            ans[u] = (ans[u] + 1ll * len[1] * max(0, x - longest[tot][c])) % p;
        }
    }
    longest[tot][c] = max(longest[tot][c], x);
    tree.modify(1, bound, root[tot][c], x, len[tot - 1], tot);
    for (int i = 0, v; i < (int)e[u].size(); ++i)
    {
        v = e[u][i];
        memcpy(root[tot + 1], root[next + 1], sizeof(root[tot + 1]));
        memcpy(longest[tot + 1], longest[next + 1], sizeof(longest[tot + 1]));
        ans[v] = ans[u];
        dfs(v);
    }
    --tot;
}

int main()
{
    input_number(n);
    for (int i = 1, cnt = 0, opt, x; i <= n; ++i)
    {
        input_number(opt), input_number(x);
        if (opt == 1)
        {
            char c;
            input_alpha(c);
            id[i] = ++cnt;
            key[cnt] = P(x, (int)(c - 'a'));
            e[id[i - 1]].push_back(cnt);
        }
        else id[i] = id[x];
    }
    for (int i = 0; i < (int)e[0].size(); ++i)
    {
        tot = 0;
        tree.clear();
        memset(root[1], 0, sizeof(root[1]));
        memset(longest[1], 0, sizeof(longest[1]));
        dfs(e[0][i]);
    }
    for (int i = 1; i <= n; ++i)
        printf("%d\n", ans[id[i]]);
    return 0;
}