from sys import stdin

n,m = map(int, stdin.readline().split())
num_list = list(map(int, stdin.readline().split()))

for i in range(0, m):
    num_list.sort()
    l,r,x = map(int, stdin.readline().split())
    for j in range(l-1,r):
        num_list[j] = num_list[j] + x

num_list.sort()
for i in range(len(num_list)):
    print(num_list[i], end=" ")