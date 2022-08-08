import sys
input = sys.stdin.readline

n = int(input())
timeline = []

for _ in range(n):
    time, due = map(int, input().split())
    timeline.append((time, due))

timeline.sort(key= lambda x: (-x[1], x[0]))
start_time = 10e9

for idx, (time, due) in enumerate(timeline):
    if idx == 0:
        start_time = due - time
        continue

    if start_time > due:
        start_time = due - time
    else:
        start_time -= time

print(start_time if start_time >= 0 else -1)