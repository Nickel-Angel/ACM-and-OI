# @author Nickel_Angel (1239004072@qq.com)
# @copyright Copyright (c) 2021

def solve():
    n, k = map(int, input().split())
    x = 0
    while (1 << x) < k:
        x += 1
    print(x + max(0, (n - (1 << x) + k - 1) // k))
    return

t = int(input())
while t:
    t -= 1
    solve()