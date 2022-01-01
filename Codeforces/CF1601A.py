# @author Nickel_Angel (1239004072@qq.com)
# @copyright Copyright (c) 2021

def solve():
    n = int(input())
    a = [0] + [*map(int, input().split())]
    cnt = [0] * 40
    for i in range(0, 31):
        for j in range(1, n + 1):
            if (a[j] & (1 << i)):
                cnt[i] += 1
    for i in range(1, n + 1):
        flag = True
        for j in range(0, 31):
            if (cnt[j] % i):
                flag = False
                break
        if (flag):
            print(i, end = ' ')
    print()

t = int(input())
for i in range(0, t):
    solve()