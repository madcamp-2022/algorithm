import sys
input = sys.stdin.readline

s, k = map(int, input().split())

if s % k == 0:
    print(int(s/k)**k)

else:
    val = int(s/k)+1
    gap = (val*k) - s
    print((val**(k-gap)) * ((val-1)**gap))