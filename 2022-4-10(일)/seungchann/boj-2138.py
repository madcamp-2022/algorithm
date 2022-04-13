import sys
input = sys.stdin.readline

n = int(input().rstrip())
current = list(map(int, input().rstrip()))
goal = list(map(int, input().rstrip()))

def solve(arr, cnt):
    global goal
    count = cnt
    if count == 1:
        arr[0] = int(not(arr[0]))
        arr[1] = int(not(arr[1]))
    for i in range(1, n):
        if arr[i-1] != goal[i-1]:
            count += 1
            arr[i-1] = int(not(arr[i-1]))
            arr[i] = int(not(arr[i]))
            if i != n-1:
                arr[i+1] = int(not(arr[i+1]))
    
    if arr == goal:
        return count
    else:
        return 100003

ans_one = solve(current[:], 0)
ans_two = solve(current[:], 1)

if ans_one == 100003 and ans_two == 100003:
    print(-1)
else:
    print(min(ans_one, ans_two))
