from collections import deque
import sys
input = sys.stdin.readline

def solve(n, arr):
    if n == 1:
        return 0

    q = deque([(0, 0)])
    visited = [False for _ in range(n)]
    visited[0] = True

    while q:
        pos, cnt = q.popleft()
        for i in range(arr[pos]):
            next = i+1
            if pos+next >= n-1:
                return cnt+1

            if visited[pos+next]:
                continue

            q.append((pos+next, cnt+1))
            visited[pos+next] = True
    return -1

if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    print(solve(n, arr))