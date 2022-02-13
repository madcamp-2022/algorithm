def f(N):
	dp = [300000] * (N + 1)
	dp[0] = 0

	for n in arr:
		for j in range(n, N + 1):
			dp[j] = min(dp[j - n] + 1, dp[j])

	print(dp[-1])



N = int(input())

arr = [1]
cnt = 1
while arr[-1] <= int(N / 2):
	cnt += 1
	arr.append(arr[-1] + cnt)

for i in range(1, len(arr)):
	arr[i] += arr[i - 1]
	if arr[i] > N:
		arr = arr[:i]
		break

f(N)
