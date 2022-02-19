#include <iostream>
#include <stack>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<int> adj[3001];
int color[3001] = {0};
int parent[3001] = {0};
bool cycle[3001] = {false};

void mark_cycle(int u, int p) {
    if (color[u] == 2)
        return;

    // re-visited before completely visited -> cycle detected
    if (color[u] == 1) {
        int cur = p;
        cycle[cur] = true;

        while (cur != u) {
            cur = parent[cur];
            cycle[cur] = true;
        }
        return;
    }

    parent[u] = p;

    // partially visited
    color[u] = 1;

    for (auto v : adj[u]) {
        if (v == parent[u])
            continue;
        mark_cycle(v, u);
    }

    // completely visited
    color[u] = 2;
}

int get_distance(int v, int N) {
    vector<bool> discovered(N + 1, false);
    stack<pair<int, int>> s;
    s.push({v, 0});

    int d;
    while (!s.empty()) {
        v = s.top().first;
        d = s.top().second;
        s.pop();

        if (discovered[v]) {
            continue;
        }

        discovered[v] = true;
        if (cycle[v]) {
            return d;
        }

        for (auto it = adj[v].rbegin(); it != adj[v].rend(); ++it) {
            if (!discovered[*it]) {
                s.push({*it, d + 1});
            }
        }
    }

    return -1;
}

int main() {
    fastio;

    int N, f, t;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> f >> t;
        adj[f].push_back(t);
        adj[t].push_back(f);
    }

    // Find all cycles
    mark_cycle(1, 0);

    // Get distances
    for (int i = 1; i <= N; ++i) {
        cout << get_distance(i, N) << " ";
    }
}
