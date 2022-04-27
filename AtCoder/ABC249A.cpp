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

int a, b, c, d, e, f, x;

int main()
{
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &x);
    int T = 0, A = 0;
    for (int i = 0; i < x; ++i)
    {
        if (i % (a + c) < a)
            T += b;
        if (i % (d + f) < d)
            A += e;
    }
    puts(T > A ? "Takahashi" : (T == A ? "Draw" : "Aoki"));
    return 0;
}