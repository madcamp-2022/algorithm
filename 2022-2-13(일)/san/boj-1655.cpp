#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;

    int N, x;
    priority_queue<int> left;                             // max heap
    priority_queue<int, vector<int>, greater<int>> right; // min heap
    left.push(-100000);
    right.push(100000);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x;

        if (x <= right.top()) {
            left.push(x);
            if (left.size() > right.size()) {
                int tmp = left.top();
                left.pop();
                right.push(tmp);
            }

        } else {
            right.push(x);
            if (right.size() > left.size()) {
                int tmp = right.top();
                right.pop();
                left.push(tmp);
            }
        }

        if (i % 2) {
            cout << min(left.top(), right.top()) << "\n";
        } else {
            cout << (left.size() > right.size() ? left.top() : right.top())
                 << "\n";
        }
    }
}
