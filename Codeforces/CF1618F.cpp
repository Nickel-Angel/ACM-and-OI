/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <string>

using std::set;
using std::string;

long long x, y;
string tar, ori;
set<string> cur;

void dfs(string s)
{
    if (cur.count(s) || s.length() > 100)
        return;
    if (s == tar)
    {
        puts("YES");
        exit(0);
    }
    cur.insert(s);
    auto it = s.rbegin();
    while (it != s.rend() && *it == '0')
        ++it;
    string t;
    while (it != s.rend())
    {
        t += *it;
        ++it;
    }
    dfs(t);
    std::reverse(s.begin(), s.end());
    dfs("1" + s);
}

int main()
{
    scanf("%lld%lld", &x, &y);
    while (y)
    {
        tar += '0' + (y & 1);
        y >>= 1;
    }
    std::reverse(tar.begin(), tar.end());
    while (x)
    {
        ori += '0' + (x & 1);
        x >>= 1;
    }
    std::reverse(ori.begin(), ori.end());
    dfs(ori);
    puts("NO");
    return 0;
}