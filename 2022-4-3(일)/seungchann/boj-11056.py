import sys
input = sys.stdin.readline

string_one = input().rstrip()
string_two = input().rstrip()

dp = [[0] * (len(string_two)+1) for _ in range(len(string_one)+1)]

for i in range(1, len(string_one)+1):
    for j in range(1, len(string_two)+1):
        if string_one[i-1] == string_two[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])

print(len(string_one) + len(string_two) - dp[-1][-1])
