N = int(input())

answer = 0
for i in range(1, N+1):
    answer += i * int(N / i)

print(answer)