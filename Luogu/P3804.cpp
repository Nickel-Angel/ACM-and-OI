/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e6 + 10;
int n, sublen;
long long ans;
char s[maxn];

class suffix_tree
{
  private:
    static const int inf = 0x3f3f3f3f;
    int link[maxn << 1], len[maxn << 1], start[maxn << 1], s[maxn << 1];
    int wtot, ntot, cur, rem, ch[maxn << 1][27];

    inline int newnode(int pos, int le)
    {
        link[++ntot] = 1, start[ntot] = pos, len[ntot] = le;
        return ntot;
    }

  public:
    suffix_tree()
    {
        cur = 1, ntot = 1;
        wtot = 0, rem = 0;
        len[0] = inf;
    }
    
    inline void extend(int x)
    {
        s[++wtot] = x, ++rem;
        int last = 1, c;
        while (rem)
        {
            while (rem > len[ch[cur][s[wtot - rem + 1]]])
            {
                cur = ch[cur][s[wtot - rem + 1]];
                rem -= len[cur];
            }
            int &v = ch[cur][s[wtot - rem + 1]];
            c = s[start[v] + rem - 1];
            if (!v || x == c)
            {
                link[last] = cur, last = cur;
                if (!v)
                    v = newnode(wtot, inf);
                else
                    break;
            }
            else
            {
                int u = newnode(start[v], rem - 1);
                ch[u][c] = v, ch[u][x] = newnode(wtot, inf);
                start[v] += rem - 1, len[v] -= rem - 1;
                v = u, link[last] = u, last = u; 
            }
            if (cur == 1)
                --rem;
            else
                cur = link[cur];
        }
    }

    int dfs(int u)
    {
        sublen += len[u];
        int leaf = 0;
        for (int i = 0; i < 27; ++i)
        {
            if (ch[u][i])
                leaf += dfs(ch[u][i]);
        }
        if (leaf > 1)
            ans = std::max(ans, 1ll * leaf * sublen);
        sublen -= len[u];
        return std::max(1, leaf);
    }
}tree;

int main()
{
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; ++i)
        tree.extend(s[i] - 'a');
    tree.extend(26);
    tree.dfs(1);
    printf("%lld\n", ans);
    return 0;
}