import sys
input = sys.stdin.readline

def solve(n, arr, cnt):
    for i in range(n-1):
        if cnt == 0:
            break
        
        max_val, idx = arr[i], i
        
        for j in range(i+1, min(n, i+1+cnt)):
            if max_val < arr[j]:
                max_val = arr[j]
                idx = j
        
        cnt -= (idx - i)
    
        for j in range(idx, i, -1):
            arr[j] = arr[j-1]
        
        arr[i] = max_val
    
    return arr

n = int(input())
array = list(map(int, input().split()))
s = int(input())

print(*solve(n, array, s))