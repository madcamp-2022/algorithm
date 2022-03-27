#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[6][2] = {{},{0,},{1,7},{2,6},{3,5},{4,}};
ll b[6] = {0,1,2,2,2,1};
int main(){
	ll n, m;
	cin >> n >> m;
	cout << m/b[n]*8 + a[n][m%b[n]];
}
