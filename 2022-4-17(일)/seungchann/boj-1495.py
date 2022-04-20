import sys
input = sys.stdin.readline

N, S, M = map(int, input().split())
V = list(map(int, input().split()))
dp = [0] * (N+1)
dp[0] = set([S])

for i in range(1, N+1):
    temp_list = []
    for j in dp[i-1]:
        plus = j + V[i-1]
        if 0 <= plus <= M:
            temp_list.append(plus)
        minus = j - V[i-1]
        if 0 <= minus <= M:
            temp_list.append(minus)
    if len(temp_list) == 0:
        dp[-1] = [-1]
        break
    dp[i] = set(temp_list)

print(max(dp[-1]))