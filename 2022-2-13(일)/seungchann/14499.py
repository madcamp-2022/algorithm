row, col, y, x, _ = map(int, input().split())
my_map = list((list(map(int, input().split())) for _ in range(row)))
plans = list(map(int, input().split()))
answer_list = []
dice = [0] * 6

# 동서남북 이동 방향
dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]
# print(my_map)

# 시뮬레이션 시작
for plan in plans:
    new_dice = [0] * 6

    nx = x + dx[plan-1]
    ny = y + dy[plan-1]
    
    if nx < 0 or ny < 0 or nx > col-1 or ny > row-1:
        continue
    
    else:
        x = nx
        y = ny

        if plan == 1:
            new_dice = [dice[3], dice[1], dice[0], dice[5], dice[4], dice[2]]
        elif plan == 2:
            new_dice = [dice[2], dice[1], dice[5], dice[0], dice[4], dice[3]]
        elif plan == 3:
            new_dice = [dice[4], dice[0], dice[2], dice[3], dice[5], dice[1]]
        else:
            new_dice = [dice[1], dice[5], dice[2], dice[3], dice[0], dice[4]]
        dice = new_dice

        if my_map[y][x] == 0:
            my_map[y][x] = dice[5]
        else:
            dice[5] = my_map[y][x]
            my_map[y][x] = 0
        
        # print("plan: ", plan)
        # print("pos: " + str(x) + "," + str(y))
        # print("dice:", dice)
        # for i in range(col):
        #     for j in range(row):
        #         print(my_map[i][j], end=" ")
        #     print()
        answer_list.append(dice[0])
        # print()

for i in answer_list:
    print(i)

# 주사위
# [1, 2, 3, 4, 5, 6]
#
# plan == 1
# [3, 2, 4, 1, 5, 6]
#
# plan == 2
# [4, 2, 1, 3, 5, 6]
#
# plan == 3
# [5, 1, 3, 4, 6, 2]
#
# plan == 4
# [2, 6, 3, 4, 1, 5]
