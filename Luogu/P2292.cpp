/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

const int maxn = 2e6 + 10;
int n, m, f[maxn];
char s[maxn];

class Trie
{
  private:
    int ch[410][26], fail[410], g[410], end[410], tot;
    std::vector<int> e[410];

  public:
    inline void init()
    {
        tot = 0;
        memset(fail, 0, sizeof(fail));
        memset(ch, 0, sizeof(ch));
    }

    inline void add(char *s)
    {
        int u = 0, len = strlen(s);
        for (int i = 0; i < len; ++i)
        {
            if (!ch[u][s[i] - 'a'])
                ch[u][s[i] - 'a'] = ++tot;
            u = ch[u][s[i] - 'a'];
        }
        end[u] = len;
    }

    inline void build()
    {
        std::queue<int> q;
        for (int i = 0; i < 26; ++i)
        {
            if (ch[0][i])
            {
                q.push(ch[0][i]);
                e[0].push_back(ch[0][i]);
            }
        }
        int u;
        while (!q.empty())
        {
            u = q.front();
            q.pop();
            for (int i = 0; i < 26; ++i)
            {
                if (ch[u][i])
                {
                    q.push(ch[u][i]);
                    fail[ch[u][i]] = ch[fail[u]][i];
                    e[fail[ch[u][i]]].push_back(ch[u][i]);
                }
                else
                    ch[u][i] = ch[fail[u]][i];
            }
        }
    }

    void dfs(int u)
    {
        g[u] = g[fail[u]] | (end[u] ? (1 << (end[u] - 1)) : 0);
        for (int v : e[u])
            dfs(v);
    }

    inline int query(char *s)
    {
        int len = strlen(s + 1), cur = 0, u = 0;
        for (int i = 1; i <= len; ++i)
        {
            u = ch[u][s[i] - 'a'];
            cur = ((cur << 1) | f[i - 1]) & ((1 << 20) - 1);
            f[i] = (cur & g[u]) != 0;
        }
        for (int i = len; i > 0; --i)
        {
            if (f[i])
                return i;
        }
        return 0;
    }
}AC;

int main()
{
    scanf("%d%d", &n, &m);
    AC.init();
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", s);
        AC.add(s);
    }
    AC.build();
    AC.dfs(0);
    f[0] = true;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%s", s + 1);
        printf("%d\n", AC.query(s));
    }
    return 0;
}