#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int maxn = 1e5 + 10;
int n, par[maxn], dp[maxn];

std::vector<int> e[maxn];

void dfs(int u) {
	for (unsigned i = 0, v; i < e[u].size(); ++i) {
		v = e[u][i];
		dfs(v);
		dp[u] = std::max(dp[u], dp[v]);
	}
	dp[u] += e[u].size();
}

int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i) {
		scanf("%d", par + i);
		e[par[i]].push_back(i);
	}
	dfs(1);
	printf("%d\n", dp[1]);
	return 0;
}