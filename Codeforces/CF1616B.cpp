#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 10;
int n;
char s[maxn];

inline void solve()
{
    scanf("%d%s", &n, s + 1);
    if (s[1] == s[2])
    {
        printf("%c%c\n", s[1], s[2]);
        return;
    }
    int pos = n;
    for (int i = 1; i < n; ++i)
    {
        if (s[i] < s[i + 1])
        {
            pos = i;
            break;
        }
    }
    for (int i = 1; i <= pos; ++i)
        putchar(s[i]);
    for (int i = pos; i > 0; --i)
        putchar(s[i]);
    puts("");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}