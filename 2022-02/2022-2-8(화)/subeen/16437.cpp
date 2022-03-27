#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[200010];
vector<int> v[200010];
ll f(int cur){
    ll ret = a[cur];
    for(int nxt:v[cur]) ret += f(nxt);
    return max(ret, 0ll);
}
int main(){
    cin >> n;
    for(int i=2;i<=n;i++){
        char c; int t;
        cin >> c >> a[i] >> t;
        if(c=='W') a[i] = -a[i];
        v[t].push_back(i);
    }
    cout << f(1);
}