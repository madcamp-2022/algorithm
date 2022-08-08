import sys
input = sys.stdin.readline

l, r = map(str, input().split())

result = 10e9
if len(l) == len(r):
    for num in range(int(l), int(r)+1):
        result = min(result, str(num).count('8'))
        if result <= 0:
            break

    print(result)

else:
    print(0)