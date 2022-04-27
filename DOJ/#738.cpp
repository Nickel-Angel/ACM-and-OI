/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n;

int main()
{
    scanf("%d", &n);
    int cnt = 0;
    bool flag = true;
    for (int i = 1, x; i <= n; ++i)
    {
        scanf("%d", &x);
        flag &= (x == 1);
        if (x % 2 == 0)
            ++cnt;
    }
    puts(flag || (cnt & 1) ? "Bob" : "Alice");
    return 0;
}