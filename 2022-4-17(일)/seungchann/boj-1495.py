import sys
input = sys.stdin.readline

N, S, M = map(int, input().split())
V = list(map(int, input().split()))

# dp[i] = i번째 곡에서 만들 수 있는 모든 볼륨들의 set
dp = [0] * (N+1)
dp[0] = set([S])

for i in range(1, N+1):
    temp_list = []
    for j in dp[i-1]:
        # 볼륨 차이만큼 더한 경우
        plus = j + V[i-1]
        if 0 <= plus <= M:
            temp_list.append(plus)
        # 볼륨 차이만큼 뺀 경우
        minus = j - V[i-1]
        if 0 <= minus <= M:
            temp_list.append(minus)

    # 만들 수 있는 볼륨이 없을 때
    if len(temp_list) == 0:
        dp[-1] = [-1]
        break
    dp[i] = set(temp_list)

print(max(dp[-1]))