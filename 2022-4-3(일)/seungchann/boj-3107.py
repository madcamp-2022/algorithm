import sys
input = sys.stdin.readline

string = input().rstrip().split(":")

def put_zeros(gr):
    result = gr
    for _ in range(4-len(gr)):
        result = '0'+result
    return result

if string[0] == '':
    if len(string) > 8:
        string = string[1:]
    else:
        string[0] = '0000'
elif string[-1] == '':
    if len(string) > 8:
        string = string[:-1]
    else:
        string[-1] = '0000'

for idx, group in enumerate(string):
    if group == '':
        string[idx] = '0000'
        while True:
            if len(string) == 8:
                break
            else:
                string.insert(idx, '0000')
        break

for idx, group in enumerate(string):
    string[idx] = put_zeros(group)

print(':'.join(string))
