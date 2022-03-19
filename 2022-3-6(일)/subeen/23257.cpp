#include<bits/stdc++.h>
using namespace std;
set<int> s[110];
int n, m, a[110];
int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		a[i] = abs(a[i]);
	}
	s[0].insert(0);
	for(int i=1;i<=m;i++){
		for(int x:s[i-1]){
			for(int j=0;j<n;j++) s[i].insert(x^a[j]);
		}
	}
	cout << *s[m].rbegin();
}
