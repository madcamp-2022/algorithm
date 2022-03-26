#include <bits/stdc++.h>

using namespace std;

vector<int> v[100'001];

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }

    for(int i = 0; i < 100'001; i++){
        sort(v[i].begin(), v[i].end());
    }

    long long answer = 0;

    for(int i = 0; i < 100'001; i++){
        if(v[i].size() == 0 || v[i].size() == 1)continue;

        for(int j = 0; j < v[i].size(); j++){
            int before = j - 1;
            int next = j + 1;
            int len = 1e9 + 1000;
            if(before >= 0){
                len = min(len, v[i][j] - v[i][before]);
            }
            if(next < v[i].size()){
                len = min(len, v[i][next] - v[i][j]);
            }
            answer += len;
        }
    }

    cout << answer << '\n';
}