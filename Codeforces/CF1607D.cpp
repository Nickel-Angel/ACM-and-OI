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

const int maxn = 2e5 + 10;
int n, a[maxn];
char s[maxn];
bool cover[maxn];
vector<int> R, B;

inline void solve()
{
    R.clear(), B.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; ++i)
    {
        cover[i] = false;
        if (s[i] == 'R')
            R.push_back(i);
        else
            B.push_back(i);
    }
    sort(R.begin(), R.end(), [&](int x, int y){return a[x] < a[y];});
    sort(B.begin(), B.end(), [&](int x, int y){return a[x] < a[y];});
    for (int i = 1, j = 0; i <= n; ++i)
    {
        while (j != B.size() && a[B[j]] < i)
            ++j;
        if (j == B.size())
            break;
        if (cover[i])
            continue;
        cover[i] = true;
        ++j;
    }
    for (int i = n, j = R.size() - 1; i > 0; --i)
    {
        while (j >= 0 && a[R[j]] > i)
            --j;
        if (j < 0)
            break;
        if (cover[i])
            continue;
        cover[i] = true;
        --j;
    }
    bool flag = true;
    for (int i = 1; i <= n; ++i)
        flag &= cover[i];
    puts(flag ? "YES" : "NO");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}