import sys
input = sys.stdin.readline

n = int(input())
cost = []
result = 10e9

for _ in range(n):
    cost.append(list(map(int, input().split())))

for init in range(3):
    dp = [[0] * 3 for _ in range(n)]

    for j in range(3):
        if j == init:
            dp[0][j] = cost[0][j]
            continue
        dp[0][j] = 10e9
    
    for i in range(1, n):
        dp[i][0] = cost[i][0] + min(dp[i-1][1], dp[i-1][2])
        dp[i][1] = cost[i][1] + min(dp[i-1][0], dp[i-1][2])
        dp[i][2] = cost[i][2] + min(dp[i-1][0], dp[i-1][1])

    for j in range(3):
        if j == init:
            continue
        result = min(result, dp[-1][j])
    
print(result)