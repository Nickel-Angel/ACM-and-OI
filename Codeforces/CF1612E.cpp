/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using std::vector;
using std::pair;

typedef pair<int, int> P;

const int maxn = 2e5 + 10;

int n;
vector<int> mes[maxn];
vector<P> ans, cur;

int main()
{
    scanf("%d", &n);
    int bound = 0, end = 0;
    for (int i = 1, m, k; i <= n; ++i)
    {
        scanf("%d%d", &m, &k);
        mes[m].push_back(k);
        bound = std::max(bound, m);
    }
    double res = 0;
    for (int t = 1, sum; t < 21; ++t)
    {
        cur.clear();
        for (int i = 1; i <= bound; ++i)
        {
            int key = 0;
            for (int k : mes[i])
                key += std::min(k, t);
            if (key)
                cur.push_back(P(key, i));
        }
        sort(cur.begin(), cur.end(), [&](P x, P y){return x.first > y.first;});
        sum = 0;
        for (int i = 0; i < std::min((int)cur.size(), t); ++i)
            sum += cur[i].first;
        if (1.0 * sum / t > res)
        {
            res = 1.0 * sum / t;
            ans = cur;
            end = t;
        }
    }
    printf("%d\n", end);
    for (int i = 0; i < end; ++i)
        printf("%d ", ans[i].second);
    return 0;
}