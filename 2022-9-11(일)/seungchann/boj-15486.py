import sys
input = sys.stdin.readline

def solve(n, time, cost):
    dp = [0 for _ in range(n+2)]

    for i in range(n, 0, -1):
        if i + time[i] > n+1:
            dp[i] = dp[i+1]
            continue
        
        dp[i] = max(dp[i+1], cost[i] + dp[i+time[i]])

    return dp[1]


if __name__ == "__main__":
    n = int(input())
    time = [0]
    cost = [0]
    
    for _ in range(n):
        t, c = map(int, input().split())
        time.append(t)
        cost.append(c)

    print(solve(n, time, cost))