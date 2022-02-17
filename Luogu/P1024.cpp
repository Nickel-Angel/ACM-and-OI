/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

double a, b, c, d;

inline double f(double x)
{
    return a * x * x * x + b * x * x + c * x + d;
}

inline double find(double l, double r)
{
    if (fabs(f(l)) < 1e-6 || fabs(f(r)) < 1e-6)
        return l;
    double mid = (l + r) / 2;
    while (r - l > 1e-6)
    {
        mid = (l + r) / 2;
        if (fabs(f(mid)) < 1e-4)
            break;
        if (f(l) * f(mid) < 0)
            r = mid;
        else
            l = mid;
    }
    return mid;
}

int main()
{
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    double k1 = (-b - sqrt(b * b - 3 * a * c)) / (3 * a);
    double k2 = (-b + sqrt(b * b - 3 * a * c)) / (3 * a);
    printf("%.2lf %.2lf %.2lf\n", find(-100, k1), find(k1, k2), find(k2, 100));
    return 0;
}