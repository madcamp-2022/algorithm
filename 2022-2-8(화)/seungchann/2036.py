arrayNum = int(input())
hasZero = False
posArray = []
negArray = []
tempNum = -1
flag = False
total = 0

n = 0

while(n<arrayNum):
    inputNum = int(input())
    if (inputNum == 1):
        total = total + 1
    elif (inputNum == 0):
        hasZero = True
    elif (inputNum > 0):
        posArray.append(inputNum)
    else:
        negArray.append(inputNum)
    n = n+1

posArray.sort(reverse=True)
negArray.sort()

for i in posArray:
    if flag == False:
        tempNum = i
        flag = True
    else:
        total = total + (tempNum * i)
        flag = False

if flag == True:
    total = total + tempNum

flag = 0

for i in negArray:
    if (flag == 0):
        tempNum = i
        flag = True
    else:
        total = total + (tempNum * i)
        flag = False

if (flag == True):
    if (hasZero == False):
        total = total + tempNum

print(total)