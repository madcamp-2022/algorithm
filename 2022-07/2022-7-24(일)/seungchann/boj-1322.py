import sys
input = sys.stdin.readline

x, k = map(int, input().split())

binary_x = str(bin(x))[2:]
# ex) 1010 -> 1(3) 0(2) 1(1) 0(0) (idx)
binary_x = binary_x[::-1]

# k의 경우 뒤에서 부터 pop 해서 사용, pop(-1)
binary_k = list(str(bin(k))[2:])

result = ""
idx = 0
while True:
    if len(binary_k) == 0:
        break

    if idx >= len(binary_x):
        result = (''.join(binary_k) + result)
        break
    
    if binary_x[idx] == "1":
        result = ("0" + result)
        idx += 1
        continue
    
    else:
        result = (binary_k.pop(-1) + result)
        idx += 1
        continue

print(int(result, 2))