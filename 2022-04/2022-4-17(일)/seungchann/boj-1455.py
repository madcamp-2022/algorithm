import sys
input = sys.stdin.readline

N, M = map(int, input().split())
array = [list(list(map(int, input().rstrip()))) for _ in range(N)]

def toggle(arr, n, m):
    for i in range(n+1):
        for j in range(m+1):
            if arr[i][j] == 0:
                arr[i][j] = 1
            else:
                arr[i][j] = 0

result = 0
for i in range(N-1, -1, -1):
    for j in range(M-1, -1, -1):
        if array[i][j] == 1:
            toggle(array, i, j)
            result += 1

print(result)