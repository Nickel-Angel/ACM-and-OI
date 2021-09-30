#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using std::sort;
using std::pair;

typedef pair<int, int> P;

const int maxc = 2e5 + 10;
const int maxm = 1e5 + 10;
const int p = 998224353;
int n, m;
int c[15], id[15][maxc], a[15][maxc];
int hash[maxm], base[15], cnt, help[15];
std::priority_queue<P> q;

inline void hash_init()
{
    cnt = 0, base[0] = 1;
    for (int i = 1; i < 15; ++i)
        base[i] = 1ll * base[i - 1] * 17 % p;
}

inline void hash_add()
{
    ++cnt;
    for (int i = 0; i < n; ++i)
        hash[cnt] = (hash[cnt] + 1ll * base[i] * help[i] % p) % p;
}

inline int hash_calc()
{
    int res = 0;
    for (int i = 0; i < n; ++i)
        res = (res + 1ll * base[i] * help[i] % p) % p;
    return res;
}

inline bool hash_find(int x)
{
    int pos = std::lower_bound(hash + 1, hash + cnt + 1, x) - hash;
    return pos > cnt ? false : hash[pos] == x;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", c + i);
        for (int j = 1; j <= c[i]; ++j)
        {
            scanf("%d", a[i] + j);
            id[i][j] = j;
        }
        sort(id[i] + 1, id[i] + c[i] + 1, [&](int x, int y){return a[i][x] > a[i][y];});
    }
    hash_init();
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0; j < n; ++j)
            scanf("%d", help + j);
        hash_add();
    }
    sort(hash + 1, hash + cnt + 1);
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        help[i] = id[i][1];
        
    }
    q.push(P(hash_calc()));
    return 0;
}