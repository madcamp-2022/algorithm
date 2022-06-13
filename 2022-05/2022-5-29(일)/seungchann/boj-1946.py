import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    array = list(list(map(int, input().split())) for _ in range(n))
    array.sort(key= lambda x: x[0])
    result = 0
    min_rank = n+1
    for idx, [_, rank] in enumerate(array):
        if idx == 0:
            result += 1
            min_rank = rank
            continue

        if rank < min_rank:
            result += 1        
        min_rank = min(rank, min_rank)

    print(result)