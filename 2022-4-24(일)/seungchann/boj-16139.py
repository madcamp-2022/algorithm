import sys
input = sys.stdin.readline

string = input().rstrip()
n = int(input())
p_sum = [[0 for _ in range(26)] for _ in range(len(string))]

for idx, ch in enumerate(string):
    if idx == 0:
        p_sum[idx][ord(ch)-97] = 1
    else:
        for i, _ in enumerate(p_sum[idx]):
            if i != ord(ch)-97:
                p_sum[idx][i] = p_sum[idx-1][i]
            else:
                p_sum[idx][i] = p_sum[idx-1][i] + 1

for _ in range(n):
    ch, l, r = input().rstrip().split()
    l, r = int(l), int(r)
    if not l == 0:
        sys.stdout.write(str(p_sum[r][ord(ch)-97] - p_sum[l-1][ord(ch)-97])+"\n")
    else:
        sys.stdout.write(str(p_sum[r][ord(ch)-97])+"\n") 