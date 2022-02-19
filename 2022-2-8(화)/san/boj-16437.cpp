#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<int> adj;
vector<long long> cost;
vector<bool> visited;
vector<int> order;

void dfs(int from) {
    visited[from] = true;

    int to = adj[from];
    if (to && !visited[to]) {
        dfs(to);
    }
    order.push_back(from);
}

void topological_sort() {
    order.clear();

    for (int i = 1; i < adj.size(); i++)
        if (!visited[i])
            dfs(i);

    reverse(order.begin(), order.end());
}

int main() {
    fastio;

    int N, p;
    long long a;
    char t;

    cin >> N;

    // The route is unique => there is only one outgoing edge
    // * vector<vector<int>> causes memory exceed
    adj = vector<int>(N + 1, 0);
    cost = vector<long long>(N + 1, 0);
    visited = vector<bool>(N + 1, false);

    for (int from = 1; from <= N - 1; from++) {
        cin >> t >> a >> p;
        cost[from + 1] = (t == 'W') ? -a : a;
        adj[from + 1] = p;
    }

    topological_sort();

    vector<long> gathered(N + 1, 0);
    for (auto from : order) {
        // gather + cost < 0 -> No esacpe from that island
        gathered[adj[from]] += max(gathered[from] + cost[from], (long long)0);
    }

    cout << gathered[1] << endl;
}
