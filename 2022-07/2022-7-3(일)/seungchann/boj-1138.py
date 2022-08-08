import sys
input = sys.stdin.readline

n = int(input())
array = list(map(int, input().split()))
result = list(-1 for _ in range(n))

for idx in range(n-1, -1, -1):
    result.insert(array[idx], str(idx+1))

print(' '.join(result[:n]))