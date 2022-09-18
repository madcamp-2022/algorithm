import sys
input = sys.stdin.readline

def solve(coins, price):
    dp = [0 for _ in range(price+1)]
    dp[0] = 1

    for i, coin in enumerate(coins):
        for j in range(coins[i], price+1):
            dp[j] += dp[j-coin]
    
    return dp[price]

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        arr = list(map(int, input().split()))
        p = int(input())
        print(solve(arr, p))