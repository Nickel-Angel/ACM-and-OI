#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;

std::vector<int> ans;

int n;
char s[1010];

inline void solve()
{
    ans.clear();
    scanf("%d%s", &n, s + 1);
    int one = 0, zero = 0;
    for (int i = 1; i <= n; ++i)
    {
        one += (s[i] == '1');
        zero += (s[i] == '0');
    }
    for (int i = 1; i <= zero; ++i)
    {
        if (s[i] == '1')
            ans.push_back(i);
    }
    for (int i = one - 1; i >= 0; --i)
    {
        if (s[n - i] == '0')
            ans.push_back(n - i);
    }
    if (ans.empty())
    {
        puts("0");
        return;
    }
    puts("1");
    printf("%zu ", ans.size());
    for (unsigned i = 0; i < ans.size(); ++i)
        printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}