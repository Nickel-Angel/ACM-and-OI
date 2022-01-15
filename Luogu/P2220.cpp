#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>

using std::pair;

typedef long long ll;
typedef pair<int, int> P;

const int p = 1e9 + 7;

std::set<P> s;
std::map<int, ll> f;
int n, m, k;

inline int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = 1ll * res * a % p;
        a = 1ll * a * a % p;
        b >>= 1;
    }
    return res;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1, x, y; i <= k; ++i)
    {
        scanf("%d%d", &x, &y);
        s.insert(P(x, y));
    }
    for (auto it = s.begin(); it != s.end(); ++it)
        f[it -> first] += it -> second;
    int inv2 = power(2, p - 2);
    int sum = 1ll * n * (n + 1) % p * inv2 % p, ans = power(sum, m - f.size());
    for (auto [x, y] : f)
        ans = 1ll * ans * ((sum - y + p) % p) % p;
    printf("%d\n", ans);
    return 0;
}