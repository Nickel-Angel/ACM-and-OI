# @author Nickel_Angel (1239004072@qq.com)
# @copyright Copyright (c) 2022

def solve():
    n, m = map(int, input().split())
    a = [([0] + list(map(int, input().split()))) for i in range(n)]
    a = [[0 for i in range(m + 1)]] + a
    f = [[0 for i in range(1 << m)] for j in range(n + 1)]
    
    def check(S):
        while S:
            if S & 3 == 3:
                return False
            S >>= 1
        return True

    def calc(i, S):
        res = 0
        for j in range(1, m + 1):
            if (S >> (j - 1)) & 1:
                res += a[i][j]
        return res

    can = [check(S) for S in range(1 << m)]
    for i in range(1, n + 1):
        for S in range(1 << m):
            if not can[S]:
                continue
            for T in range(1 << m):
                if S & (T << 1) or S & T or S & (T >> 1) or not can[T]:
                    continue
                f[i][S] = max(f[i][S], f[i - 1][T])
            f[i][S] += calc(i, S)
    print(max(x for x in f[n]))

for i in range(int(input())):
    solve()