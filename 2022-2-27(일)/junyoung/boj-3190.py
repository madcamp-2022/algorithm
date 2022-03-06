import sys

def stdin():
    return sys.stdin.readline()

def print_board(t, snake, board):
    print('-' * 10)
    print(snake)
    print(f'Time: {t}')
    for i in board:
        print(i)

def get_ans(N, board, move, dir_index, snake):
    t = 0
    directions = ['up', 'right', 'down', 'left']
    while True:
        head = [snake[-1][0], snake[-1][1]]
        tail = [snake[0][0], snake[0][1]]
        if directions[dir_index] == 'up':
            head[0] -= 1
        elif directions[dir_index] == 'down':
            head[0] += 1
        elif directions[dir_index] == 'left':
            head[1] -= 1
        elif directions[dir_index] == 'right':
            head[1] += 1
        try:
            block = board[head[0]][head[1]]
            if head[0] < 0 or head[0] == N:
                break
            if head[1] < 0 or head[1] == N:
                break
            if block == 2:
                break
            elif block == 1:
                snake.append(head)
                board[head[0]][head[1]] = 2
            else:
                board[head[0]][head[1]] = 2
                board[tail[0]][tail[1]] = 0
                snake.append(head)
                snake.pop(0)
        except:
            break

        t += 1

        try:
            if int(move[0][0]) == t:
                if move[0][1] == 'L':
                    dir_index -= 1
                    if dir_index < 0:
                        dir_index = 3
                else:
                    dir_index += 1
                    dir_index %= 4
                move.pop(0)
        except:
            pass
        # print_board(t, snake, board)

    print(t + 1)

def ans():
    N = int(stdin())
    K = int(stdin())
    board = [[0 for _ in range(N)] for _ in range(N)]
    for _ in range(K):
        x, y = map(int, stdin().split())
        board[x - 1][y - 1] = 1
    L = int(stdin())
    move = [stdin().split() for _ in range(L)]
    direction = 1
    snake = [[0, 0]]
    board[0][0] = 2
    get_ans(N, board, move, direction, snake)




if __name__ == '__main__':
    ans()