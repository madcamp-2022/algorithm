#include <bits/stdc++.h>

using namespace std;

map<int, long long> m;
long long answer = 0;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<long long> v(N+1, 0);
    m[0] = 1;
    for(int i = 1; i <= N; i++){
        long long temp;
        cin >> temp;
        v[i] = (temp + v[i-1])%M;

        long long here = v[i];
        for(int j = 0; j * M <= here; j++){
            answer += m[(here - j * M)];
        }
        m[v[i]]++;
    }

    cout << answer;

}