import sys

input = sys.stdin.readline

N = int(input())

dp = [0 for _ in range(N + 1)]
for i in range(1, N + 1):
    for j in range(i, N + 1, i):
        dp[j] += i

print(sum(dp))
