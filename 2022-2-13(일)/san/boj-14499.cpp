#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
int dice[6] = {0, 0, 0, 0, 0, 0}; // x+, x-, y+, y-, z+, z-

vector<int> split(string str, char delim) {
    vector<int> v;

    for (auto &ch : str) {
        if (ch != delim) {
            v.push_back(ch - '0');
        }
    }
    return v;
}

void swap(int a, int b) {
    int tmp = dice[a];
    dice[a] = dice[b];
    dice[b] = tmp;
}

void rotate(int r) {
    if (r == 1) {
        swap(2, 5);
        swap(3, 4);
        swap(2, 3);
    } else if (r == 2) {
        swap(2, 4);
        swap(3, 5);
        swap(2, 3);
    } else if (r == 3) {
        swap(0, 4);
        swap(1, 5);
        swap(0, 1);
    } else if (r == 4) {
        swap(0, 5);
        swap(1, 4);
        swap(0, 1);
    }
}

int main() {
    int N, M, x, y, K;
    vector<vector<int>> map;

    cin >> N >> M >> x >> y >> K;
    cin.ignore(); // flush last "\n"
    string input;
    for (int i = 0; i < N; i++) {
        getline(cin, input);
        map.push_back(split(input, ' '));
    }

    getline(cin, input);
    for (auto i : split(input, ' ')) {
        if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= N ||
            y + dy[i] >= M) {
            continue;
        }

        x += dx[i];
        y += dy[i];
        rotate(i);

        if (map[x][y] > 0) {
            // map >> dice bottom; map << 0
            dice[5] = map[x][y];
            map[x][y] = 0;
        } else {
            // dice bottom >> map
            map[x][y] = dice[5];
        }

        cout << dice[4] << "\n";
    }
}
