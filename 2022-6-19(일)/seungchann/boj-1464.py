import sys
input = sys.stdin.readline

string = list(input().rstrip())
result = string[0]

for idx, ch in enumerate(string):
    if idx == 0:
        continue
    if result[idx-1] < ch:
        result = ch + result
    else:
        result += ch

result = result[::-1]

print(result)