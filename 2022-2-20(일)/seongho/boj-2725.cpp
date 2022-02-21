#include <bits/stdc++.h>

using namespace std;

int dp[1001];
set<float> s;

int f(int idx){
    int sum = 0;
    for(int i = 1; i < idx; i++){
        if(s.find((float)i/idx) == s.end()){
            sum++;
            s.insert((float)i/idx);
        }

        if(s.find((float)idx/i) == s.end()){
            sum++;
            s.insert((float)idx/i);
        }
    }
    return sum;
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    dp[1] = 3;

    for(int i = 2; i <= 1000; i++){
        dp[i] = dp[i-1] + f(i);
    }

    int T;
    cin >> T;
    while(T--){
        int temp;
        cin >> temp;
        cout << dp[temp] << '\n';
    }
}