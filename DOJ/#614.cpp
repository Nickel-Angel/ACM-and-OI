/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;

int n, m, b, L[3010][3010], R[3010][3010], near[3010];
char s[3010][3010];
std::vector<int> del[3010];

class BIT
{
  private:
    int v[6010], tag[6010], tim = 0, bound;

    inline int lowbit(int x)
    {
        return x & -x;
    }

  public:
    inline void build(int n)
    {
        bound = n;
        ++tim;
    }

    inline void add(int pos, int x)
    {
        for (int i = pos; i <= bound; i += lowbit(i))
        {
            if (tag[i] < tim)
            {
                tag[i] = tim;
                v[i] = 0;
            }
            v[i] += x;
        }
    }

    inline int query(int pos)
    {
        int res = 0;
        for (int i = pos; i > 0; i -= lowbit(i))
        {
            if (tag[i] < tim)
            {
                tag[i] = tim;
                v[i] = 0;
                continue;
            }
            res += v[i];
        }
        return res;
    }

    inline int query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
}tree;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%s", s[i] + 1);
    b = std::min(n, m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            L[i][j] = s[i][j] == 'z' ? L[i][j - 1] + 1 : 0;
        for (int j = m; j > 0; --j)
            R[i][j] = s[i][j] == 'z' ? R[i][j + 1] + 1 : 0;
    }
    long long ans = 0;
    for (int i = 1, len; i <= m; ++i)
    {
        len = min(i, n);
        tree.build(len);
        near[len + 1] = len + 1;
        for (int j = len; j > 0; --j)
            near[j] = s[j][i - j + 1] == 'z' ? near[j + 1] : j;
        for (int j = 1; j <= len; ++j)
        {
            for (int k : del[j])
                tree.add(k, -1);
            del[j].clear();
            if (L[j][i - j + 1])
            {
                if (min(j + L[j][i - j + 1], near[j]) <= len)
                    del[min(j + L[j][i - j + 1], near[j])].push_back(j);
                tree.add(j, 1);
                ans += tree.query(j - R[j][i - j + 1] + 1, j);
            }   
        }
    }
    for (int i = 2, len; i <= n; ++i)
    {
        len = min(n - i + 1, m);
        tree.build(len);
        near[len + 1] = len + 1;
        for (int j = len; j > 0; --j)
            near[j] = s[i + j - 1][m - j + 1] == 'z' ? near[j + 1] : j;
        for (int j = 1; j <= len; ++j)
        {
            for (int k : del[j])
                tree.add(k, -1);
            del[j].clear();
            if (L[i + j - 1][m - j + 1])
            {
                if (min(j + L[i + j - 1][m - j + 1], near[j]) <= len)
                    del[min(j + L[i + j - 1][m - j + 1], near[j])].push_back(j);
                tree.add(j, 1);
                ans += tree.query(j - R[i + j - 1][m - j + 1] + 1, j);
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}