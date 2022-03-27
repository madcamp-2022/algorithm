import sys
input = sys.stdin.readline

n = int(input())
x, y = map(int, input().split())

x = x-1
y = 2**n-y

my_map = [[0 for _ in range(2**n)] for _ in range(2**n)]

if n == 1:
    for i in range(2):
        for j in range(2):
            my_map[i][j] = 1

flag = 0
if n == 2:
    for i in range(4):
        for j in range(4):
            if j<2:
                if i<2:
                    my_map[i][j] = 1
                else:
                    my_map[i][j] = 3
            else:
                if i<2:
                    my_map[i][j] = 2
                else:
                    my_map[i][j] = 4
            
            if j>0 and j<3 and i>0 and i<3:
                my_map[i][j] = 5
    
    for _ in range(4):
        for _ in range(4):
            if y<2:
                if x<2:
                    flag = 1
                else:
                    flag = 2
            else:
                if x<2:
                    flag = 3
                else:
                    flag = 4
            
            if x>0 and x<3 and y>0 and y<3:
                flag = 0
    
    if flag == 1:
        my_map[1][1] = flag
    elif flag == 2:
        my_map[1][2] = flag
    elif flag == 3:
        my_map[2][1] = flag
    elif flag == 4:
        my_map[2][2] = flag

my_map[y][x] = -1

for i in range(2**n):
    for j in range(2**n):
        print(my_map[i][j], end=' ')
    print()