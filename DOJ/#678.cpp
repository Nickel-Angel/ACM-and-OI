/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <set>

using std::string;
using std::set;

char s[50];
int n;
bool flag;
set<string> S;

inline bool check(string a, string b)
{
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    for (unsigned i = 0; i < std::min(a.size(), b.size()); ++i)
    {
        if (a[i] != b[i])
            return false;
    }
    string com = a.size() < b.size() ? b.substr(a.size()) : a.substr(b.size());
    std::reverse(com.begin(), com.end());
    return S.count(com);
}

void dfs(int l, int r, string &a, string &b)
{
    if (flag)
        return;
    if (l > r)
    {
        if (r == n / 2)
        {
            for (unsigned i = 0; i < std::min(a.size(), b.size()); ++i)
            {
                if (a[i] != b[i])
                    return;
            }
            if (a.size() > b.size())
                S.insert(a.substr(b.size()));
            else
                S.insert(b.substr(a.size()));
        }
        else
            flag |= check(a, b);
        return;
    }
    a.push_back(s[l]);
    dfs(l + 1, r, a, b);
    a.pop_back();
    b.push_back(s[l]);
    dfs(l + 1, r, a, b);
    b.pop_back();
}

inline void solve()
{
    flag = false;
    scanf("%s", s + 1);
    n = strlen(s + 1);
    string a = "", b = ""; 
    dfs(1, n / 2, a, b);
    dfs(n / 2 + 1, n, a, b);
    puts(flag ? "possible" : "impossible");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}