#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ans;
int main(){
    cin >> n;
    for(int i=1;i<=n;i++) ans += n/i*i;
    cout << ans;
}