#include<bits/stdc++.h>
using namespace std;
char s[20];
char t[20];

int a[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int z[19];
int c[19] = {10,9,8,7,6,5,4,3,2,10,9,8,7,6,5,4,3,2};

typedef long long ll;

inline void format(int d, int m, int y){
	z[0] = d/10;
	z[1] = d%10;
	z[2] = m/10;
	z[3] = m%10;
	z[4] = y/1000;
	z[5] = (y/100)%10;
	z[6] = (y/10)%10;
	z[7] = y%10;
	
	for(int i=0;i<8;i++) t[i] = '0' + z[i];
}

bool check(){
	for(int i=0;i<8;i++) {
		if(s[i] == t[i] || s[i] == 'X');
		else return 0;
	}
	return 1;
}

ll d[20][20][20];

ll f(){
	int t = 0;
	for(int i=0;i<8;i++) {
		t += z[i]*c[i];
		t %= 19;
	}
	if(s[18] == 'X'){
		ll sum = 0;
		for(int i=0;i<19;i++) sum += d[t][17][i];
		return sum;
	} else {
		int t1 = s[18] - '0';
		int t2 = 19 - t1;
		return d[t][17][t1] + d[t][17][t2];
	}
	
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	
	for(int i=0;i<19;i++){
		d[i][7][i] = 1;
		for(int j=8;j<18;j++){
			for(int k=0;k<19;k++){
				if(s[j] != 'X'){
					d[i][j][k] = d[i][j-1][(k-c[j]*(s[j]-'0')+19*19)%19];
				} else {
					for(int l=0;l<10;l++){
						d[i][j][k] += d[i][j-1][(k-c[j]*l+19*19)%19];
					}
				}
			}
		}
	}
	
	ll ans = 0;
	for(int i=1;i<=9999;i++){
		for(int j=1;j<=12;j++){
			int m = a[j];
			if(j==2) if((i%4==0 && i%100!=0) || i%400==0) m++;
			for(int k=1;k<=m;k++){
				format(k,j,i);
				if(!check()) continue;
				ans += f();
			}
		}
	}
	cout << ans;
}
