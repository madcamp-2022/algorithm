import sys
input = sys.stdin.readline

n, d = map(int, input().split())
dp = [i for i in range(d+1)]
graph = []

for _ in range(n):
    start, end, dist = map(int, input().split())
    if end > d or dist > end-start:
        continue
    graph.append([start, end, dist])

graph.sort(key= lambda x: x[0])

for start, end, dist in graph:
    dp[end] = min(dp[end], dp[start]+dist)
    for idx, dist in enumerate(dp):
        dp[idx] = min(dp[idx], dp[idx-1]+1)

print(dp[d])