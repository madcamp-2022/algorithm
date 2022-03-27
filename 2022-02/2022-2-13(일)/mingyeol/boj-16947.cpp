#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> adj[3001];
bool passed[3001], incycle[3001], checked;
int from_node[3001], ans[3001], back_node, origin_node;

void backtr_cycle(int node) {
    incycle[node] = true;
    if(node == origin_node)
        return;
    backtr_cycle(from_node[node]);
}

void dfs(int from, int node) {
    // printf("test: %d %d\n", from, node);
    passed[node] = true;
    from_node[node] = from;
    for(int i : adj[node]) {
        if(!passed[i]) {
            dfs(node, i);
        } else if(from != i && !checked) {
            back_node = node;
            origin_node = i;
            checked = true;
        }
    }
}

void dfs_dist(int node, int dist) {
    passed[node] = true;
    ans[node] = dist;
    for(int i : adj[node]) {
        if(!passed[i]) {
            int new_dist = incycle[i] ? dist : dist + 1;
            dfs_dist(i, new_dist);
        }
    }
}

int main(void) {
    int n, a, b;

    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 1);
    backtr_cycle(back_node);
    for(int i=1; i<=n; i++) passed[i] = false;
    dfs_dist(origin_node, 0);

    for(int i=1; i<=n; i++) printf("%d ", ans[i]);
    return 0;
}