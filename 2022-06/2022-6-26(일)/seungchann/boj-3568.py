import sys
input = sys.stdin.readline

command = input().rstrip()

is_initial = True
shared = ""
temp = ""
name = ""
variable_group = []

for ch in command:
    if ch == " ":
        if is_initial:
            shared = temp
            temp = ""
            is_initial = False
        continue
    
    if ch == "," or ch == ";":
        temp = temp[::-1] + " " + name
        
        variable_group.append(temp)
        temp = ""
        name = ""
        continue

    if not is_initial:
        if 65 <= ord(ch) <= 90 or 97 <= ord(ch) <= 122:
            name += ch
            continue

        if ch == "[":
            ch = "]"
        elif ch == "]":
            ch = "["
    
    temp += ch

for var in variable_group:
    print(shared + var + ";")