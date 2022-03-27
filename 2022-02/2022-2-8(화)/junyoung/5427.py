import copy
import sys

def ans(n, m, matrix, exit_list):
	human_pos = []
	fire_pos = []
	fire_matrix = [matrix.copy()]
	human_matrix = matrix

	for i in range(n):
		for j in range(m):
			if matrix[i][j] == '@':
				human_pos.append([i, j, 0])
			if matrix[i][j] == '*':
				fire_pos.append([i, j])

	
	while len(fire_pos):
		new_matrix = copy.deepcopy(fire_matrix[-1])
		new_pos = []
		for x, y in fire_pos:
			try:
				for i in range(-1, 2):
					for j in range(-1, 2):
						if (i * j == 0) and not (i == 0 and j == 0): 
							if new_matrix[x + i][y + j] in ['.', '@']:
								new_pos.append([x + i, y + j])
								new_matrix[x + i][y + j] = '*'
			except:
				pass

		check_exit = []
		for i in range(n):
			for j in range(m):
				if i == 0 or j == 0 or i == n - 1 or j == m - 1:
					if matrix[i][j] in ['.', '@']:
						check_exit.append([i, j])
		if len(check_exit) == 0:
			break
		fire_pos = new_pos
		fire_matrix.append(new_matrix)


	result = 1001 * 1001
	minimum_time = 1001 * 1001
	maximum_time = len(fire_matrix)
	x, y, cnt = human_pos[0]
	for exit in exit_list:
		minimum_time = min(minimum_time, (abs(exit[0] - x) + abs(exit[1] - y)) + 1)

	while len(human_pos):
		x, y, cnt = human_pos[0]
		human_pos.pop(0)
		if cnt == maximum_time:
			continue
		if x == 0 or y == 0 or x == n - 1 or y == m - 1:
			result = min(cnt + 1, result)
			if result == minimum_time:
				break
		try:
			for i in range(-1, 2):
				for j in range(-1, 2):
					if (i * j == 0) and not (i == 0 and j == 0):
						if fire_matrix[cnt + 1][x + i][y + j] == '.':
							human_pos.append([x + i, y + j, cnt + 1])
		except:
			pass

	if result == 1001 * 1001:
		print('IMPOSSIBLE')
	else:
		print(result)

def f(n, m):
	matrix = []
	exit_list = []
	for _ in range(n):
		matrix.append(list(sys.stdin.readline()))

	for i in range(n):
		for j in range(m):
			if i == 0 or j == 0 or i == n - 1 or j == m - 1:
				if matrix[i][j] in ['.', '@']:
					exit_list.append([i, j])

	if len(exit_list) > 0:
		ans(n, m, matrix, exit_list)
	else:
		print('IMPOSSIBLE')

N = int(input())

for _ in range(N):
	m, n = map(int, sys.stdin.readline().split())
	f(n, m)