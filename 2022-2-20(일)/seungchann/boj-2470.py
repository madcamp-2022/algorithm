import sys
input = sys.stdin.readline

_ = int(input())
array = list(map(int, input().split()))
abs_array = []

for i in array:
    if i>0:
        abs_array.append((i, 1))
    else:
        abs_array.append((abs(i), -1))

abs_array.sort(key= lambda x: x[0])

min_val = 999999999999
result = [0] * 2
for idx in range(len(abs_array)-1):
    a = abs_array[idx][0] * abs_array[idx][1]
    b = abs_array[idx+1][0] * abs_array[idx+1][1]
    temp_val = abs(a+b)
    if temp_val < min_val:
        min_val = temp_val
        result[0] = a
        result[1] = b

result.sort()

for i in result:
    print(i, end=' ')