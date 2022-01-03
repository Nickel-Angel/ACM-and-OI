/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <numeric>
#include <vector>

int n, k;
std::vector<int> ans;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 2, bound = n; i * i <= bound; ++i)
    {
        while (n % i == 0)
        {
            n /= i;
            ans.push_back(i);
        }
        if (n == 1)
            break;
    }
    if (n != 1)
        ans.push_back(n);
    int sum = std::accumulate(ans.begin(), ans.end(), 0);
    if (sum > k)
    {
        puts("-1");
        return 0;
    }
    printf("%d\n", ans.size() + k - sum);
    for (int i : ans)
        printf("%d ", i);
    for (int i = 0; i < k - sum; ++i)
        printf("1 ");
}