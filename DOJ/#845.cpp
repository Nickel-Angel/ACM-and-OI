/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e6 + 10;
int n, a[maxn];

int main()
{
    scanf("%d", &n);
    int mi = 1e9;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        mi = std::min(mi, a[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        cnt += (a[i] == mi);
    puts(cnt <= n / 2 ? "Alice" : "Bob");
    return 0;
}