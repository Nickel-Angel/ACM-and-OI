/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

std::vector<int> ans;

int main()
{
    int a, b, t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &a, &b);
        int n = a + b;
        if ((a + b) & 1)
        {
            int x = abs(n / 2 - a);
            ans.push_back(x);
            for (int i = 1; i <= std::min(a, b); ++i)
            {
                x += 2;
                ans.push_back(x);
            }
            x = abs(n / 2 - b);
            ans.push_back(x);
            for (int i = 1; i <= std::min(a, b); ++i)
            {
                x += 2;
                ans.push_back(x);
            }
        }
        else
        {
            int x = abs(n / 2 - a);
            ans.push_back(x);
            for (int i = 1; i <= std::min(a, b); ++i)
            {
                x += 2;
                ans.push_back(x);
            }
        }
        std::sort(ans.begin(), ans.end());
        printf("%u\n", ans.size());
        for (unsigned i = 0; i < ans.size(); ++i)
            printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
        ans.clear();
    }
    return 0;
}