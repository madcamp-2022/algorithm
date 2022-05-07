import sys
input = sys.stdin.readline

n = int(input())
array = []
for _ in range(n):
    a, b = map(int, input().split())
    array.append(b-a)
array.sort()

if not n%2 == 0:
    print(1)

else:
    print(abs(array[int(n/2)] - array[int(n/2)-1]) + 1)
