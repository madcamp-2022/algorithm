import sys
input = sys.stdin.readline

n = int(input())
senior_links = [0]

for _ in range(n):
    senior_links.append(int(input()))

senior_counts = [0]
for idx in range(1, n+1):
    cur = idx
    cnt = 0
    visited = [False] * (n+1)
    
    while True:
        val = senior_links[cur]
        if visited[val]:
            break
        visited[cur] = True
        cur = val
        cnt += 1
    
    senior_counts.append(cnt)

print(senior_counts.index(max(senior_counts)))