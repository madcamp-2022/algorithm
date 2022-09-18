import sys
input = sys.stdin.readline

def check_cur(i):
    global length
    return i if i < length else (i-length)

def solve(belt, k, c):
    global length
    idx = 0
    temp = set()
    result = 0

    while True:
        if (idx == length) or (result == k+1):
            break

        for cnt in range(k):
            cur = belt[check_cur(idx + cnt)]
            temp.add(cur)

            if cnt == k-1:
                result = max(result, (len(temp)+1 if c not in temp else len(temp)))
            
        idx += 1
        temp = set()

    return result

if __name__ == "__main__":
    N, _, K, C = map(int, input().split())
    array = []
    for _ in range(N):
        array.append(int(input()))
    
    length = len(array)
    print(solve(array, K, C))
