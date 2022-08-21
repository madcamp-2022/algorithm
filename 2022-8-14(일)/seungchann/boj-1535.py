import sys
input = sys.stdin.readline

def solve(hp, score):
    dp = [0 for _ in range(100)]
    
    for idx, h in enumerate(hp): 
        for j in range(99, 0, -1):
            if h <= j:
                dp[j] = max(dp[j], dp[j-h] + score[idx])

    return max(dp)

if __name__ == "__main__":
    n = int(input())
    health = list(map(int, input().split()))
    happiness = list(map(int, input().split()))

    print(solve(health, happiness))