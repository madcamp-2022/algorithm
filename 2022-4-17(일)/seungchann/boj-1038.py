from itertools import combinations
import sys
input = sys.stdin.readline

N = int(input().rstrip())
num_sets = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
answer_list = []

for i in range(1, 11):
    answer_list += list(combinations(num_sets, i))

for idx, ans in enumerate(answer_list):
    temp = ''
    for ch in reversed(ans):
        temp += str(ch)
    answer_list[idx] = int(temp)
answer_list.sort()

if N >= len(answer_list):
    print("-1")
else:
    print(answer_list[N])