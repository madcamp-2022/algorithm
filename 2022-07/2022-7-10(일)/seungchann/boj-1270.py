import sys
input = sys.stdin.readline

n = int(input())

for _ in range(n):
    temp = list(map(int, input().split()))

    # 번호, 개수
    head = [0, 0]
    num_dict = {}

    for idx, num in enumerate(temp):
        if idx == 0:
            continue

        if num in num_dict:
            num_dict[num] += 1
        else:
            num_dict[num] = 1
        
        if num_dict[num] >= head[1]:
            head[0] = num
            head[1] = num_dict[num]
            
    if head[1] < int(temp[0]/2)+1:
        sys.stdout.write("SYJKGW\n")
    else:
        sys.stdout.write(str(head[0])+"\n")