#include <bits/stdc++.h>

using namespace std;

int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1,0,0};
vector<string> m;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> visit(N+1, vector<int>(M+1, 0));
    int sy = 0;
    int sx = 0;

    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        m.push_back(str);
        for(int j = 0; j < M; j++){
            if(str[j] == 'I'){
                sx = j;
                sy = i;
            }
        }
    }

    queue<pair<int,int>> q;
    q.push({sy, sx});
    visit[sy][sx] = 1;
    int answer = 0;

    while(!q.empty()){
        auto temp = q.front(); q.pop();
        int hy = temp.first;
        int hx = temp.second;

        if(m[hy][hx] == 'X')continue;
        if(m[hy][hx] == 'P')answer++;

        for(int i = 0; i < 4; i++){
            int nx = dx[i] + hx;
            int ny = dy[i] + hy;
            if(ny < 0 || ny >= N)continue;
            if(nx < 0 || nx >= M)continue;
            if(visit[ny][nx])continue;
            visit[ny][nx] = 1;
            q.push({ny, nx});
        }
    }

    if(answer == 0){
        cout << "TT";
    } else {
        cout << answer;
    }

}