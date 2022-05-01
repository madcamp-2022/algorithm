import sys
from collections import deque
input = sys.stdin.readline
primes = []

def is_prime(n):
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True

for num in range(2, 100001):
    if is_prime(num):
        primes.append(num)

def bfs(start):
    queue = deque([[start, 0]])
    visited = [False for _ in range(1000001)]
    visited[start] = True

    while queue:
        global a, b, primes
        v, cnt = queue.popleft()
        visited[v] = True
        
        for iter in range(4):
            next = 0
            if iter == 0:
                next = int(v/2)
            elif iter == 1:
                next = int(v/3)
            elif iter == 2:
                next = v+1
            else:
                next = v-1
        
            if (a <= next <= b) and (next in primes):
                return cnt+1
            
            if next <= 0 or next >= 1000001 or visited[next]:
                continue
            
            visited[next] = True
            queue.append([next, cnt+1])
        
    return -1

t = int(input())
for _ in range(t):
    n, a, b = map(int, input().split())

    if a <= n <= b:
        print(0)
        continue

    print(bfs(n))