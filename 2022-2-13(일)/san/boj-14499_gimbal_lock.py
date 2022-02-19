import numpy as np

dx = (0, 0, 0, -1, 1)
dy = (0, 1, -1, 0, 0)
R = (
    np.array([[1, 0, 0], [0, 0, -1], [0, 1, 0]]),
    np.array([[1, 0, 0], [0, 0, 1], [0, -1, 0]]),
    np.array([[0, 0, 1], [0, 1, 0], [-1, 0, 0]]),
    np.array([[0, 0, -1], [0, 1, 0], [1, 0, 0]]),
)
dice_normal = [
    np.array([[1, 0, 0]]),
    np.array([[0, 1, 0]]),
    np.array([[0, 0, 1]]),
    np.array([[0, 0, -1]]),
    np.array([[0, -1, 0]]),
    np.array([[-1, 0, 0]]),
]


def dice_index(normal):
    for i in range(0, 6):
        if np.array_equal(normal, dice_normal[i]):
            return i + 1
    return -1


N, M, x, y, K = map(int, input().split())
m = []
dice = [0] * 6
dice_rotation = np.array([[1, 0, 0], [0, 1, 0], [0, 0, 1]])

for i in range(0, N):
    m.append(list(map(int, input().split())))

for i in list(map(int, input().split())):
    if x + dx[i] < 0 or y + dy[i] < 0 or x + dx[i] >= N or y + dy[i] >= M:
        continue

    x += dx[i]
    y += dy[i]

    # ! This product eventually causes gimbal-lock
    dice_rotation = R[i - 1] @ dice_rotation  # Euiler-angle rotate

    bottom = dice_index((dice_rotation @ np.array([[0, 0, -1]]).T).T)

    if m[x][y] != 0:
        # map >> dice bottom
        dice[bottom - 1] = m[x][y]
    else:
        # dice bottom >> map
        m[x][y] = dice[bottom - 1]

    top = dice_index((dice_rotation @ np.array([[0, 0, 1]]).T).T)
    print(dice[top - 1])
