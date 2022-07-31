from itertools import combinations
import sys
input = sys.stdin.readline

points = []
n = int(input())

for _ in range(n):
    x, y = map(int, input().split())
    points.append((x, y))

result = 0
for val in list(combinations(points, 3)):
    x_1, y_1 = val[0]
    x_2, y_2 = val[1]
    x_3, y_3 = val[2]

    s = ((1/2) * abs(((x_1*y_2) + (x_2*y_3) + (x_3*y_1)) - ((x_2*y_1) + (x_3*y_2) + (x_1*y_3))))
    result = max(s, result)

print(result)