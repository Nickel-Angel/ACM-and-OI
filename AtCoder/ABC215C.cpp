/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
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
using std::set;

typedef long long ll;

int n, id[10];
string s, t;
set<string> S;

int main()
{
    std::cin >> s >> n;
    for (int i = 0; i < s.size(); ++i)
    {
        id[i] = i;
        t.push_back(' ');
    }
    do
    {
        for (int i = 0; i < s.size(); ++i)
            t[i] = s[id[i]];
        S.insert(t);
    } while (std::next_permutation(id, id + s.size()));
    int cnt = 0;
    for (string c : S)
    {
        ++cnt;
        if (cnt == n)
        {
            std::cout << c << "\n";
            break;
        }
    }
    return 0;
}