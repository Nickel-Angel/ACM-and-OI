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

const int maxn = 1e6 + 10;
int n, f[maxn];
bool vis[maxn];
vector<int> vec;

int main()
{
    n = 1000000;
    int cnt = 0;
    int pre = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!f[i])
        {
            f[i] = 1;
            for (int j : vec)
            {
                if (i + j > n)
                    break;
                f[i + j] = f[j] + 1;
            }
            vec.push_back(i);
            vis[i] = true;
            if (pre && !vis[i - pre])
            {
                vis[i - pre] = true;
                vec.push_back(i - pre);
                //printf("%d ", i - pre);
                ++cnt;
            }
            pre = i;
            ++cnt;
            //printf("%d ", i);
            continue;
        }
        if (f[i] < 3)
            vec.push_back(i);
    }
    //puts("");
    std::sort(vec.begin(), vec.end());
    vec.resize(300);
    memset(vis, 0, sizeof(vis));
    cnt = 100;
    pre = 0;
    for (int i : vec)
    {
        printf("%d ", i);
        vis[i] = true;
        f[i] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!f[i])
        {
            f[i] = 1;
            for (int j : vec)
            {
                if (i + j > n)
                    break;
                f[i + j] = f[j] + 1;
            }
            vec.push_back(i);
            vis[i] = true;
            if (pre && !vis[i - pre])
            {
                vis[i - pre] = true;
                vec.push_back(i - pre);
                printf("%d ", i - pre);
                ++cnt;
            }
            pre = i;
            ++cnt;
            printf("%d ", i);
            continue;
        }
        if (f[i] < 3)
            vec.push_back(i);
    }
    printf("%d\n", cnt);
    return 0;
}