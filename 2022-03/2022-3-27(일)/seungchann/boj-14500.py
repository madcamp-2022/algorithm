import sys
input = sys.stdin.readline

N, M = list(map(int, input().split()))
array = list(list(map(int, input().split())) for _ in range(N))

case_one = [[(0,0), (1,0), (2,0), (3,0)], [(0,0), (0,1), (0,2), (0,3)]]
case_two = [[(0,0), (0,1), (1,0), (1,1)]]
case_three_one = [[(0,0), (1,0), (1,1), (1,2)], [(0,0), (-1,0), (-1,1), (-1,2)], [(0,0), (1,0), (1,-1), (1,-2)], [(0,0), (-1,0), (-1,-1), (-1,-2)]]
case_three_two = [[(0,0), (1,0), (2,0), (2,1)], [(0,0), (1,0), (2,0), (2,-1)], [(0,0), (-1,0), (-2,0), (-2,1)], [(0,0), (-1,0), (-2,0), (-2, -1)]]
case_four = [[(0,0), (0,1), (1,1), (1,2)], [(0,0), (0,1), (-1,1), (-1,2)], [(0,0), (1,0), (1,-1), (2,-1)], [(0,0), (-1,0), (-1,-1), (-2,-1)]]
case_five = [[(0,0), (1,0), (2,0), (1,-1)], [(0,0), (1,0), (2,0), (1,1)], [(0,0), (0,1), (0,2), (-1,1)], [(0,0), (0,1), (0,2), (1,1)]]

cases = case_one + case_two + case_three_one + case_three_two + case_four + case_five

result = 0
# array 브루트 포스
for y in range(N):
    for x in range(M):
        # 테트로미노 브루트 포스
        for case in cases:
            temp_sum = 0
            out_range = False
            for dx, dy in case:
                nx = x + dx
                ny = y + dy

                if nx < 0 or ny < 0 or nx >= M or ny >= N:
                    out_range = True
                    break
                
                temp_sum += array[ny][nx]

            if out_range:
                continue
            
            result = max(result, temp_sum)

print(result)
