#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>

const int maxn = 5e5 + 10;
int a[maxn];

struct data
{
    int x1, x2;
    bool operator < (const data &rhs) const
    {
        return x2 < rhs.x2;
    }
}b[maxn];

bool cmp(data a, data b)
{
    return a.x1 > b.x1; 
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        b[i].x1 = i;
    b[2].x1 = b[3].x1;
    std::random_shuffle(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i)
        b[i].x2 = i;
    b[3].x2 = b[4].x2;
    std::random_shuffle(b + 1, b + n + 1);
    std::sort(b + 1, b + n + 1, cmp);
    for (int i = 1; i <= n; ++i)
    {
        printf("%d %d\n", b[i].x1, b[i].x2);
    }
    return 0;
}