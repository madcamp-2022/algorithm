import sys

input = sys.stdin.readline

n = int(input())
nums = [[], []]
ones = 0
zero = False
for _ in range(n):
    num = int(input())
    if nums == 0:
        zero = True
        continue
    if num == 1:
        ones += 1
        continue
    nums[bool(num > 0)].append(num)

nums[0].sort()
nums[1].sort(reverse=True)

ans = 0
for i in range(len(nums[0]) // 2):
    ans += nums[0][2 * i] * nums[0][2 * i + 1]
for j in range(len(nums[1]) // 2):
    ans += nums[1][2 * j] * nums[1][2 * j + 1]
if len(nums[0]) % 2 == 1:
    if not zero:
        ans += nums[0][-1]
if len(nums[1]) % 2 == 1:
    ans += nums[1][-1]
print(ans + ones)
