#include <algorithm>
#include <cstdio>
#include <cstring>

int n, m, f[40][40];

int main()
{
    scanf("%d%d", &n, &m);
    f[0][0] = 1;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            f[i + 1][(j - 1 + n) % n] += f[i][j];
            f[i + 1][(j + 1) % n] += f[i][j];
        }
    }
    printf("%d\n", f[m][0]);
    return 0;
}