#include<bits/stdc++.h>
using namespace std;
int s1, e1, s2, e2, S1, S2, E1, E2, t1, t2;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s1 >> S1 >> e1 >> E1;
	cin >> s2 >> S2 >> e2 >> E2;
	
	if(e1<s2||e2<s1) t1 = 0;
	else if(e1==s2||e2==s1) t1 = 1;
	else t1 = 2;
	
	if(E1<S2||E2<S1) t2 = 0;
	else if(E1==S2||E2==S1) t2 = 1;
	else t2 = 2;
	
	if(t1 == 1 && t2 == 1) cout << "POINT";
	else if(t1 == 0 || t2 == 0) cout << "NULL";
	else if(t1 == 1 || t2 == 1) cout << "LINE";
	else cout << "FACE";
}
