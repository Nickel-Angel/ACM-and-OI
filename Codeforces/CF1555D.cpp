#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 2e5 + 10;
int n, m, sum[6][maxn];
char s[maxn], alpha[4] = "abc";

int main()
{
    scanf("%d%d%s", &n, &m, s + 1);
    int cur = 0;
    do
    {
        for (int i = 1; i <= n; ++i)
            sum[cur][i] = sum[cur][i - 1] + (s[i] != alpha[i % 3]);
        ++cur;
    } while (std::next_permutation(alpha, alpha + 3));
    int l, r, ans;
    while (m--)
    {
        scanf("%d%d", &l, &r);
        ans = n;
        for (int i = 0; i < 6; ++i)
            ans = std::min(ans, sum[i][r] - sum[i][l - 1]);
        printf("%d\n", ans);
    }
    return 0;
}