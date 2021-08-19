#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>

const int maxn = 1010;
const int p = 1e9 + 7;
int n, T, C[maxn][maxn];
int head[maxn], to[maxn << 1], dir[maxn << 1], next[maxn << 1], tot = 0;
int f[maxn][maxn], size[maxn], sum[maxn], g[maxn];

template<typename T>
inline void input(T &x)
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

inline void add_edge(int u, int v, int w)
{
    to[++tot] = v;
    dir[tot] = w;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs(int u, int pre)
{
    size[u] = 1, f[u][1] = 1;
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == pre) continue;
        dfs(v, u);
        memcpy(g, f[u], sizeof(g));
        memset(f[u], 0, sizeof(f[u]));
        if (dir[c])
        {
            for (int i = 1; i <= size[v]; ++i)
                sum[i] = (sum[i - 1] + f[v][i]) % p;
            for (int i = 1; i <= size[u]; ++i)
                for (int j = 1; j <= size[v]; ++j)
                    f[u][i + j] = (f[u][i + j] + 1ll * g[i] * sum[j] % p
                    * C[i + j - 1][j] % p * C[size[u] + size[v] - i - j][size[u] - i] % p) % p;           
        }
        else
        {
            sum[size[v]] = f[v][size[v]];
            for (int i = size[v] - 1; i > 0; --i)
                sum[i] = (sum[i + 1] + f[v][i]) % p;
            for (int i = 1; i <= size[u]; ++i)
                for (int j = 0; j < size[v]; ++j)
                    f[u][i + j] = (f[u][i + j] + 1ll * g[i] * sum[j + 1] % p
                    * C[i + j - 1][j] % p * C[size[u] + size[v] - i - j][size[u] - i] % p) % p;
        }
        size[u] += size[v];
    }
}

int main()
{
    C[0][0] = 1;
    for (int i = 1; i <= 1000; ++i)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
        {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
        }
    }
    input(T);
    while (T--)
    {
        memset(head, 0, sizeof(head));
        tot = 0;
        input(n);
        for (int i = 1, u, v; i < n; ++i)
        {
            char ch;
            input(u), ch = getchar(), input(v);
            ++u, ++v;
            if (ch == '>')
                add_edge(u, v, 0), add_edge(v, u, 1);
            else
                add_edge(u, v, 1), add_edge(v, u, 0);
        }
        dfs(1, 0);
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            ans = (ans + f[1][i]) % p;
        printf("%d\n", ans);
    }
}