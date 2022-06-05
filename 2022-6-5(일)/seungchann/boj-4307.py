import sys
input = sys.stdin.readline

n = int(input())

for _ in range(n):
    l, ants = map(int, input().split())
    # min_l -> 개미들이 각자 가장 짧은 경로로 갈 때, 가장 오래 걸린 시간
    # max_l -> 개미들이 각자 가장 먼 경로로 갈 때, 가장 오래 걸린 시간
    min_l, max_l = 0, 0
    for _ in range(ants):
        cur = int(input())
        min_l = max(min(cur, l-cur), min_l)
        max_l = max(max(cur, l-cur), max_l)
    print(min(min_l, max_l), max(min_l, max_l))    