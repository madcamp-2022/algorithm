import sys
sys.setrecursionlimit(10**6)

def dfs(i):
    ret = island[i]
    for v in vertex[i]:
        ret += dfs(v)
    
    return max(ret, 0)

N = int(input())
island = [0] * 123458
vertex = [[] for _ in range(123458)]

for i in range(2, N+1):
    inputs = input().split()
    vertex[int(inputs[2])].append(i)
    # print(vertex)
    island[i] = int(inputs[1])
    if (inputs[0] == 'W'):
        island[i] = -island[i]

print(dfs(1))

# answer = 0
# for i in range(2, N+1):
#     if island[i][0] == 'S':
#         escaping_sheep = island[i][1]
#         if (escaping_sheep == 0):
#             continue
#         island[i][1] = 0
#         cur_island = i
#         while True:
#             if (cur_island == 1):
#                 answer += escaping_sheep
#                 break
#             if island[cur_island][0] == 'W':
#                 if (island[cur_island][1] >= escaping_sheep):
#                     island[cur_island][1] -= escaping_sheep
#                     break
#                 else:
#                     escaping_sheep -= island[cur_island][1]
#                     island[cur_island][1] = 0
#             else:
#                 escaping_sheep += island[cur_island][1]
#                 island[cur_island][1] = 0
            
#             cur_island = island[cur_island][2]

# print(answer)