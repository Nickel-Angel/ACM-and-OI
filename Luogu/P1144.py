# @author Nickel_Angel (1239004072@qq.com)
# @copyright Copyright (c) 2022

from collections import deque

n, m = list(map(int, input().split()))
p = 100003
e = [[] for i in range(n + 1)]
dis = [0x3f3f3f3f for i in range(n + 1)]
dp = [0 for i in range(n + 1)]
for i in range(m):
    u, v = list(map(int, input().split()))
    e[u].append(v); e[v].append(u)

def bfs(S):
    q = deque([S])
    dis[S] = 0; dp[S] = 1
    while len(q):
        u = q[0]
        q.popleft()
        for v in e[u]:
            if dis[v] == 0x3f3f3f3f:
                dis[v] = dis[u] + 1
                dp[v] = dp[u]
                q.append(v)
            elif dis[v] == dis[u] + 1:
                dp[v] = (dp[v] + dp[u]) % p

bfs(1)
for i in range(1, n + 1):
    print(dp[i])