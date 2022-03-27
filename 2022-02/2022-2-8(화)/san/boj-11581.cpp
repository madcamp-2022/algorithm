#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<vector<int>> adj;
vector<bool> visited, finished;
bool has_cycle = false;

// dfs
void check_cycle(int from) {
    visited[from] = true;

    int to;
    for (int i = 0; i < adj[from].size(); ++i) {
        to = adj[from][i];
        if (!visited[to]) {
            check_cycle(to);
        } else if (!finished[to]) {
            has_cycle = true;
        }
    }
    finished[from] = true;
}

int main() {
    fastio;

    int N, M, C;

    cin >> N;
    adj = vector<vector<int>>(N + 1);
    visited = vector<bool>(N + 1, false);
    finished = vector<bool>(N + 1, false);

    for (int i = 1; i < N; ++i) {
        cin >> M;
        while (M--) {
            cin >> C;
            adj[i].push_back(C);
        }
    }

    check_cycle(1);
    cout << (has_cycle ? "CYCLE" : "NO CYCLE") << endl;
}
