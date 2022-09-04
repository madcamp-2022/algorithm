import sys
input = sys.stdin.readline

def check_b_num(lecs, target):
    b_num = 1
    limit = 0    
    
    for val in lecs:
        limit += val
        if limit > target:
            b_num += 1
            limit = val
    
    return b_num

def binary_search(start, end, m, lecs):
    result = 0
    
    while start <= end:
        mid = (start + end) // 2

        if check_b_num(lecs, mid) <= m:
            result = mid
            end = mid - 1
        else:
            start = mid + 1
    
    print(result)

def solve(n, m, lecs):
    start, end = max(lecs), sum(lecs)
    binary_search(start, end, m, lecs)    

if __name__ == "__main__":
    n, m = map(int, input().split())
    lectures = list(map(int, input().split()))
    solve(n, m, lectures)