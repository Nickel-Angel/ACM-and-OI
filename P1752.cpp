/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>

const int maxn = 5e4 + 10;
const int maxm = 2e5 + 10;
int n, m, p, q;
int del[maxn], price[maxn];

struct food_rev
{
    int del, price, id;
    bool operator < (const food_rev &rhs) const
    {
        return del > rhs.del;
    }
}dish[maxm];

struct food
{
    int del, price, id;
    
    food (int new_del, int new_price, int new_id)
    {
        del = new_del;
        price = new_price;
        id = new_id;
    }
    
    bool operator < (const food &rhs) const
    {
        return del < rhs.del;
    }
};

std::priority_queue<food_rev> poor;
std::multiset<food> picky;

bool cmp(food_rev a, food_rev b)
{
    return a.price < b.price;
}

inline bool check(int day)
{
    picky.clear();
    while (!poor.empty()) poor.pop();
    for (int i = 1; i <= m; ++i)
        picky.insert(food(dish[i].del, dish[i].price, dish[i].id));
    for (int i = 1, j = 1; i <= q; ++i)
    {
        while (j <= m && dish[j].price <= price[i])
        {
            poor.push(dish[j]);
            ++j;
        }
        for (int k = 1; k <= std::min(day, (int)poor.size()); ++k)
        {
            food_rev cur = poor.top();
            poor.pop();
            picky.erase(food(cur.del, cur.price, cur.id));
        }
    }
    for (int i = 1; i <= p; ++i)
    {
        for (int j = 1; j <= day; ++j)
        {
            std::multiset<food>::iterator cur = picky.lower_bound(food(del[i], 0, 0));
            if (cur != picky.end())
                picky.erase(cur);
            else break;
        }
    }
    return (int)picky.size() <= (n - p - q) * day;
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &p, &q);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &dish[i].del, &dish[i].price);
        dish[i].id = i;
    }
    for (int i = 1; i <= p; ++i)
        scanf("%d", del + i);
    for (int i = 1; i <= q; ++i)
        scanf("%d", price + i);
    std::sort(dish + 1, dish + m + 1, cmp);
    std::sort(del + 1, del + p + 1);
    std::sort(price + 1, price + q + 1);
    int s = 1, e;
    if (n - p - q > 0)
        e = (m + n - p - q - 1) / (n - p - q);
    else e = m + 1;
    while (s < e)
    {
        int mid = (s + e) >> 1;
        if (check(mid)) e = mid;
        else s = mid + 1;
    }
    if (n - p - q == 0 && e == m + 1)
    {
        puts("-1");
        return 0;
    }
    printf("%d\n", s);
    return 0;
}