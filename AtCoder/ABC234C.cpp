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

ll n;
vector<int> v;

int main()
{
    scanf("%lld", &n); 
    while (n)
    {
        v.push_back(n & 1 ? 2 : 0);
        n >>= 1;
    }
    if (v.empty())
        v.push_back(0);
    std::reverse(v.begin(), v.end());
    for (int i : v)
        printf("%d", i);
    return 0;
}