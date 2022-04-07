import sys
input = sys.stdin.readline

ax_1, ay_1, ax_2, ay_2 = map(int, input().split())
bx_1, by_1, bx_2, by_2 = map(int, input().split())

ax_len = ax_2 - ax_1
bx_len = bx_2 - bx_1
ay_len = ay_2 - ay_1
by_len = by_2 - by_1

max_diff_x = max(bx_2 - ax_1, ax_2 - bx_1)
max_diff_y = max(by_2 - ay_1, ay_2 - by_1)

if ax_1 == bx_2 or bx_1 == ax_2:
    if ay_1 == by_2 or ay_2 == by_1:
        print("POINT")
    elif ay_len + by_len > max_diff_y:
        print("LINE")
    else:
        print("NULL")

elif ax_len + bx_len > max_diff_x:
    if ay_1 == by_2 or ay_2 == by_1:
        print("LINE")
    elif ay_len + by_len > max_diff_y:
        print("FACE")
    else:
        print("NULL")
else:
    print("NULL")
