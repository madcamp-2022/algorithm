#include<bits/stdc++.h>
using namespace std;
int n, d[300010];
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        d[i] = 1e9;
        for(int j=1;;j++){
            int t = j*(j+1)*(j+2)/6;
            if(i-t<0) break;
            d[i] = min(d[i],d[i-t]+1);
        }
    }
    cout << d[n];
}