import sys
input = sys.stdin.readline

if __name__ == "__main__":
    n = int(input())
    answer = 1
    gap = 1

    for i in range(2, n+1):
        if i%6 == 0:
            gap += 1
        answer += gap
        if i%6 == 1:
            answer -= 1
    
    print(answer)