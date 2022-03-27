#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int board[20][20];
int dice[6]; // dice[0]이 윗면
int dice1[6];
int n, m, x, y, k, cmd; // x:[0,n) y:[0,m)

bool InBound(int r, int c) {
    return (r >= 0) && (r < n) && (c >= 0) && (c < m);
}

void Vtrans() {
    if(!board[x][y]){
        board[x][y] = dice[5];
    } else {
        dice[5] = board[x][y];
        board[x][y] = 0;
    }
}

bool go_east() {
    if(!InBound(x, y+1)) return false;
    for(int j=0; j<6; j++) dice1[j] = dice[j];
    
    y++;
    dice[0] = dice1[3];
    dice[1] = dice1[1];
    dice[2] = dice1[0];
    dice[3] = dice1[5];
    dice[4] = dice1[4];
    dice[5] = dice1[2];
    
    Vtrans();
    return true;
}

bool go_west() {
    if(!InBound(x, y-1)) return false;
    for(int j=0; j<6; j++) dice1[j] = dice[j];

    y--;
    dice[0] = dice1[2];
    dice[1] = dice1[1];
    dice[2] = dice1[5];
    dice[3] = dice1[0];
    dice[4] = dice1[4];
    dice[5] = dice1[3];

    Vtrans();
    return true;
}

bool go_north() {
    if(!InBound(x-1, y)) return false;
    for(int j=0; j<6; j++) dice1[j] = dice[j];

    x--;
    dice[0] = dice1[4];
    dice[1] = dice1[0];
    dice[2] = dice1[2];
    dice[3] = dice1[3];
    dice[4] = dice1[5];
    dice[5] = dice1[1];

    Vtrans();
    return true;
}

bool go_south() {
    if(!InBound(x+1, y)) return false;
    for(int j=0; j<6; j++) dice1[j] = dice[j];

    x++;
    dice[0] = dice1[1];
    dice[1] = dice1[5];
    dice[2] = dice1[2];
    dice[3] = dice1[3];
    dice[4] = dice1[0];
    dice[5] = dice1[4];

    Vtrans();
    return true;
}

int main(void) {
    bool inb;
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
            scanf("%d", &board[i][j]);
    }

    for(int i=0; i<k; i++) {
        scanf("%d", &cmd);

        if(cmd == 1) {
            inb = go_east();
        } else if(cmd == 2) {
            inb = go_west();
        } else if(cmd == 3) {
            inb = go_north();
        } else if(cmd == 4) {
            inb = go_south();
        }
        
        if(inb) printf("%d\n", dice[0]);
    }

    return 0;
}