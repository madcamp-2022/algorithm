#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, c, a[1110], b[1110], d[1110];
int main(){
	cin >> c >> n;
	for(int i=0;i<n;i++) cin >> a[i] >> b[i];
	for(int i=0;i<=c+100;i++) d[i] = 1e9;
	d[0] = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<=c+100;j++){
			if(j-b[i]>=0) d[j] = min(d[j], d[j-b[i]] + a[i]);
		}
	}
	int ans = 1e9;
	for(int i=c;i<=c+100;i++) ans = min(ans, d[i]);
	cout << ans;
}
