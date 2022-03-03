import heapq
import sys

input = sys.stdin.readline
N = int(input())
min_heap = []
max_heap = []
for _ in range(N):
    num = int(input())
    if not max_heap:
        heapq.heappush(max_heap, -num)
    else:
        if len(max_heap) > len(min_heap):
            heapq.heappush(min_heap, num)
        else:
            heapq.heappush(max_heap, -num)
        if -max_heap[0] > min_heap[0]:
            min_num = heapq.heappop(min_heap)
            max_num = -heapq.heappop(max_heap)

            heapq.heappush(min_heap, max_num)
            heapq.heappush(max_heap, -min_num)
    print(-max_heap[0])
