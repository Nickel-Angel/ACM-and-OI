/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

typedef long long ll;

using std::vector;

vector<int> A, B, C;

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

ll a, b, p, q;
int help[10], cnt[10], change[10];

int main()
{
    scanf("%lld%lld", &a, &b);
    ll tmp, d = gcd(a, b);
    p = a / d, q = b / d;
    tmp = a;
    while (tmp)
    {
        A.push_back(tmp % 10);
        tmp /= 10;
    }
    std::reverse(A.begin(), A.end());
    tmp = b;
    while (tmp)
    {
        ++cnt[tmp % 10];
        B.push_back(tmp % 10);
        tmp /= 10;
    }
    bool flag = false;
    int n = A.size();
    ll x, ans_a = a, ans_b = b;
    for (int S = 1; S < (1 << n); ++S)
    {
        x = 0;
        for (int i = 0; i < 10; ++i)
            change[i] = 0, help[i] = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((S >> i) & 1)
                x = x * 10 + A[i];
            else
                ++change[A[i]];
        }
        if (x == 0 || x % p != 0 || ans_a <= x)
            continue;
        tmp = x / p * q;
        C.clear();
        while (tmp)
        {
            C.push_back(tmp % 10);
            tmp /= 10;
        }
        unsigned i = 0, j = 0;
        while (i < B.size() && j < C.size())
        {
            if (B[i] == C[j])
                ++i, ++j;
            else
            {
                ++help[B[i]];
                ++i;
            }
        }
        if (j < C.size())
            continue;
        while (i < B.size())
        {
            if (B[i])
                ++help[B[i]];
            ++i;
        }
        flag = (cnt[0] >= change[0] && change[0] >= help[0]);
        if (!flag)
            continue;
        for (int i = 1; i < 10; ++i)
            flag &= (change[i] == help[i]);
        if (flag)
        {
            ans_a = x;
            ans_b = x / p * q;
        }
    }
    printf("%lld %lld\n", ans_a, ans_b);
    return 0;
}