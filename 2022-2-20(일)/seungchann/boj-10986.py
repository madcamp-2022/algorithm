import sys
input = sys.stdin.readline

n, m = map(int, input().split())
v = list(map(int, input().split()))

pSum, cnt = 0, [0] * m
for i in range(n):
    pSum = (pSum + v[i]) % m
    cnt[pSum] += 1

ans = 0
for i in range(m):
    if i == 0:
        ans += cnt[i] * (cnt[i] + 1) >> 1
    else:
        ans += cnt[i] * (cnt[i] - 1) >> 1
print(ans)

