#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

void insertion_sort_variant(vector<long long> *v, size_t L, size_t R,
                            bool plus) {
    // lower bound, middle bound, upper bound
    int lb, mb, ub;
    long long key;

    if (plus) {
        lb = L - 1;
        mb = R;
        ub = v->size();
    } else {
        lb = 0;
        mb = L - 1;
        ub = R - 1;
    }

    int i, j;
    for (i = mb; i < ub; ++i) {
        key = v->at(i);
        j = i - 1;

        while (j >= lb && v->at(j) > key) {
            v->at(j + 1) = v->at(j);
            j--;
        }
        v->at(j + 1) = key;
    }
}

int main() {
    fastio;

    int N, K;
    vector<long long> v;

    cin >> N >> K;

    long long n;
    while (N--) {
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());

    size_t L, R;
    long long X;
    while (K--) {
        cin >> L >> R >> X;
        if (X == 0)
            continue;

        for (int i = L - 1; i < R; i++) {
            v[i] += X;
        }

        insertion_sort_variant(&v, L, R, X > 0);
    }

    for (auto &i : v) {
        cout << i << " ";
    }
}
