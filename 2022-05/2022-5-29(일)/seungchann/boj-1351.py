from collections import defaultdict
import sys
input = sys.stdin.readline

n, p, q = map(int, input().split())
dp = defaultdict(int)
dp[0] = 1

def A(num):
    global dp, p, q
    if dp[num]:
        return dp[num]
    else:
        dp[num] = A(num//p) + A(num//q)
        return dp[num]

A(n)
print(dp[n])