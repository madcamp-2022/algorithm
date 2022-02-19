array_num = int(input())
has_zero = False
pos_array = []
neg_array = []
temp_num = 0
flag = False
total = 0

n = 0

while(n<array_num):
    input_num = int(input())
    if (input_num == 1):
        total = total + 1
    elif (input_num == 0):
        has_zero = True
    elif (input_num > 0):
        pos_array.append(input_num)
    else:
        neg_array.append(input_num)
    n = n+1

pos_array.sort(reverse=True)
neg_array.sort()

for i in pos_array:
    if flag == False:
        temp_num = i
        flag = True
    else:
        total = total + (temp_num * i)
        flag = False

if flag == True:
    total = total + temp_num

flag = False

for i in neg_array:
    if (flag == False):
        temp_num = i
        flag = True
    else:
        total = total + (temp_num * i)
        flag = False

if (flag == True):
    if (has_zero == False):
        total = total + temp_num

print(total)