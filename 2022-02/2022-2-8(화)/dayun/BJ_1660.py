def init():
    sum = 0
    tmp = 1
    iter = 2

    while True:
        sum += tmp
        if (sum > 300000): 
            break
        answer[sum] = 1
        bomb.append(sum)
        tmp += iter
        iter += 1

def calc():
    for i in range(1, N+1):
        answer[i] = inf
        for j in range(0, len(bomb)):
            if (i - bomb[j] < 0):
                break
            answer[i] = min(answer[i], answer[i - bomb[j]] + 1)

inf = 999999
N = int(input())
bomb = []
answer = [inf] * 300001
answer[0] = 0

calc()
print(answer[N])
# 뭐가 문제임?