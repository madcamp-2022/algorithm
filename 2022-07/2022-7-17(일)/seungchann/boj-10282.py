import heapq
import sys

input = sys.stdin.readline
INF = 10e9
t = int(input())

def dijkstra(graph, start, distance):
    q = []
    # 시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입
    heapq.heappush(q, (0, start))
    distance[start] = 0

    while q: # 큐가 비어있지 않다면
        # 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
        dist, now = heapq.heappop(q)
        # 현재 노드가 이미 처리된 적이 있는 노드라면 무시
        if distance[now] < dist:
            continue
        # 현재 노드와 연결된 다른 인접한 노드들을 확인
        for i in graph[now]:
            cost = dist +i[1]
            # 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))

for _ in range(t):
    n, d, c = map(int, input().split())
    graph = [[] for _ in range(n+1)]
    distance = [INF for _ in range(n+1)]
    
    for _ in range(d):
        a, b, s = map(int, input().split())
        graph[b].append((a, s))
    
    dijkstra(graph, c, distance)
    distance = list(filter(lambda x: x != INF, distance))
    print(len(distance), max(distance))