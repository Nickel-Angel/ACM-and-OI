/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::vector;
using std::pair;
using std::string;
using std::cin;
using std::cout;

typedef pair<int, string> P;

int n, next[15][110][60];
string s[15];
std::map<vector<int>, P> LCS;

inline int to_int(char c)
{
    return c <= 'Z' ? c - 'A' : c - 'a' + 26;
}

inline char to_char(int x)
{
    return x < 26 ? x + 'A' : x + 'a' - 26;
}

P dfs(const vector<int> &v)
{
    if (LCS.count(v))
        return LCS[v];
    P res = {0, ""};
    bool flag;
    vector<int> cur;
    for (int i = 0; i < 52; ++i)
    {
        cur.clear(), flag = true;
        for (int j = 0; j < n; ++j)
        {
            if (next[j][v[j]][i] == -1)
                flag = false;
            else
                cur.push_back(next[j][v[j]][i]);
        }
        if (flag)
        {
            P state = dfs(cur);
            res = std::max(res, P(state.first + 1, to_char(i) + state.second));
        }
    }
    LCS[v] = res;
    return res;
}

inline void solve()
{
    LCS.clear();
    memset(next, -1, sizeof(next));
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
        s[i] = " " + s[i];
        for (int j = 0; j < s[i].length(); ++j)
        {
            for (int k = s[i].length() - 1; k > j; --k)
            {
                next[i][j][to_int(s[i][k])] = k;
            }
        }
    }
    P ans = dfs(vector<int>(n, 0));
    cout << ans.first << "\n" << ans.second << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}