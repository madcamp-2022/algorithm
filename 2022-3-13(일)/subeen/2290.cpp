#include<bits/stdc++.h>
using namespace std;
int s;
char a[25][200];
int b[10][10] = {
	{0,1,2,4,5,6,-1},
	{2,6,-1},
	{1,2,3,4,5,-1},
	{1,2,3,5,6,-1},
	{0,2,3,6,-1},
	{0,1,3,5,6,-1},
	{0,1,3,4,5,6,-1},
	{1,2,6,-1},
	{0,1,2,3,4,5,6,-1},
	{0,1,2,3,5,6,-1},
};
string t;
int offx;

void f(int n){
	if(n%2) for(int i=1;i<=s;i++) a[(s+1)*(n/2)][offx + i] = '-';
	else for(int i=1;i<=s;i++) a[(s+1)*(n/4) + i][offx + (s+1)*((n/2)%2)] = '|';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s >> t;
	int n = t.size();
	for(int i=0;i<n;i++) {
		int x = t[i] - '0';
		for(int j=0;b[x][j]!=-1;j++) f(b[x][j]);
		offx += s+3;
	} 
	for(int i=0;i<2*s+3;i++){
		for(int j=0;j<(s+3)*n;j++){
			if(!a[i][j]) cout << " ";
			else cout << a[i][j];
		} 
		cout << "\n";
	}
	
}
