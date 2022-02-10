#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[100010],b[100010];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i]; a[n] = b[n] = 2e18;
    sort(a,a+n);
    while(k--){
        int l,r,x;
        cin >> l >> r >> x;
        l--;
        int i=0, j=l, p=0;
        while(p<n){
            if(i==l) i=r;
            if(j==r) j=n;
            if(a[i] < a[j]+x) b[p++] = a[i++];
            else b[p++] = a[j++]+x;
        }
        swap(a,b);
    }
    for(int i=0;i<n;i++) cout << a[i] << " ";
}