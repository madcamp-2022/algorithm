import sys
input = sys.stdin.readline

l, r = map(int, input().split())
answer = [0, 0]

cur = [l, r]
while True:
    if cur == [1, 1]:
        break

    if cur[0] > cur[1]:
        cur[0] = cur[0] - cur[1]
        answer[0] += 1
        continue

    else:
        cur[1] = cur[1] - cur[0]
        answer[1] += 1
        continue

answer = map(str, answer)
print(' '.join(answer))