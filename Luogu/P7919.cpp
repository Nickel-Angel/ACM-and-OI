/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using std::pair;

typedef pair<int, int> P;

int n;
char s[5010];

std::vector<P> ans;

int main()
{
    scanf("%d%s", &n, s + 1);
    int l = 1, r = n;
    while (l < r)
    {
        while (l < r && s[l] != s[l + 1])
            ++l;
        while (l < r && s[r] != s[r - 1])
            --r;
        if (l == r)
            break;
        ++l, --r;
        ans.push_back(P(l, r));
    }
    printf("%zu\n", ans.size());
    if (ans.empty())
        return 0;
    if (ans.back().first > ans.back().second)
        ans.back().second = n;
    for (P i : ans)
        printf("%d %d CAB\n", i.first, i.second);
    return 0;
}