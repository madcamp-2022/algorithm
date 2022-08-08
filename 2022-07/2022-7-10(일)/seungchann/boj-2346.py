import sys
input = sys.stdin.readline

n = int(input())
balloon = list(map(int, input().split()))
popped = [False for _ in range(n)]
result = []

cur = 0
popped[0] = True
result.append(str(cur+1))

while False in popped:
    paper = balloon[cur]    
    cnt = 0
    if paper > 0:
        while cnt != paper:
            cur += 1
            if cur > n-1:
                cur = 0
            
            if popped[cur] == False:
                cnt += 1
    else:
        while cnt != paper:
            cur -= 1
            if cur < 0:
                cur = n-1
            
            if popped[cur] == False:
                cnt -= 1
    
    popped[cur] = True
    result.append(str(cur+1))

print(' '.join(result))