#include<bits/stdc++.h>
using namespace std;
long long n, a[100010], d[100010];
int main(){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	d[0] = 0;
	d[1] = a[1];
	for(int i=2;i<=n;i++) d[i] = max(d[i-1]+a[i], d[i-2]+a[i]*a[i-1]);
	cout << d[n];
}
