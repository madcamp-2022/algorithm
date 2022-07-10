import sys
input = sys.stdin.readline

n = int(input())
hexagonals = []

gap, num = 5, 1
while True:
    if num > min(1_000_000, n):
        break
    hexagonals.append(num)
    num += gap
    gap += 4

dp = [10e9] * 1_000_001
dp[0] = 0

for idx in hexagonals:
    dp[idx] = 1

for i in range(2, n+1):
    min_val = 10e9
    for h in hexagonals:
        if h > i:
            break
        min_val = min(min_val, dp[i-h])
    dp[i] = min_val + 1

print(dp[n])