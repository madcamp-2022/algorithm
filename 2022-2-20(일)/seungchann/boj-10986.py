import sys
from itertools import combinations
input = sys.stdin.readline

n, m = map(int, input().split())
array = [0]
array += list(map(int, input().split()))
num_list = [0] * 1000

for i in range(len(array)):
    if i != 0:
        array[i] = (array[i-1] + array[i]) % m
    
    num_list[array[i]] += 1

result = 0
for i in num_list:
    result += len(list(combinations(range(i), 2)))

print(result)