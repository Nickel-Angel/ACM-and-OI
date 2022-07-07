/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

const int maxn = 2e5 + 10;
int n, k, a[maxn];
vector<int> vec;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    for (int i = 0; i < k; ++i)
    {
        vec.clear();
        for (int j = i; j < n; j += k)
            vec.push_back(a[j]);
        sort(vec.begin(), vec.end());
        for (int j = i; j < n; j += k)
            a[j] = vec[j / k];
    }
    for (int i = 1; i < n; ++i)
    {
        if (a[i - 1] > a[i])
        {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}