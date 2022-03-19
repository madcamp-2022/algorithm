#include<bits/stdc++.h>
#define MOD 123456789
using namespace std;
int n, d[40010];
bool isprime(int n){
	if(n==2) return 1;
	for(int i=2;i*i<=n;i++) if(n%i==0) return 0;
	return 1;
}
vector<int> v;
int main(){
	cin >> n;
	d[0] = 1;
	for(int i=2;i<=n;i++) if(isprime(i)) v.push_back(i);
	for(int x:v){
		for(int i=x;i<=n;i++) {
			d[i] += d[i-x];
			d[i] %= MOD;
		}
	}
	cout << d[n];
}
