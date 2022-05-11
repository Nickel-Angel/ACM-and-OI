/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int maxm = 3e5 + 10;
int n, k, ans;
char s[maxm];

class Trie
{
  private:
    int ch[maxm][26], end[maxm], tot;
    std::vector<int> e[maxm];

  public:
    inline void init()
    {
        memset(ch, 0, sizeof(ch));
        tot = 0;
    }

    inline void add(char *s)
    {
        int u = 0, len = strlen(s);
        for (int i = 0, id; i < len; ++i)
        {
            id = s[i] - 'a';
            if (!ch[u][id])
            {
                ch[u][id] = ++tot;
                e[u].push_back(ch[u][id]);
            }
            u = ch[u][id];
        }
        end[u] = 1;
    }

    void dfs(int u)
    {
        std::vector<int> vec;
        for (int v : e[u])
        {
            dfs(v);
            end[u] += end[v];
            vec.push_back(end[v]);
        }
        std::sort(vec.begin(), vec.end());
        while (end[u] > k)
        {
            ++ans;
            end[u] -= vec.back();
            vec.pop_back();
        }
        if (u == 0)
            ans += !!end[u];
    }
}tree;

int main()
{
    scanf("%d%d", &n, &k);
    tree.init();
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", s);
        tree.add(s);
    }
    tree.dfs(0);
    printf("%d\n", ans);
    return 0;
}