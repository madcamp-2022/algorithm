#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

// Sigma(n, k=1){k(k+1)/2} = n(n+1)(n+2)/6
int tetrahedron(int d) { return d * (d + 1) * (d + 2) / 6; }

int repeated_combination(vector<int> *src, vector<int> select, int index,
                         int depth, int target) {
    if (depth == select.size()) {
        // if full, check (sum == target)
        return (accumulate(select.begin(), select.end(), 0) == target)
                   ? select.size()
                   : -1;
    }

    int comb_size;
    for (int i = index; i < src->size(); i++) {
        select[depth] = src->at(i);
        comb_size = repeated_combination(src, select, i, depth + 1, target);
        if (comb_size > 0) {
            return comb_size;
        }
    }
    return -1; // fail
}

int search_combinations(vector<int> tetrahedrons, int target) {
    for (int i = 1; i <= target; i++) {
        vector<int> select(i);
        int comb_size =
            repeated_combination(&tetrahedrons, select, 0, 0, target);
        if (comb_size > 0) {
            return comb_size;
        }
    }

    return -1; // fail
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i = 1;
    vector<int> tetrahedrons;

    cin >> n;
    while (tetrahedron(i) <= n) {
        tetrahedrons.push_back(tetrahedron(i));
        i++;
    }

    cout << search_combinations(tetrahedrons, n) << endl;
}
