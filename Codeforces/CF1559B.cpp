/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

char s[110];

int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%s", &n, s);
        int pos = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] != '?')
            {
                pos = i;
                break;
            }  
        }
        int state = 0;
        if (s[pos] == 'B') 
            state = 1;
        for (int i = pos - 1; i >= 0; --i)
        {
            if (state)
                s[i] = 'R';
            else
                s[i] = 'B';
            state ^= 1;
        }
        for (int i = pos; i < n; ++i)
        {
            if (s[i] != '?')
            {
                state = (s[i] == 'R' ? 0 : 1);
                continue;
            }
            if (state)
                s[i] = 'R';
            else
                s[i] = 'B';
            state ^= 1;
        }
        puts(s);
    }
    return 0;
}