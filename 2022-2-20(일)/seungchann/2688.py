import sys
input = sys.stdin.readline

n = int(input())
array = [int(input().rstrip()) for _ in range(n)]
d = [0] * 65

def sum_n(arr, idx):
    result = 0
    for i in range(idx+1):
        result += arr[i]
    return result
        
d[0] = 0
d[1] = 10

sum_list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
for i in range(2, 65):
    d[i] = sum(sum_list)
    sum_list_copy = sum_list[:]
    for j in range(len(sum_list)):
        sum_list[j] = sum_n(sum_list_copy, j)

for i in array:
    print(d[i])