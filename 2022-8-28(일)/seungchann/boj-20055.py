from collections import deque
import sys
input = sys.stdin.readline

def solve(n, k, belt):
    answer = 0
    robot = deque([0] * (n+2))

    while True:
        # 벨트, 로봇 이동
        belt.rotate(1)
        robot.rotate(1)

        # 로봇이 내리기 전 칸에 있을 경우, 한 칸 이동해서 내림
        robot[n-1] = 0

        # 로봇이 이동 가능한 경우 이동        
        for i in range(n-2, -1, -1):
            if (robot[i] != 0 and robot[i+1] == 0 and belt[i+1] >= 1):
                belt[i+1] -= 1
                robot[i+1] = robot[i]
                robot[i] = robot[0]
        
        # 로봇이 내리기 전 칸에 있을 경우, 한 칸 이동해서 내림
        robot[n-1] = 0

        # 로봇을 새로 올릴 수 있는 경우, 로봇을 올림
        if belt[0] >= 1:
            belt[0] -= 1
            robot[0] = 1
        
        answer += 1
        
        # 내구성이 0인 벨트가 k개 이상일 경우 종료
        if belt.count(0) >= k:
            break

    print(answer)

if __name__ == "__main__":
    n, k = map(int, input().split())
    belt = deque(list(map(int, input().split())))
    solve(n, k, belt)