/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <set>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;
using std::string;
using std::cin;
using std::cout;

typedef long long ll;

const int maxn = 1e5 + 10;
int n;
string s[maxn];
std::set<string> S, T;

inline void solve()
{
    cin >> n;
    S.clear(), T.clear();
    bool flag = false;
    string t;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[i];
        if (flag)
            continue;
        S.insert(s[i]);
        if (s[i].size() == 1)
        {
            cout << "YES\n";
            flag = true;
            continue;
        }
        if (s[i].size() == 2)
        {
            if (s[i][0] == s[i][1])
            {
                cout << "YES\n";
                flag = true;
                continue;
            }
            else
            {
                std::reverse(s[i].begin(), s[i].end());
                if (S.count(s[i]) || T.count(s[i]))
                {
                    cout << "YES\n";
                    flag = true;
                    continue;
                }
                
            }
        }
        if (s[i].size() == 3)
        {
            if (s[i][0] == s[i][2])
            {
                cout << "YES\n";
                flag = true;
                continue;
            }
            t = s[i][2];
            t += s[i][1];
            if (S.count(t))
            {
                cout << "YES\n";
                flag = true;
                continue;
            }
            t = s[i][0];
            t += s[i][1];
            T.insert(t);
            std::reverse(s[i].begin(), s[i].end());
            if (S.count(s[i]))
            {
                cout << "YES\n";
                flag = true;
                continue;
            }
        }
    }
    if (!flag)
        cout << "NO\n";
}

int main()
{
    int t;
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--)
        solve();
    return 0;
}