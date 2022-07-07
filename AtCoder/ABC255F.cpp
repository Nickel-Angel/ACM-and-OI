/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 2e5 + 10;
int n, preorder[maxn], inorder[maxn], pos[maxn], ch[maxn][2];

int dfs(int pre_l, int pre_r, int in_l, int in_r)
{
    if (pre_l > pre_r)
        return 0;
    //printf("%d %d %d %d\n", pre_l, pre_r, in_l, in_r);
    int root = preorder[pre_l], x = pos[root];
    if (x < in_l || x > in_r)
    {
        puts("-1");
        exit(0);
    }
    ch[root][0] = dfs(pre_l + 1, pre_l + x - in_l, in_l, x - 1);
    ch[root][1] = dfs(pre_l + x - in_l + 1, pre_r, x + 1, in_r);
    return root;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", preorder + i);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", inorder + i);
        pos[inorder[i]] = i;
    }
    if (preorder[1] != 1)
    {
        puts("-1");
        return 0;
    }
    dfs(1, n, 1, n);
    for (int i = 1; i <= n; ++i)
        printf("%d %d\n", ch[i][0], ch[i][1]);
    return 0;
}