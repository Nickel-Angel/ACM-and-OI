/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>

using std::vector;

const int maxn = 3e5 + 10;
int n, m, a[maxn];
bool vis[maxn];
std::map<int, vector<int>> S;

class Trie
{
  private:
    int ch[maxn * 35][2], end[maxn * 35], tot;

  public:
    inline void clear()
    {
        for (int i = 0; i <= tot; ++i)
        {
            ch[i][0] = ch[i][1] = 0;
            end[i] = 0;
        }
    }

    inline void add(int x)
    {
        int u = 0;
        for (int i = 29, id; i >= 0; --i)
        {
            id = (x >> i) & 1;
            if (!ch[u][id])
                ch[u][id] = ++tot;
            u = ch[u][id];
        }
        end[u] = x;
    }

    inline int query(int x)
    {
        int u = 0;
        for (int i = 29, id; i >= 0; --i)
        {
            id = (x >> i) & 1;
            if (ch[u][!id])
                u = ch[u][!id];
            else if (ch[u][id])
                u = ch[u][id];
            else
                break;
        }
        return end[u] ^ x;
    }
}tree;

int main()
{
    scanf("%d%d", &n, &m);
    int bound = 29;
    if (m == 0)
    {
        printf("%d\n", n);
        for (int i = 1; i <= n; ++i)
            printf("%d ", i);
        puts("");
        return 0;
    }
    while (((m >> bound) & 1) == 0)
        --bound;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        S[a[i] >> (bound + 1)].push_back(i);
    }
    int cnt = 0;
    bool flag;
    for (auto v : S)
    {
        flag = false;
        for (int i : v.second)
        {
            if (tree.query(a[i]) >= m)
            {
                for (int j : v.second)
                {
                    if ((a[i] ^ a[j]) >= m)
                    {
                        vis[i] = vis[j] = true;
                        cnt += 2;
                        flag = true;
                        tree.clear();
                        break;
                    }
                }
            }
            else
                tree.add(a[i]);
            if (flag)
                break;
        }
        if (!flag)
        {
            ++cnt;
            vis[v.second[0]] = true;
            tree.clear();
        }
    }
    if (cnt < 2)
    {
        puts("-1");
        return 0;
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i])
            printf("%d ", i);
    }
    return 0;
}