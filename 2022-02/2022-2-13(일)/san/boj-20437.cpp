#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;

    int T, k;
    string w;

    cin >> T;
    while (T--) {
        cin >> w >> k;

        // pair : index, occurence
        map<char, deque<int>> m;
        int ans1 = 10001, ans2 = -1;

        for (int i = 0; i < w.length(); i++) {
            if (m.find(w[i]) != m.end()) {
                (&m.at(w[i]))->push_back(i);
            } else {
                m.insert({w[i], {i}});
            }

            deque<int> *q = &m.at(w[i]);
            if (q->size() == k) {
                ans1 = min(ans1, q->back() - q->front() + 1);
                ans2 = max(ans2, q->back() - q->front() + 1);
                q->pop_front();
            }
        }

        if (ans1 == 10001 || ans2 == -1)
            cout << -1 << "\n";
        else {
            cout << ans1 << " " << ans2 << "\n";
        }
    }
}
