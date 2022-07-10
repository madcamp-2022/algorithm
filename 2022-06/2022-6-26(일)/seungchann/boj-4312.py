import sys
input = sys.stdin.readline

while True:
    n = int(input())
    if n == 0:
        break
    print("{", end=" ")
    n -= 1
    i = 0
    while n != 0:
        if n % 2:
            if n // 2:
                print(3**i, end=", ")
            else:
                print(3**i, end= " ")
        n //= 2
        i += 1
    print("}")