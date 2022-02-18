#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
    ll n, m, ans;
    scanf("%lld %lld", &n, &m);
    if(n == 1) {
        ans = 8*m;
    } else if(n == 5) {
        ans = 8*m + 4;
    } else {
        if(m%2) {
            ans = 4*m + 5 - n;
        } else {
            ans = 4*m + n - 1;
        }
    }

    printf("%lld", ans);
    return 0;
}