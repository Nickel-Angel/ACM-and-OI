/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>

typedef long long ll;

using std::max;
using std::min;
using std::set;

const int p = 998244353;
const int inv2 = 499122177;

inline ll calc(ll l, ll r)
{
    l %= p, r %= p;
    return (l + r) % p * (r - l + 1 + p) % p * inv2 % p;
}

class ODT
{
  private:
    struct node
    {
        ll l, r;
        mutable ll val;

        node() {}

        node(ll l, ll r, ll val) : l(l), r(r), val(val) {}

        inline bool operator < (const node &rhs) const 
        { 
            return l < rhs.l;
        }
    };

    ll bound;
    set<node> S;

    inline auto split(ll x)
    {
        if (x > bound)
            return S.end();
        auto it = --S.upper_bound(node(x, 0, 0));
        if (it->l == x)
            return it;
        ll l = it->l, r = it->r, val = it->val;
        S.erase(it);
        S.insert(node(l, x - 1, val));
        return S.insert(node(x, r, val)).first;
    }

  public:
    inline void init(ll n)
    {
        S.clear();
        S.insert(node(1, n, 0));
        bound = n;
    }

    inline ll harvest(ll l, ll r, ll date)
    {
        auto it_r = split(r + 1), it_l = split(l);
        ll res = 0, cur_l, cur_r, pre;
        for (auto it = it_l; it != it_r; ++it)
        {
            cur_l = it->l, cur_r = it->r, pre = it->val;
            res = (res + (date - pre) % p * calc(cur_l, cur_r) % p) % p;
        }
        S.erase(it_l, it_r);
        S.insert(node(l, r, date));
        return res;
    }
}tree;

ll n;
int q;

int main()
{
    scanf("%lld%d", &n, &q);
    tree.init(n);
    ll d, l, r;
    while (q--)
    {
        scanf("%lld%lld%lld", &d, &l, &r);
        printf("%lld\n", tree.harvest(l, r, d));
    }
    return 0;
}