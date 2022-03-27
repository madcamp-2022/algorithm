#include<bits/stdc++.h>
using namespace std;
int a[7], b[7];

void N(){
	b[1] = a[5];
	b[5] = a[6];
	b[6] = a[2];
	b[2] = a[1];
	b[3] = a[3];
	b[4] = a[4];
	swap(a,b);
}

void S(){
	N();N();N();
}

void E(){
	b[1] = a[4];
	b[4] = a[6];
	b[6] = a[3];
	b[3] = a[1];
	b[2] = a[2];
	b[5] = a[5];
	swap(a,b);
}

void W(){
	E();E();E();
}

int dx[5] = {0,1,-1,0,0};
int dy[5] = {0,0,0,-1,1};

int n, m, x, y, k, c[30][30];

int main(){
	cin >> n >> m >> y >> x >> k;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> c[i][j];
	for(int i=0;i<k;i++){
		int t;
		cin >> t;
		int xx = x+dx[t];
		int yy = y+dy[t];
		if(xx<0||yy<0||xx>=m||yy>=n) continue;
		if(t==1) E();
		else if(t==2) W();
		else if(t==3) N();
		else if(t==4) S();
		x = xx; y = yy;
		if(c[y][x]) {
			a[6] = c[y][x];
			c[y][x] = 0;
		} else {
			c[y][x] = a[6];
		}
		cout << a[1] << "\n";
	}
}
