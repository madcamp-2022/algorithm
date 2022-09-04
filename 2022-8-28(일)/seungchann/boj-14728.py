import sys
input = sys.stdin.readline

n, t = map(int, input().split())
time = [0]
score = [0]
dp = [[0 for _ in range(t+1)] for _ in range(n+1)]

for _ in range(n):
    tm, s = map(int, input().split())
    time.append(tm)
    score.append(s)

for i in range(1, n+1):
    for j in range(1, t+1):
        if (j - time[i] >= 0):
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-time[i]] + score[i])
        else:
            dp[i][j] = dp[i-1][j]

print(dp[n][t])