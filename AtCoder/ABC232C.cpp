/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>

using std::pair;
using std::min;
using std::max;
using std::sort;
using std::swap;

typedef pair<int, int> P;

int n, m, id[10];
P edge[110];
std::set<P> s;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, x, y; i <= m; ++i)
    {
        scanf("%d%d", &x, &y);
        s.insert(P(x, y));
        s.insert(P(y, x));
    }
    for (int i = 1; i <= m; ++i)
        scanf("%d%d", &edge[i].first, &edge[i].second);
    for (int i = 1; i <= n; ++i)
        id[i] = i;
    bool flag = false;
    do
    {
        flag = true;
        for (int i = 1; i <= m; ++i)
        {
            if (!s.count(P(id[edge[i].first], id[edge[i].second])))
            {
                flag = false;
                break;
            }
        }
        if (flag)
            break;
    } while (std::next_permutation(id + 1, id + n + 1));
    puts(flag ? "Yes" : "No");
    return 0;
}