import sys

input = sys.stdin.readline

x = int(input())
n = int(input())
if x == 1:
    print(8 * n)
elif x == 5:
    print(4 + 8 * n)
elif x == 3:
    print(2 + 4 * n)
elif x == 2:
    if n % 2 == 0:
        print(1 + 8 * (n // 2))
    else:
        print(1 + 8 * (n // 2) + 6)
elif x == 4:
    if n % 2 == 0:
        print(3 + 8 * (n // 2))
    else:
        print(3 + 8 * (n // 2) + 2)
