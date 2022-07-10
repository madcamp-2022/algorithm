import sys
input = sys.stdin.readline

n, k = map(int, input().split())

dp = list(list(0 for _ in range(k+1)) for _ in range(n+1))

for y in range(n+1):
    for x in range(k+1):
        if x == 1:
            dp[y][x] = 1
            continue
        dp[y][x] = dp[y-1][x] + dp[y][x-1]

print(dp[n][k] % 1_000_000_000)