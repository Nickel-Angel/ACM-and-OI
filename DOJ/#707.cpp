/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e6 + 10;
char s[maxn];
int pos[maxn], stk[maxn], top;
long long f[maxn];

int main()
{
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; ++i)
    {
        if (s[i] == '(')
            stk[++top] = i;
        else
        {
            if (top)
            {
                pos[i] = stk[top];
                f[i] = f[pos[i] - 1] + 1;
                --top;
            }
        }    
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += f[i];
    printf("%lld\n", ans);
    return 0;
}