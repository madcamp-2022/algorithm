import sys
input = sys.stdin.readline

a, b = map(int, input().split())
n, m = map(int, input().split())
my_map = [[0 for _ in range(a)] for _ in range(b)]

locations = list(list(input().split()) for _ in range(n))
commands = list(list(input().split()) for _ in range(m))

directions = ['S', 'W', 'N', 'E']
dx = [0, -1, 0, 1]
dy = [-1, 0, 1, 0]

robot_idx = 1
for idx in range(len(locations)):
    x, y, _ = locations[idx]
    my_map[int(y)-1][int(x)-1] = robot_idx
    locations[idx].append(robot_idx)
    robot_idx += 1

def find_my_location(idx):
    global locations
    result = (0, 0)

    for location in locations:
        if location[3] == idx:
            result = location
            break

    return result

is_end = False
for command in commands:
    idx, direction, step = command
    location = find_my_location(int(idx))
    original_location = locations[locations.index(location)]
    r_x, r_y, r_dir, _ = location
    r_x = int(r_x)-1
    r_y = int(r_y)-1

    my_map[r_y][r_x] = 0

    r_dir = int(directions.index(r_dir))

    for _ in range(int(step)):
        if direction == 'F':
            nx = r_x + dx[r_dir]
            ny = r_y + dy[r_dir]

            if nx < 0 or ny < 0 or nx > a-1 or ny > b-1:
                print("Robot", idx, "crashes into the wall")
                is_end = True
                break
            
            if my_map[ny][nx] != 0:
                print("Robot", idx, "crashes into robot", my_map[ny][nx])
                is_end = True
                break

            r_x = nx
            r_y = ny
        
        elif direction == 'L':
            r_dir -= 1
        
        elif direction == 'R':
            r_dir += 1
    
        if r_dir > 3:
            r_dir = 0
        elif r_dir < 0:
            r_dir = 3
    
    my_map[r_y][r_x] = idx
    # update location
    original_location[0] = r_x +1
    original_location[1] = r_y +1

    # update direction
    original_location[2] = directions[r_dir]
    
    if is_end:
        break

if not is_end:
    print("OK")