import sys
input = sys.stdin.readline

n, c, w = map(int, input().split())
trees = [int(input().rstrip()) for _ in range(n)]

result = 0
for height in range(1, max(trees)+1):
    total = 0
    for tree in trees:
        tree_val = 0 
        if tree >= height:
            tree_val += ((tree // height) * height * w)
            if tree % height == 0:
                tree_val -= (((tree // height)-1) * c)
            else:
                tree_val -= ((tree // height) * c)
            
            # 잘라서 파는 것이 손해일 경우, 자르지 않음
            if tree_val > 0:
                total += tree_val
        
        result = max(result, total)

if n == 1:
    result = trees[0] * w

print(result)