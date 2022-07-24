import math
import sys
input = sys.stdin.readline
n, m = map(int, input().split())
print(m - math.gcd(n, m))