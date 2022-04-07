#include<bits/stdc++.h>
using namespace std;
int n, k, a[1010], d[31][1010];
int main(){
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) d[0][i] = d[0][i-1] + (a[i] == 1);
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			d[i][j] = max(d[i][j-1], d[i-1][j-1]) + (a[j] == (1+(i%2)));
		}
	}
	int ans = 0;
	for(int i=0;i<=k;i++) ans = max(ans, d[i][n]);
	cout << ans;
}
