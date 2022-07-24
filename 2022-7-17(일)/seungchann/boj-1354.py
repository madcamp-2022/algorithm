import sys
input = sys.stdin.readline

n, p ,q, x, y = map(int, input().split())
visited = {}

def A(i, p, q, x, y):
    global visited
    if i == 0:
        visited[i] = 1
        return 1
    else:
        front = max(0, int(i/p)-x)

        if not front in visited:
            visited[front] = A(front, p, q, x, y)
        front = visited[front]
        
        back = max(0, int(i/q)-y)
        if not back in visited:
            visited[back] = A(back, p, q, x, y)
        back = visited[back]
            
        return front + back

print(A(n, p, q, x, y))