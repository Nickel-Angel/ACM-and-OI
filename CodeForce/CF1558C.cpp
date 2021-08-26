/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

int a[3010];
std::vector<int> ans;

inline int find_pos(int x, int n)
{
    int pos = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == x)
        {
            pos = i;
            break;
        }
    }
    return pos;
}

int main()
{
    int t, n;
    bool flag;
    scanf("%d", &t);
    while (t--)
    {
        ans.clear();
        flag = false;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", a + i);
            if (a[i] % 2 != i % 2)
                flag = true;
        }
        if (flag)
        {
            puts("-1");
            continue;
        }
        for (int i = n, x, y; i > 1; i -= 2)
        {
            if (a[i] == i && a[i - 1] == i - 1)
                continue;
            x = find_pos(i, i);
            std::reverse(a + 1, a + x + 1), ans.push_back(x);
            y = find_pos(i - 1, i);
            std::reverse(a + 1, a + y), ans.push_back(y - 1);
            std::reverse(a + 1, a + y + 2), ans.push_back(y + 1);
            std::reverse(a + 1, a + 4), ans.push_back(3);
            std::reverse(a + 1, a + i + 1), ans.push_back(i);
        }
        printf("%u\n", ans.size());
        for (unsigned i = 0; i < ans.size(); ++i)
            printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
    }
    return 0;
}