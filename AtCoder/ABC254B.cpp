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

int n;
ll C[50][50];

int main()
{
    scanf("%d", &n);
    C[0][0] = 1;
    printf("%lld\n", C[0][0]);
    for (int i = 1; i < n; ++i)
    {
        C[i][0] = 1;
        printf("%lld ", C[i][0]);
        for (int j = 1; j <= i; ++j)
        {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            printf("%lld%c", C[i][j], " \n"[j == i]);
        }
    }
    return 0;
}