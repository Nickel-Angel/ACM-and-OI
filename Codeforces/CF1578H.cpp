/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
 
const int maxn = 1e4 + 10;
char s[maxn];
int right[maxn], bucket[maxn], cnt = 0;
int L, R, len;
 
inline int split(int l, int r)
{
    for (L = l, R = r; L < R; ++L, --R)
    {
        if (right[L] != R)
            return right[L] + 1;
    }
    return 0;
}
 
int dfs(int l, int r)
{
    int pos = split(l, r);
    int cur_l = L, cur_r = R;
    return pos ? std::max(dfs(cur_l, pos - 1) + 1, dfs(pos + 2, cur_r)) : 0;  
}
 
int main()
{
    scanf("%s", s + 1);
    len = strlen(s + 1);
    int key = 0;
    if (s[len] == '\0')
        --len;
    for (int i = 1; i <= len; ++i)
    {
        if (s[i] == '(')
            bucket[++cnt] = i;
        if (s[i] == ')')
        {
            right[bucket[cnt]] = i;   
            --cnt;
        }
    }
    printf("%d\n", dfs(1, len));
    return 0;
}