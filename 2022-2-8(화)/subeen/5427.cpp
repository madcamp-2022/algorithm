#include<bits/stdc++.h>
#define fi first
#define se second

using namespace std;
typedef pair<int,int> pii;
typedef pair<pii, int> piii;

int n, m, a[1010][1010], b[1010][1010];
bool vis[1010][1010];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    
    while(T--){
        cin >> m >> n;
        queue<piii> q;
        pii start;
        for(int i=0;i<n;i++){
            string t;
            cin >> t;
            for(int j=0;j<m;j++){
                if(t[j]=='#') a[i][j] = 1;
                else {
                    a[i][j] = 0;
                    if(t[j]=='*') q.push({{i,j},0});
                    if(t[j]=='@') start = {i,j};
                }
            }
        }
        memset(vis,0,sizeof(vis));
        memset(b,-1,sizeof(b));
        while(!q.empty()){
            int y = q.front().fi.fi;
            int x = q.front().fi.se;
            int dis = q.front().se;
            q.pop();
            if(vis[y][x]) continue;
            vis[y][x] = 1;
            b[y][x] = dis;
            for(int i=0;i<4;i++){
                int yy = y + dy[i];
                int xx = x + dx[i];
                if(xx<0||yy<0||xx>=m||yy>=n||vis[yy][xx]||a[yy][xx]) continue;
                q.push({{yy,xx},dis+1});
            }
        }
        memset(vis,0,sizeof(vis));
        q.push({start, 0});
        int ans = -1;
        while(!q.empty()){
            int y = q.front().fi.fi;
            int x = q.front().fi.se;
            int dis = q.front().se;
            q.pop();
            if(vis[y][x]) continue;
            vis[y][x] = 1;
            for(int i=0;i<4;i++){
                int yy = y + dy[i];
                int xx = x + dx[i];
                if(xx<0||yy<0||xx>=m||yy>=n) {
                    ans = dis+1;
                    goto result;
                }
                if(vis[yy][xx]||a[yy][xx]||(b[yy][xx]!=-1&&dis+1>=b[yy][xx])) continue;
                q.push({{yy,xx},dis+1});
            }
        }
    result:
        if(ans==-1) cout << "IMPOSSIBLE\n";
        else cout << ans << "\n";
    }
}