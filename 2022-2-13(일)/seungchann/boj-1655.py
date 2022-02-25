import heapq
from sys import stdin

n = int(stdin.readline())
min_heap = []
max_heap = []

for _ in range(n):
    num = int(stdin.readline())

    if len(min_heap) == len(max_heap):
        heapq.heappush(max_heap, (-1 * num))
    else:
        heapq.heappush(min_heap, num)

    if len(max_heap) >= 1 and len(min_heap) >= 1 and (max_heap[0] * -1) > min_heap[0]:
        max_num = heapq.heappop(max_heap) * -1
        min_num = heapq.heappop(min_heap)

        heapq.heappush(max_heap, (min_num * -1))
        heapq.heappush(min_heap, max_num)
    
    print(max_heap[0] * -1)