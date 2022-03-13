import sys
input = sys.stdin.readline

t, w = map(int, input().split())
dp = [[0 for _ in range(w+1)] for _ in range(t)]
plum = []

for _ in range(t):
    plum.append(int(input().rstrip()))

for i in range(t):
    for j in range(w+1):
        # 움직임이 없을 경우 (초기 위치는 1)
        # 자두의 위치가 1일때만 +1
        if j == 0:
            if plum[i] == 1:
                dp[i][0] = dp[i-1][0] + 1
            else:
                dp[i][0] = dp[i-1][0]
        else:
            # 움직임이 짝수일 경우
            # 자두의 위치가 1일때만 +1
            if plum[i] == 1 and j%2 == 0:
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + 1
            
            # 움직임이 홀수일 경우
            # 자두의 위치가 2일때만 +1
            elif plum[i] == 2 and j%2 == 1:
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1])

print(max(dp[t-1]))