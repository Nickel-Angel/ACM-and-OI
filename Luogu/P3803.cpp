/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

const double pi = acos(-1);

class complex
{
  public:
    double real, img;

    complex() {}

    complex(double real, double img) : real(real), img(img) {}
    
    complex operator + (const complex &rhs)
    {
        return complex(real + rhs.real, img + rhs.img);
    }

    complex operator - (const complex &rhs)
    {
        return complex(real - rhs.real, img - rhs.img);
    }

    complex operator * (const complex &rhs)
    {
        return complex(real * rhs.real - img * rhs.img, img * rhs.real + real * rhs.img);
    }
};

const int maxn = 5e6 + 10;
int n, m, pos[maxn];
complex a[maxn], b[maxn];

inline void fft(complex *a, int n, int inv)
{
    for (int i = 0; i < n; ++i)
    {
        if (pos[i] < i)
            std::swap(a[pos[i]], a[i]);
    }
    for (int i = 1; i < n; i <<= 1)
    {
        complex next(cos(pi / i), inv * sin(pi / i));
        for (int j = 0; j < n; j += (i << 1))
        {
            complex w(1, 0);
            for (int k = 0; k < i; ++k, w = w * next)
            {
                complex x = a[j + k], y = a[i + j + k];
                a[j + k] = x + w * y;
                a[i + j + k] = x - w * y;
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; ++i)
        scanf("%lf", &a[i].real);
    for (int i = 0; i <= m; ++i)
        scanf("%lf", &b[i].real);
    int bound = 1, len = 0;
    while (bound <= n + m)
        bound <<= 1, ++len;
    for (int i = 0; i < bound; ++i)
        pos[i] = (pos[i >> 1] >> 1) | ((i & 1) << (len - 1));
    fft(a, bound, 1);
    fft(b, bound, 1);
    for (int i = 0; i < bound; ++i)
        a[i] = a[i] * b[i];
    fft(a, bound, -1);
    for (int i = 0; i <= n + m; ++i)
        printf("%d ", (int)(a[i].real / bound + 0.5));
    return 0;
}