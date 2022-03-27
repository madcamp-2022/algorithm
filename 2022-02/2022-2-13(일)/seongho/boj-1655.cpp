#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct cmp{

	bool operator()(int a, int b){
		return a > b;
	}
	
};

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	int N, middle;
	cin >> N;
	priority_queue<int,vector<int>,cmp> big;
	priority_queue<int> small;
	small.push(-987654321);
	big.push(987654321);
	
	cin >> middle;
	cout << middle << '\n';
	int flag = 0;
	for(int i = 1,t; i < N; i++){
		cin >> t;
		
		if(t > middle)big.push(t);
		else{small.push(t);}
		
		while(!(big.size()-small.size() == 1 || big.size()-small.size() == 0)){
				int bignum = big.top();
			int smallnum = small.top();
			if((int)small.size()-(int)big.size() > 0){
				small.pop();
				big.push(middle);
				middle = smallnum;
			}
			else{
				big.pop();
				small.push(middle);
				middle = bignum;
			}
		}
		cout << middle << '\n';
		
	}
	
	
	
}