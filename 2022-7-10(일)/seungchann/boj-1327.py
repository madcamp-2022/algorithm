from collections import deque
import sys
input = sys.stdin.readline

n, k = map(int, input().split())
array = list(map(int, input().split()))
answer = sorted(array)

def n_sort(start, l, arr):
    return arr[:start] + arr[start:start+l][::-1] + arr[start+l:]

def bfs(arr, leng, ans):
    # array, count
    queue = deque([(arr, 0)])
    visited = set()
    visited.add("".join(list(map(str, arr))))

    if arr == ans:
        return 0

    while queue:
        v, cnt = queue.popleft()
        for idx in range(0, max(len(arr)-leng+1, 1)):    
            temp = n_sort(idx, k, v)

            if temp == ans:
                return cnt+1
            
            temp_str = "".join(list(map(str, temp)))
            if temp_str in visited:
                continue
            
            queue.append((temp, cnt+1))
            visited.add(temp_str)

    return -1

print(bfs(array, k, answer))