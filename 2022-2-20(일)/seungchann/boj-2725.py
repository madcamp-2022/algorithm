import math
import sys
input = sys.stdin.readline

n = int(input())
array = [int(input().rstrip()) for _ in range(n)]
result = 0
d = [0] * 1001
d[1] = 3

for i in range(2, 1001):
    count = 0
    for j in range(1, i):
        if math.gcd(i,j) == 1:
            count += 2
    d[i] = d[i-1] + count

for i in array:
    print(d[i])