import sys
from math import lcm, gcd
input = sys.stdin.readline

_ = input()
c_list = list(map(int, input().split()))
h_list = list(map(int, input().split()))
possible_angles = set(c_list)
answer_list = []

# 0 ~ 360 안의 각도로 만들기 위한 함수
def angle(ang):
    if ang < 0:
        while(ang < 0):
            ang += 360
    if ang > 360:
        ang %= 360
    return ang

while True:
    a = c_list.pop()
    
    if len(c_list) == 0:
        break
    else:
        for i in c_list:
            possible_angles.update([angle(a+i), angle(a-i)])

# for i in h_list:
#     is_answer = False
#     i = angle(i)
#     for j in list(possible_angles):
    

print(angle(lcm(100, 60)), angle(gcd(100, 60)))


