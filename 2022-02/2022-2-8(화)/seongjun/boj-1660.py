import sys

input = sys.stdin.readline
INF = sys.maxsize

N = int(input())
nums = []
i = 1
while True:
    cur = (i * (i + 1) * (i + 2)) // 6
    if cur > N:
        break
    nums.append(cur)
    i += 1
dp = [INF for _ in range(N + 1)]
for n in nums:
    dp[n] = 1
for i in range(1, N + 1):
    for n in nums:
        if n < i:
            dp[i] = min(dp[i], dp[i - n] + 1)
print(dp[-1])
