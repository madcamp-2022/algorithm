import sys

input = sys.stdin.readline
INF = sys.maxsize

C, N = map(int, input().split())
infos = []
dp = [INF for _ in range(1101)]
dp[0] = 0
for _ in range(N):
    infos.append([*map(int, input().split())])
for i in range(1, 1101):
    for c, n in infos:
        if i - n < 0:
            continue
        dp[i] = min(dp[i], dp[i - n] + c)
print(min(dp[C:]))
