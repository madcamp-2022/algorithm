#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;

    long n, m, ans;
    cin >> n >> m;

    if (n == 1 || n == 5) {
        ans = (n == 1 ? 0 : 4) + 8 * m;
    } else {
        ans = 1 + 4 * m + (m % 2 ? 4 - n : n - 2);
    }

    cout << ans << endl;
}
