/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

std::vector<int> A, B;
int n, a, b;

inline void solve()
{
    A.clear(), B.clear();
    scanf("%d", &n);
    int cnt = 0;
    while (n)
    {
        ++cnt;
        if (cnt & 1)
            A.push_back(n % 10);
        else
            B.push_back(n % 10);
        n /= 10;
    }
    a = 0, b = 0;
    std::reverse(A.begin(), A.end());
    std::reverse(B.begin(), B.end());
    for (int e : A)
        a = a * 10 + e;
    for (int e : B)
        b = b * 10 + e;
    printf("%d\n", (a + 1) * (b + 1) - 2);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}