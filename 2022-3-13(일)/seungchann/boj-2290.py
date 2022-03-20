import sys
input = sys.stdin.readline

s, n = map(int, input().split())

answer_list = [[] for _ in range(2*s+3)]

def number(digit):
    global answer_list, s
    for row in range(len(answer_list)):
        if (row == 0):
            if digit in [1, 4]:
                answer_list[row].append(' '*(s+3)) 
            else:
                answer_list[row].append(' ')
                answer_list[row].append('-'*s)
                answer_list[row].append(' ')
                answer_list[row].append(' ')
        
        elif row > 0 and row < s+1:
            if digit in [1, 2, 3, 7]:
                answer_list[row].append(' '*(s+1))
                answer_list[row].append('|') 
                answer_list[row].append(' ') 
            elif digit in [5, 6]:
                answer_list[row].append('|')
                answer_list[row].append(' '*(s+2))
            else:
                answer_list[row].append('|')
                answer_list[row].append(' '*s)
                answer_list[row].append('|') 
                answer_list[row].append(' ') 

        elif row == s+1:
            if digit in [0, 1, 7]:
                answer_list[row].append(' '*(s+3))
            else :
                answer_list[row].append(' ')
                answer_list[row].append('-'*s)
                answer_list[row].append(' ')
                answer_list[row].append(' ')
        
        elif row > s+1 and row < len(answer_list)-1:
            if digit == 2:
                answer_list[row].append('|')
                answer_list[row].append(' '*(s+2))
            elif digit in [1, 3, 4, 5, 7, 9]:
                answer_list[row].append(' '*(s+1))
                answer_list[row].append('|') 
                answer_list[row].append(' ') 
            else:
                answer_list[row].append('|')
                answer_list[row].append(' '*s)
                answer_list[row].append('|') 
                answer_list[row].append(' ') 
        else:
            if digit in [2, 3, 5, 6, 8, 9, 0]:
                answer_list[row].append(' ')
                answer_list[row].append('-'*s)
                answer_list[row].append(' ')
                answer_list[row].append(' ')
            elif digit in [1, 4, 7]:
                answer_list[row].append(' '*(s+3))
            
for num in str(n):
    number(int(num))

for ch in answer_list:
    print(''.join(ch))