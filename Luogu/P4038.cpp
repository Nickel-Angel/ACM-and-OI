#include <algorithm>
#include <cstdio>
#include <cstring>

using std::max;

const double inf = 1e10;
int n, m, S;
double p, w[110], f[110][110], help[110][110];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j)
                f[i][j] = -inf;
    for (int i = 1; i <= n; ++i)
        scanf("%lf", w + i);
    scanf("%d%lf", &S, &p);
    for (int i = 0, u, v; i < m; ++i)
    {
        scanf("%d%d", &u, &v);
        f[u][v] = w[v] * p;
    }
    while (p > 1e-10)
    {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                help[i][j] = -inf;
        for (int k = 1; k <= n; ++k)
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    help[i][j] = max(help[i][j], f[i][k] + f[k][j] * p);
        memcpy(f, help, sizeof(f));
        p *= p;
    }
    double ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, f[S][i]);
    printf("%.1lf\n", ans + w[S]);
    return 0;
}