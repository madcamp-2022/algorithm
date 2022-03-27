#include <bits/stdc++.h>
using namespace std;

int N;

int main(void) {
    cin >> N;
    vector<int> arr = {1};
    int cnt = 1;
    while(arr.back() <= N) {
        cnt++;
        arr.push_back(arr.back() + cnt);
    }
    
    vector<int> num = {arr[0]};
    for (int i = 1; i < arr.size(); i++) {
        arr[i] += arr[i - 1];
        if (arr[i] > N) break;
        num.push_back(arr[i]);
    }
    
    vector<int> dp(N + 1, 300000);
    dp[0] = 0;
    for (auto &n: num) {
        for (int i = n; i <= N; i++) {
            dp[i] = min((dp[i - n] + 1), dp[i]);
        }
    }
    cout << dp[N];
}
