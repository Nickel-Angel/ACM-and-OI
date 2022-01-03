from collections import deque

n, a, b = list(map(int, input().split()))
K = [0] + list(map(int, input().split()))
dis = [-1 for i in range(0, n + 1)]

def bfs(S, T):
    q = deque([S])
    dis[S] = 0
    while len(q):
        x = q[0]
        if x == T:
            break
        q.popleft()
        if x + K[x] <= n and dis[x + K[x]] == -1:
            dis[x + K[x]] = dis[x] + 1
            q.append(x + K[x])
        if x - K[x] > 0 and dis[x - K[x]] == -1:
            dis[x - K[x]] = dis[x] + 1
            q.append(x - K[x])

bfs(a, b)
print(dis[b])