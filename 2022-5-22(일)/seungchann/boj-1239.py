import sys
input = sys.stdin.readline

_ = input()
array = list(map(int, input().split()))
array.sort()

if max(array) > 50:
    print(0)

elif max(array) == 50:
    print(1)

else:
    for i in range(1, 49):
        

