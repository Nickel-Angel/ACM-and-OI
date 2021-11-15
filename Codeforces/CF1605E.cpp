#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

typedef long long ll;

const int maxn = 2e5 + 10;

int n, q, c[maxn], k[maxn], b[maxn];
ll pre_b[maxn], suf_b[maxn], pre_k[maxn], suf_k[maxn];

std::vector<int> pos;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", c + i);
    scanf("%*d");
    for (int i = 2, x; i <= n; ++i)
    {
        scanf("%d", &x);
        c[i] -= x;
        b[i] = -c[i];
    }
    ll sum = 0;
    scanf("%d", &q);
    k[1] = 1, b[1] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i * 2; j <= n; j += i)
        {
            k[j] -= k[i];
            b[j] -= b[i];
        }
        if (k[i] < 0)
        {
            k[i] = -k[i];
            b[i] = -b[i];
        }
        if (k[i])
            pos.push_back(i);
        else
            sum += abs(b[i]);
    }
    std::sort(pos.begin(), pos.end(), [&](int x, int y){return b[x] / k[x] < b[y] / k[y];});
    pre_b[0] = b[pos[0]], pre_k[0] = k[pos[0]];
    for (int i = 1; i < (int)pos.size(); ++i)
    {
        pre_k[i] = pre_k[i - 1] + k[pos[i]];
        pre_b[i] = pre_b[i - 1] + b[pos[i]];
    }
    for (int i = (int)pos.size() - 1; i >= 0; --i)
    {
        suf_k[i] = suf_k[i + 1] + k[pos[i]];
        suf_b[i] = suf_b[i + 1] + b[pos[i]];
    }
    int x, bound = 0, key;
    ll ans;
    while ((1 << bound) <= pos.size())
        ++bound;
    --bound;
    while (q--)
    {
        scanf("%d", &x);
        x = c[1] - x;
        ans = sum, key = -1;
        for (int i = bound; i >= 0; --i)
        {
            key += (1 << i);
            if (key > pos.size() - 1 || b[pos[key]] / k[pos[key]] > x)
                key -= (1 << i);
        }
        if (key != -1)
            ans += pre_k[key] * x - pre_b[key] - suf_k[key + 1] * x + suf_b[key + 1];
        else
            ans += -suf_k[0] * x + suf_b[0];
        printf("%lld\n", ans);
    }
    return 0;
}