#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>

long long n;

inline void print(long long x, char c) {
	printf("%lld%lld%c", x / 10 % 10, x % 10, c);
}

int main() {
	scanf("%lld", &n);
	n %= 24ll * 3600000;
	print(n / 3600000, ':');
	n %= 3600000;
	print(n / 60000, ':');
	n %= 60000;
	print(n / 1000, '\n');
	return 0;
}