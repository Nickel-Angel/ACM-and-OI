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

int T, k;
long double p[1010], e[1010];

class Matrix
{
  public:
    long double v[2][2];

    Matrix()
    {
        v[0][0] = 0, v[1][0] = 0, v[0][1] = 0, v[1][1] = 0;
    }

    Matrix operator * (const Matrix &rhs) const
    {
        Matrix res;
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 2; ++j)
            {
                for (int k = 0; k < 2; ++k)
                {
                    res.v[i][j] += v[i][k] * rhs.v[k][j];
                }
            }
        }
        return res;
    }
};

inline Matrix bit_power(Matrix A, int x)
{
    while (x--)
        A = A * A;
    return A;
}

inline bool check(Matrix A, double x)
{
    return (int)(A.v[0][0] * x + A.v[0][1]) == (int)x;
}

inline double next(double x, int &b)
{
    Matrix A, res, power;
    A.v[0][0] = p[(int)x], A.v[0][1] = e[(int)x + 1];
    A.v[1][0] = 0, A.v[1][1] = 1;
    res.v[0][0] = 1, res.v[1][1] = 1;
    int bit = 0;
    while ((1ll << bit) <= b)
        ++bit;
    --bit;
    for (int i = bit; i >= 0; --i)
    {
        if (b < (1 << i))
            continue;
        power = bit_power(A, i);
        if (check(res * power, x))
        {
            res = res * power;
            b -= (1 << i);
        }
    }
    return res.v[0][0] * x + res.v[0][1];
}

int main()
{
    scanf("%d%d", &T, &k);
    --T;
    double bit = 1;
    p[0] = 1;
    for (int i = 0; i < T; ++i)
    {
        p[i + 1] = (T - i) * p[i] / (i + 1);
        bit *= 2;
    }
    p[T] /= bit, e[T] = p[T] * T;  
    for (int i = T - 1; i >= 0; --i)
    {
        p[i] /= bit;
        e[i] = e[i + 1] + p[i] * i;
    }
    for (int i = 1; i <= T; ++i)
        p[i] += p[i - 1];
    int last = k - 1;
    long double x = e[0];
    for (int i = 1; i <= min(last, 1000000); ++i)
        x = p[(int)x] * x + e[(int)x + 1];
    last -= min(last, 1000000);
    while (last)
    {
        x = next(x, last);
        if (last <= 0)
            break;
        --last;
        x = p[(int)x] * x + e[(int)x + 1];
    }
    printf("%.10Lf", x + 1);
    return 0;
}