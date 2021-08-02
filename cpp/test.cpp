#include <cmath>
#include <cstdio>

const int bound = 5e5 + 10;
int log_2[bound];

int main()
{
    printf("%lf\n", log2(5e5));
    log_2[0] = -1;
    for (int i = 1; i < bound; ++i)
        log_2[i] = log_2[i >> 1] + 1;
    log_2[0] = 0;
    printf("%d\n", log_2[bound - 10]);
}