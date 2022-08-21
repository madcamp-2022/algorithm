import sys
input = sys.stdin.readline

def find_plus(x, y):
    global n, array
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]
    is_end = False
    result = 0
    temp = [(x, y)]
    
    while True:    
        for i in range(4):
            nx = x + (dx[i] * (result+1))
            ny = y + (dy[i] * (result+1))

            if nx < 0 or ny < 0 or nx >= n or ny >= n:
                is_end = True
                break
            
            if array[ny][nx] == "0":
                is_end = True
                break

            temp.append((nx, ny))

        if not is_end:
            y_start, y_end = y-(result+1), y+(result+1)+1 
            x_start, x_end = x-(result+1), x+(result+1)+1

            for cx in range(x_start, x_end):
                if cx == (x_start+x_end-1) / 2:
                    if array[y_start][cx] == "0":
                        is_end = True
                    if array[y_end-1][cx] == "0":
                        is_end = True
                    continue
                
                elif array[y_start][cx] == "1":
                    is_end = True
                elif array[y_end-1][cx] == "1":
                    is_end = True

            for cy in range(y_start, y_end):
                if cy == (y_start+y_end-1) / 2:
                    if array[cy][x_start] == "0":
                        is_end = True
                    if array[cy][x_end-1] == "0":
                        is_end = True
                    continue
                
                elif array[cy][x_start] == "1":
                    is_end = True
                elif array[cy][x_end-1] == "1":
                    is_end = True

        if is_end:
            return result
        else:
            result += 1

if __name__ == "__main__":
    n = int(input())
    array = list(list(list(input().rstrip()) for _ in range(n)))

    result = 0
    for y in range(n):
        for x in range(n):
            if array[y][x] == "0":
                continue
            elif x-1 < 0 or y-1 < 0 or x+1 >= n or y+1 >= n:
                continue
            elif array[y+1][x] == "0" or array[y][x+1] == "0" or array[y-1][x] == "0" or array[y][x-1] == "0":
                continue
            else:
                result += find_plus(x, y)

    print(result)