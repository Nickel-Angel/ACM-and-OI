#include <algorithm>
#include <cstring>
#include <cstdio>

typedef long long ll;

int a[10010], b[10010], n, m, w[10], p;

inline int power(int a, int b, int p)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = 1ll * res * a % p;
        a = 1ll * a * a % p;
        b >>= 1;
    }
    return res;
}

inline int mul(int a, int b, int p)
{
    int res = 0;
    while (b)
    {
        if (b & 1) res = ((ll)res + a) % p;
        a = ((ll)a + a) % p;
        b >>= 1;
    }
    return res;
}

int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

inline int inv(int a, int p)
{
    int x, y;
    exgcd(a, p, x, y);
    return (x % p + p) % p;
}

inline int CRT(int *a, int *b, int n)
{
    int A = 1, res = 0;
    for (int i = 1; i <= n; ++i)
    {
        A *= a[i];
        b[i] = (b[i] % a[i] + a[i]) % a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        int m = A / a[i];
        res = (res + mul(mul(inv(m, a[i]), m, A), b[i], A)) % A;
    }
    return res;
}

inline int f(int n, int p, int P)
{
    if (n == 0) return 1;
    int loop = 1, rem = 1;
    for (int i = 1; i <= P; ++i)
    {
        if (i % p == 0) continue;
        loop = 1ll * loop * i % P;
    }
    loop = power(loop, n / P, P);
    for (int i = P * (n / P); i <= n; ++i)
    {
        if (i % p == 0) continue;
        rem = 1ll * rem * i % P;
    }
    return 1ll * f(n / p, p, P) * rem % P * loop % P;
}

inline int g(int n, int p)
{
    if (n < p) return 0;
    return g(n / p, p) + (n / p);
}

inline int combine(int n, int m, int p, int P)
{
    int fac = 1ll * f(n, p, P) * inv(f(m, p, P), P) % P * inv(f(n - m, p, P), P) % P;
    return 1ll * fac * power(p, g(n, p) - g(m, p) - g(n - m, p), P) % P;
}

inline int exlucas(int n, int m, int p)
{
    int tmp = p, cnt = 0;
    for (int i = 2; i * i <= p; ++i)
    {
        if (tmp % i != 0) continue;
        int P = 1;
        while (tmp % i == 0)
        {
            P *= i;
            tmp /= i;
        }
        a[++cnt] = P;
        b[cnt] = combine(n, m, i, P);
    }
    if (tmp > 1)
    {
        a[++cnt] = tmp;
        b[cnt] = combine(n, m, tmp, tmp);
    }
    return CRT(a, b, cnt);
}

int main()
{
    scanf("%d%d%d", &p, &n, &m);
    int sum_w = 0;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", w + i);
        sum_w += w[i];
    }
    if (sum_w > n)
    {
        puts("Impossible");
        return 0;
    }
    int res = 1;
    for (int i = 1; i <= m; ++i)
    {
        res = 1ll * res * exlucas(n, w[i], p) % p;
        n -= w[i];
    }
    printf("%d\n", res);
    return 0;
}