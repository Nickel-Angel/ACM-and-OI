#include <cstring>
#include <cstdio>

int cnt[10];

inline bool split(int x) {
	while (x) {
		if (!cnt[x % 10])
			return false;
		--cnt[x % 10];
		x /= 10;
	}
	return true;
}

int main() {
	for (int i = 0; i < 10; ++i)
		cnt[i] = 2021;
	int x = 1;
	while (split(x))
		++x;
	printf("%d\n", x);
	return 0;
}