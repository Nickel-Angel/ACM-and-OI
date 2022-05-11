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

char s[20], t[] = "Hello,World!";

int main()
{
    scanf("%s", s);
    int len = strlen(s);
    if (len != 12)
    {
        puts("WA");
        return 0;
    }
    for (int i = 0; i < len; ++i)
    {
        if (s[i] != t[i])
        {
            puts("WA");
            return 0;
        }
    }
    puts("AC");
    return 0;
}