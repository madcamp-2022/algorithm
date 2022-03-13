import sys
input = sys.stdin.readline

def is_prime(n):
    for i in range(2, int(n**0.5)+1):
        if n%i == 0:
            return False
    return True

n = int(input())
d = [0] * (n+1)
prime = []

for i in range(2, n+1):
    if is_prime(i):
        prime.append(i)
    
d[0] = 1
for p in prime:
    for i in range(p, n+1):
        d[i] = (d[i] + d[i-p]) % 123456789

print(d[n])