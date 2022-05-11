#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>

int n, m, a[2510][2510], f[2510], g[2510];

template<typename T>
inline void input(T &x)
{
    x = 0;
    char ch = getchar();
    bool f = false;
    while (!isdigit(ch))
    {
        f |= (ch == '-');
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = (x * 10) + (ch - '0');
        ch = getchar();
    }
    x = f ? -x : x;
}

int main()
{
    input(n), input(m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            input(a[i][j]);
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
            f[i] = std::max(f[i], a[j][i]);
    }
    for (int i = 1, fir, sec; i <= n; ++i)
    {
        fir = 0, sec = 0;
        for (int j = 1; j <= m; ++j)
        {
            if (fir < a[i][j])
            {
                sec = fir;
                fir = a[i][j];
            }
            else if (sec < a[i][j])
                sec = a[i][j];
        }
        g[i] = sec;
    }
    int f_min = 1e9;
    for (int i = 1; i <= m; ++i)
        f_min = std::min(f_min, f[i]);
    int g_max = 0;
    for (int i = 1; i <= n; ++i)
        g_max = std::max(g_max, g[i]);
    printf("%d\n", std::min(f_min, g_max));
    return 0;
}