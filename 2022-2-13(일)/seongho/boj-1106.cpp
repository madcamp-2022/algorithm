#include <bits/stdc++.h>

using namespace std;

vector<int> dp(2001, 987654321);

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int C, N;
    cin >> C >> N;

    vector<pair<int,int>> v(N);

    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};       
    }

    dp[0] = 0;

    for(int i = 1; i < 2001; i++){
        for(int j = 0; j < N; j++){
            int cost = v[j].first;
            int people = v[j].second;

            if(i - people >= 0){
                dp[i] = min(dp[i-people] + cost, dp[i]);
            }
        }
    }
    int answer = 987654321;
    for(int i = C; i < 2001; i++){
        answer = min(answer, dp[i]);
    }
    cout << answer;
}