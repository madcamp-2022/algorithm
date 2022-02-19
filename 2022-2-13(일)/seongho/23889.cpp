#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N, M, K;
    cin >> N >> M >> K;
    vector<int> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    vector<int> vv(K);
    for(int i = 0; i < K; i++){
        int temp;
        cin >> temp;
        vv[i] = temp - 1;
    }

    vv.push_back(N);

    vector<pair<int,int>> vpii;

    for(int i = 0; i < vv.size() - 1; i++){
        int start = vv[i];
        int end = vv[i+1];
        int sum = 0;

        for(int j = start; j < end; j++){
            sum +=  v[j];
        }
        vpii.push_back({sum , start});
    }

    sort(vpii.begin(), vpii.end(), [](pair<int,int> a, pair<int,int> b) {
        return a.first != b.first ? a.first > b.first : a.second < b.second;
    });

    vector<int> answer;
    for(int i = 0; i < M; i++){
        answer.push_back(vpii[i].second + 1);
    }

    sort(answer.begin(), answer.end());
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << "\n"; 
    }

}