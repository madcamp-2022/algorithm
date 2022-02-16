#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, m;
long long ans = 0;
int main(void) {
    cin >> n >> m;
    LL left = (n - 1) * 2;
    LL right = (5 - n) * 2;
    ans += left / 2;
    if (n != 1 && n != 5) {
        ans += ((left + right) * (m / 2)) + (right * (m % 2 == 1));
    }
    else {
        ans += ((left + right) * (m));
    }
    cout << ans;
    return 0;
}
