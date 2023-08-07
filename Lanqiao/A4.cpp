#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

using std::map;

long long n = 2021041820210418;

long long calc(long long x) {
	long long res = 0;
	for (long long i = 1; 1ll * i * i <= x; ++i) {
		if (x % i == 0)
			res += i * i == x ? 1 : 2;
	}
	return res;
}

int main() {
	long long ans = 0;
	for (int i = 2; 1ll * i * i <= n; ++i) {
		if (n % i == 0) {
			ans += calc(n / i);
			if (n / i != i)
				ans += calc(i);
		}
	}
	printf("%lld\n", ans);
	return 0;
}