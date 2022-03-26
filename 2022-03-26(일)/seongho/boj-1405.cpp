#include <bits/stdc++.h>

using namespace std;

int m[100][100];

double arr[4];
int N;
double answer = 0;

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};


void f(int y, int x, double t, int n){
    if(n == N){
        answer += t;
        return;
    }

    m[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(!m[ny][nx]){
            f(ny, nx,  t*arr[i]/100, n+1);
        }
    }
    m[y][x] = 0;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    f(50, 50, 1, 0);
    cout << fixed << setprecision(10) << answer;
}