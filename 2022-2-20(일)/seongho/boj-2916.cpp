#include <bits/stdc++.h>

using namespace std;
using vii = vector<vector<int>>;

vii dp(10, vector<int>(361, false));
vector<int> v;
int N, K;

void f(int idx, int cur){

    if(idx == N){
        return;
    }

    int& ret = dp[idx][cur];
    if(ret)return;
    dp[idx][cur] = true;
    f(idx, (cur + v[idx])%360);
    f(idx, abs(cur - v[idx])%360);
    f(idx + 1, cur);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K;
    

    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

   while(K--){
       for(int i = 0; i < 10; i++){
           for(int j = 0; j < 361; j++){
               dp[i][j] = false;
           }
       }

        int temp;
        cin >> temp;
        f(0, 0);

        cout << (dp[N-1][temp] ? "YES" : "NO") << '\n';
    }

}