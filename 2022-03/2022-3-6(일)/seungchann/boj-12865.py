import sys
input = sys.stdin.readline

N, K = map(int, input().split())
d = [[0] * (K+1) for _ in range(N+1)]

for i in range(1, N+1):
    item, value = map(int, input().split())
    for j in range(1, K+1):
        if item > j:
            d[i][j] = d[i-1][j]
        else:
            d[i][j] = max(d[i-1][j], d[i-1][j-item] + value)

print(d[N][K])