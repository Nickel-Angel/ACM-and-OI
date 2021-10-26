/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;

const int maxn = 1e5 + 10;
int n;
char s[maxn];
vector<char> t;

inline bool pard(const vector<char> &s)
{
    for (unsigned i = 0; i < s.size() / 2; ++i)
    {
        if (s[i] != s[s.size() - 1 - i])
            return false;
    }
    return true;
}

inline void solve()
{
    scanf("%d%s", &n, s + 1);
    int ans = 0x7f7f7f7f, res;
    for (char cur = 'a'; cur <= 'z'; ++cur)
    {
        res = 0;
        t.clear();
        for (int i = 1; i <= n; ++i)
        {
            if (s[i] != cur)
                t.push_back(s[i]);
        }
        if (pard(t))
        {
            int curl = 0, curr = 0, i = 1, j = n;
            while (i <= j)
            {
                if (curl == curr)
                {
                    curl += (s[i] != cur);
                    curr += (s[j] != cur);
                    res += ((s[i] == cur) ^ (s[j] == cur));
                    ++i, --j;
                }
                else
                {
                    while (curl < curr && i <= j)
                    {
                        res += (s[i] == cur);
                        curl += (s[i] != cur);
                        ++i;
                    }
                    while (curr < curl && i <= j)
                    {
                        res += (s[j] == cur);
                        curr += (s[j] != cur);
                        --j;
                    }
                }
                
            }
            ans = min(ans, res);
        }
    }
    printf("%d\n", ans == 0x7f7f7f7f ? -1 : ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}