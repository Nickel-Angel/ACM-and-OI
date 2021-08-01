#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>

const int maxn = 1e8 + 10;
int L[110], R[110], T;
int prime[10000010], prime_counter = 0;
int double_prime[10000010], double_prime_counter = 0;
std::bitset<maxn> prime_tag;

inline void Euler(int bound)
{
    std::bitset<maxn> euler_tag;
    euler_tag.reset();
    euler_tag.set(1);
    for (int i = 2; i <= bound; ++i)
    {
        if (!euler_tag[i])
        {
            euler_tag.set(i, 1);
            prime_tag.set(i, 1);
            prime[++prime_counter] = i; 
        }
        for (int j = 1; j <= prime_counter; ++j)
        {
            if (i * prime[j] > bound) break;
            euler_tag.set(i * prime[j], 1);
            if (i % prime[j] == 0) break;
        }
    }
}

int main()
{
    int bound = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i)
    {
        scanf("%d%d", L + i, R + i);
        bound = std::max(bound, R[i]);
    }
    Euler(bound);
    for (int i = 1; i <= prime_counter; ++i)
    {
        int cur_prime = prime[i], cur_result = 0;
        while (cur_prime)
        {
            cur_result += cur_prime % 10;
            cur_prime /= 10;
        }
        if (prime_tag[cur_result])
            double_prime[++double_prime_counter] = prime[i];
    }
    for (int i = 0; i < T; ++i)
    {
        int start_counter = std::lower_bound(double_prime + 1, double_prime + double_prime_counter + 1, L[i]) - double_prime;
        int end_counter = std::upper_bound(double_prime + 1, double_prime + double_prime_counter + 1, R[i]) - double_prime;
        printf("%d\n", end_counter - start_counter);
    }
    return 0;
}