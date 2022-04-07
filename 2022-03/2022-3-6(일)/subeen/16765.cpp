#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100010];
long long d[100010];
int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	d[0]=a[0];
	for(int i=1;i<n;i++){
		int now = a[i];
		long long mx = a[i]+d[i-1];
		for(int j=1;j<k;j++){
			if(i-j<0) break;
			now = max(now,a[i-j]);
			mx = max(mx,now*(j+1)+d[i-j-1]);
		}
		d[i] = mx;
	}
	printf("%lld",d[n-1]);
}
