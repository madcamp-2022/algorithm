import sys
input = sys.stdin.readline

def get_combinations(n):
    seats = [0 for _ in range(41)]
    seats[0] = 1
    seats[1] = 1
    for i in range(2, n+1):
        seats[i] = seats[i-1] + seats[i-2]
    return seats

if __name__ == "__main__":
    n = int(input())
    m = int(input())
    
    # 연속된 i개의 일반 좌석에서 바꿔 앉을 수 있는 경우의 수
    dp = get_combinations(n)
    
    result = 1
    idx = 1
    vip = 0
    for _ in range(m):
        vip = int(input())
        result *= dp[vip-idx]
        idx = min(vip+1, n)
    result *= dp[n-vip]
    
    print(result)