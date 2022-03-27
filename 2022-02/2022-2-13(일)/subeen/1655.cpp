#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
priority_queue<int> maxpq;
priority_queue<int,vector<int>,greater<int>> minpq;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	
	maxpq.push(-1e9);
	minpq.push(1e9);
	
	for(int i=0;i<n;i++){
		int t;
		cin >> t;
		if(maxpq.top() >= t) maxpq.push(t);
		else minpq.push(t);
		
		while(maxpq.size() < i/2+2){
			maxpq.push(minpq.top());
			minpq.pop();
		}
		while(maxpq.size() > i/2+2){
			minpq.push(maxpq.top());
			maxpq.pop();
		}
		cout << maxpq.top() << "\n";
	}
}
