#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int maxn = 2e4 + 10;
int n;
std::vector<int> v[2];

inline int middle(int x, int y, int z)
{
    if (x == y || y == z || x == z)
        return 0;
    printf("1 %d %d %d\n", x, y, z);
    fflush(stdout);
    static int res;
    scanf("%d", &res);
    return res;
}

inline int most(int x, int y)
{
    printf("2 %d %d\n", x, y);
    fflush(stdout);
    static int res;
    scanf("%d", &res);
    return res;
}

int main()
{
    scanf("%d", &n);
    int key[2], mid = middle(1, 2, 3);
    if (mid == 1)
        key[0] = 2, key[1] = 3;
    else if (mid == 2)
        key[0] = 1, key[1] = 3;
    else
        key[0] = 1, key[1] = 2;
    v[0].push_back(key[0]), v[1].push_back(key[1]);
    for (int i = 4; i <= n; ++i)
    {
        if (middle(key[0], mid, i) == mid)
            v[1].push_back(i);
        else
            v[0].push_back(i);
    }
    std::sort(v[0].begin(), v[0].end(), [&](int x, int y){return middle(x, y, mid) == y;});
    std::sort(v[1].begin(), v[1].end(), [&](int x, int y){return middle(x, y, mid) == y;});
    if (middle(v[0].front(), v[0].back(), mid) == v[0].front())
        std::reverse(v[0].begin(), v[0].end());
    if (middle(v[1].front(), v[1].back(), mid) == v[1].front())
        std::reverse(v[1].begin(), v[1].end());
    if (most(v[0][0], v[1][0]) == v[0][0])
    {
        std::reverse(v[1].begin(), v[1].end());
        printf("3 ");
        for (int i : v[0])
            printf("%d ", i);
        printf("%d ", mid);
        for (int i : v[1])
            printf("%d ", i);
    }
    else
    {
        std::reverse(v[0].begin(), v[0].end());
        printf("3 ");
        for (int i : v[1])
            printf("%d ", i);
        printf("%d ", mid);
        for (int i : v[0])
            printf("%d ", i);
    }
    return 0;
}