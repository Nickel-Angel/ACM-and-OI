/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <set>
#include <string>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::string;
using std::vector;
using std::pair;

typedef long long ll;

int n;
std::set<string> word;

int main()
{
    std::cin >> n;
    string s;
    int score = -1, ans = 0;
    for (int i = 1, t; i <= n; ++i)
    {
        std::cin >> s >> t;
        if (!word.count(s))
        {
            word.insert(s);
            if (t > score)
            {
                score = t;
                ans = i;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}