#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;

char key[60], s[60];
int id[26];

inline void solve()
{
    scanf("%s%s", key, s);
    for (int i = 0; i < 26; ++i)
        id[key[i] - 'a'] = i;
    int ans = 0, n = strlen(s);
    for (int i = 1; i < n; ++i)
        ans += abs(id[s[i] - 'a'] - id[s[i - 1] - 'a']);
    printf("%d\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}