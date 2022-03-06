#include <bits/stdc++.h>
using namespace std;

typedef struct _coord { int x, y; } Coord;
typedef struct _RCS{ Coord top, bottom; } RCS;

typedef vector<vector<int> > Matrix;

void rotateMatrix(Matrix &matrix, Coord top, Coord bottom) {
    while (top.x != bottom.x && top.y != bottom.y) {
        vector<int> nums;
        int x = top.x; int y = top.y;
        while (y < bottom.y) nums.push_back(matrix[x][y++]);
        while (x < bottom.x) nums.push_back(matrix[x++][y]);
        while (y > top.y) nums.push_back(matrix[x][y--]);
        while (x > top.x) nums.push_back(matrix[x--][y]);

        nums.insert(nums.begin(), nums.back());
        nums.pop_back();

        x = top.x; y = top.y; int idx = 0;
        while (y < bottom.y) matrix[x][y++] = nums[idx++];
        while (x < bottom.x) matrix[x++][y] = nums[idx++];
        while (y > top.y) matrix[x][y--] = nums[idx++];
        while (x > top.x) matrix[x--][y] = nums[idx++];

        top.x++; top.y++;
        bottom.x--; bottom.y--;
    }
}

int calc(Matrix &matrix, vector<RCS> &rcs, vector<bool> visited, int cnt) {
    int result = INT_MAX;
    if (cnt == visited.size()) {
        for (auto &list: matrix) {
            result = min(result, accumulate(list.begin(), list.end(), 0));
        }
        return result;
    }
    else {
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                Matrix nextMatrix(matrix.size(), vector<int>(matrix[0].size()));
                copy(matrix.begin(), matrix.end(), nextMatrix.begin());
                rotateMatrix(nextMatrix, rcs[i].top, rcs[i].bottom);
                result = min(result, calc(nextMatrix, rcs, visited, cnt + 1));
                visited[i] = false;
            }
        }
    }
    return result;
}

void ans(Matrix matrix, vector<RCS> &rcs) {
    int result = INT_MAX;
    vector<bool> visited(rcs.size(), false);
    result = min(result, calc(matrix, rcs, visited, 0));
    cout << result;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;
    Matrix matrix(N, vector<int>(M));
    vector<RCS> rcs(K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < K; i++) {
        int r, c, s;
        cin >> r >> c >> s;
        rcs[i].top.x = r - s - 1;
        rcs[i].top.y = c - s - 1;
        rcs[i].bottom.x = r + s - 1;
        rcs[i].bottom.y = c + s - 1;
    }
    ans(matrix, rcs);
    return 0;
}