from itertools import product
import sys
input = sys.stdin.readline

n = int(input())
options = [' ', '+', '-']

def calc(eq):
    temp = eq.replace(' ', '')
    if eval(temp) == 0:
        print(eq)

for _ in range(n):
    num = int(input())
    opers_comb = list(product(options, repeat=num-1))
    
    for opers in opers_comb:
        cnt = 1
        string = str(cnt)
        
        for op in opers:
            cnt += 1
            string += (op + str(cnt))
        
        calc(string)
            
    print()