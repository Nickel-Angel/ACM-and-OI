from collections import deque

a = list(input().split())
S = 0; T = 123456789
for i in range(9):
        if a[i] == "x":
            S = S * 10 + 9
        else:
            S = S * 10 + ord(a[i]) - ord('0')
d = {0: [1, 3], 1: [0, 2, 4], 2: [1, 5], 3: [0, 4, 6], 4: [1, 3, 5, 7], 5: [2, 4, 8], 6: [3, 7], 7: [4, 6, 8], 8: [5, 7]}
dis = {S: 0}

def calc(a):
    res = 0
    for i in range(9):
        res = res * 10 + a[i]
    return res

def bfs(S, T):
    q = deque([S])
    while len(q):
        x = q[0]
        if x == T:
            break
        q.popleft()
        cur = []; y = x
        while y:
            cur.append(y % 10)
            y //= 10
        cur.reverse()
        i = cur.index(9)
        for j in d[i]:
            cur[i], cur[j] = cur[j], cur[i]
            z = calc(cur)
            if z not in dis:
                dis[z] = dis[x] + 1
                q.append(z)
            cur[i], cur[j] = cur[j], cur[i]

bfs(S, T)
print(dis[T] if T in dis else -1)