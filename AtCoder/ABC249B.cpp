/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

char s[110];
std::map<char, int> cnt;

int main()
{
    bool num = true, flag1 = false, flag2 = false;
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; ++i)
    {
        if (isupper(s[i]))
            flag1 = true;
        if (islower(s[i]))
            flag2 = true;
        ++cnt[s[i]];
        num &= cnt[s[i]] < 2;
    }
    puts(num && flag1 && flag2 ? "Yes" : "No");
    return 0;
}