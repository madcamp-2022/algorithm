from operator import ne
from os import popen


n = int(input())
pos_ints = []
neg_ints = []
answer = 0

for i in range(0, n):
    my_input = int(input())
    if my_input <= 0:
        neg_ints.append(my_input)
    elif my_input != 1:
        pos_ints.append(my_input)
    else:
        answer += 1

pos_ints.sort(reverse=True)
neg_ints.sort()

if len(pos_ints) == 1:
    answer += pos_ints[0]
elif len(pos_ints) > 1:
    for i in range(0, int(len(pos_ints)/2)):
        answer += pos_ints[i*2] * pos_ints[i*2+1]
    if len(pos_ints) % 2 != 0:
        answer += pos_ints[len(pos_ints) - 1]

if len(neg_ints) == 1:
    answer += neg_ints[0]
elif len(neg_ints) > 1:
    for i in range(0, int(len(neg_ints) / 2)):
        answer += neg_ints[i*2] * neg_ints[i*2+1]

    if (len(neg_ints) % 2 != 0):
        answer += neg_ints[len(neg_ints) - 1]

print(answer)