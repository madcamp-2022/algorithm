#include<bits/stdc++.h>
using namespace std;
int a[200][200], cnt, y, x, k, l;

void place(int k, int x0, int y0, int m){
	int l = 1<<(k-1);
	if(k==1) {
		cnt++;
		for(int i=0;i<4;i++) if(i!=m) a[y0+(i/2)][x0+(i%2)] = cnt;
		return;
	}
	place(k-1, x0+l/2, y0+l/2, m);
	for(int i=0;i<4;i++) if(i!=m) place(k-1, x0+l*(i%2), y0+l*(i/2), 3-i);
}

void solve(int k, int x0, int y0){
	if(k==0) return;
	int l = 1<<(k-1), i = (y-y0)/l, j = (x-x0)/l; 
	place(k, x0, y0, i*2+j); solve(k-1, x0+l*j, y0+l*i);
}

int main(){
	cin >> k >> x >> y;
	
	l = 1<<k;
	x--; y = l-y;
	
	a[y][x] = -1;
	solve(k, 0, 0);
	for(int i=0;i<l;i++){
		for(int j=0;j<l;j++) cout << a[i][j] << " ";
		cout << "\n";
	}
}
