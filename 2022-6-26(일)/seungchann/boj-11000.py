import queue
import sys
import heapq

input = sys.stdin.readline

n = int(input())
times = []

for _ in range(n):
    s, t = map(int ,input().split())
    times.append((s, t))

# '수업 시작 시간' 기준으로 오름차순 정렬
times.sort(key= lambda x: (x[0], x[1]))

queue = []

for time in times:
    if queue and queue[0] <= time[0]:
        heapq.heappop(queue)
    heapq.heappush(queue, time[1])

print(len(queue))