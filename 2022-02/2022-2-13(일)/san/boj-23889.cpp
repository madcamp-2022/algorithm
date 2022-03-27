#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;

    int N, M, K, x, x2;
    vector<int> v = {0};
    vector<int> r;
    priority_queue<pair<int, int>> pq;

    // input
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < K; i++) {
        cin >> x;
        r.push_back(x);
    }

    int total;
    for (int i = 0; i < K; i++) {
        total = 0;
        x = r[i];
        x2 = i == K - 1 ? N + 1 : r[i + 1];

        for (int j = x; j < x2; j++) {
            total += v[j];
        }
        // push negative index for ascending order
        pq.push({total, -x});
    }

    vector<int> ans;
    for (int i = 0; i < M; i++) {
        ans.push_back(-pq.top().second);
        pq.pop();
    }
    sort(ans.begin(), ans.end());

    for (auto a : ans) {
        cout << a << "\n";
    }
}
