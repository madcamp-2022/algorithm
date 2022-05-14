from itertools import combinations
import sys
input = sys.stdin.readline

cards = input().rstrip().split(',')
tier_one = []
tier_two = []
tier_three = []

def front_to_int(ch):
    if 97<=ord(ch)<=102:
        return ord(ch)-87
    else:
        return int(ch)

for card_one, card_two in list(combinations(cards, 2)):
    temp = card_one + card_two
    fir = front_to_int(temp[0])
    sec = front_to_int(temp[2])

    # 하위 서열 정리를 위한 정보 수집
    is_same_color = (temp[1] == temp[3])
    max_num = 0 
    min_num = 0
    is_black_max_num = False
    
    if fir>sec:
        max_num = fir
        min_num = sec
        is_black_max_num = (temp[1] == 'b')
    else:
        max_num = sec
        min_num = fir
        is_black_max_num = (temp[3] == 'b')
    
    # 상위 서열 정리
    if abs(fir-sec) == 1:
        tier_one.append((temp, is_same_color, max_num, min_num, is_black_max_num))
        continue
    else:
        if (fir == 1 and sec == 15) or (fir == 15 and sec == 1):
            tier_one.append((temp, is_same_color, max_num, min_num, is_black_max_num))
            continue
    if abs(fir-sec) == 0:
        tier_two.append((temp, is_same_color, max_num, min_num, is_black_max_num))
    else:
        tier_three.append((temp, is_same_color, max_num, min_num, is_black_max_num))

tier_one.sort(key= lambda x: (-x[1], -x[2], -x[3], -x[4]))
tier_two.sort(key= lambda x: (-x[1], -x[2], -x[3], -x[4]))
tier_three.sort(key= lambda x: (-x[1], -x[2], -x[3], -x[4]))

result = tier_one + tier_two + tier_three

for string, _, _, _, _ in result:
    print(string)