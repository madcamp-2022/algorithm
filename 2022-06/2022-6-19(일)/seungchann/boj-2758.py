import sys
input = sys.stdin.readline

dp = list(list(0 for _ in range(2001)) for _ in range(11))
t = int(input())

for y in range(11):
    for x in range(2001):
        if y == 1:
            dp[y][x] = x
            continue
        dp[y][x] = dp[y-1][int(x/2)] + dp[y][x-1]

for _ in range(t):
    n, m = map(int, input().split())
    print(dp[n][m])