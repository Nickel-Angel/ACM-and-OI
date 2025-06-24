#include <algorithm>
#include <cstring>
#include <cstdio>

int L, R, dp[15][15], a[15], len;

int int_abs(int x, int y) {
    return x < y ? y - x : x - y;
}

int dfs_calc_num(int pos, int pre, bool lead, bool limit) {
    if (pos >= len) 
        return 1;
    if ((!lead) && (!limit) && (dp[pos][pre]))
        return dp[pos][pre];
    int res = 0;
    int curMax = limit ? a[len - 1 - pos] : 9;
    for (int i = 0; i <= curMax; ++i) {
        if (i == 0 && lead) {
            res += dfs_calc_num(pos + 1, 0, true, limit && (i == curMax));
        } else if (i != 0 && lead) {
            res += dfs_calc_num(pos + 1, i, false, limit && (i == curMax));
        } else if (int_abs(pre, i) >= 2) {
            res += dfs_calc_num(pos + 1, i, false, limit && (i == curMax));
        }
    }
    if ((!lead) && (!limit))
        dp[pos][pre] = res;
    return res;
}

int calc_num(int x) {
    if (x == 0)
        return 1;
    len = 0;
    memset(dp, 0, sizeof(dp));
    while (x) {
        a[len] = x % 10;
        x /= 10;
        ++len;
    }
    return dfs_calc_num(0, 0, true, true);
}

int main() {
    scanf("%d%d", &L, &R);
    printf("%d\n", calc_num(R) - calc_num(L - 1));
    return 0;
}