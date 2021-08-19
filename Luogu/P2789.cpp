#include <cstdio>

int n, ans = 0;
bool vis[1010];

void dfs(int par, int cnt)
{
    if (par == 0)
    {
        if (!vis[cnt])
        {
            ++ans;
            vis[cnt] = true;
        }
        return;
    }
    for (int i = par; i > 0; --i)
        dfs(par - i, i * (par - i) + cnt);
}

int main()
{
    scanf("%d", &n);
    dfs(n, 0);
    printf("%d\n", ans);
    return 0;
}