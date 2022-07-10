from itertools import combinations
import sys

input = sys.stdin.readline
n, l, r, x = map(int, input().split())

questions = list(map(int, input().split()))
questions.sort()

answer = []
cnt = 2
while True:
    if cnt == n+1:
        break

    if sum(questions[:cnt]) > r:
        break

    for val in list(combinations(questions, cnt)):
        if l <= sum(val) <= r and max(val)-min(val) >= x:
            answer.append(val)
    
    cnt += 1

print(len(answer))