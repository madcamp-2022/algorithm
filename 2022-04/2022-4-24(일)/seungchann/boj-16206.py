import sys
input = sys.stdin.readline

n, m = map(int, input().split())
array = list(map(int, input().split()))
array.sort()
remaining = []
result = 0
is_end = False

for len in array:
    if len == 10:
        result += int(len / 10)
    elif len % 10 == 0 and len != 10:
        cakes = int(len / 10)
        result += cakes
        m -= (cakes-1)
    elif len > 10:
        remaining.append(len)
    
    if m < 0:
        result += (m-1)
        is_end = True
        break

if not is_end:
    for len in remaining:
        cakes = int(len / 10)
        result += cakes
        m -= (cakes)

        if m <= 0:
            result += m
            break

print(result)
