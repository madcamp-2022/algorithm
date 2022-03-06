#include <bits/stdc++.h>
using namespace std;
enum Move {NONE, EAST, WEST, NORTH, SOUTH};

int N, M, X, Y, K;
vector<vector<int>> Map;
vector<int> Cmd;

vector<int> Dice(7, 0);
vector<int> RollDice = {1, 5, 6, 2};
vector<int> RotateDice = {1, 3, 6, 4};

bool checkMove(int x, int y) {
    if (x == N || x < 0) return false;
    if (y == M || y < 0) return false;
    return true;
}

void turnDice(int move) {
    switch(move) {
        case EAST:
            RotateDice.insert(RotateDice.begin(), RotateDice.back());
            RotateDice.pop_back();
            RollDice[0] = RotateDice[0];
            RollDice[2] = RotateDice[2];
            break;
        case WEST:
            RotateDice.push_back(RotateDice.front());
            RotateDice.erase(RotateDice.begin());
            RollDice[0] = RotateDice[0];
            RollDice[2] = RotateDice[2];
            break;
        case NORTH:
            RollDice.push_back(RollDice.front());
            RollDice.erase(RollDice.begin());
            RotateDice[0] = RollDice[0];
            RotateDice[2] = RollDice[2];
            break;
        case SOUTH:
            RollDice.insert(RollDice.begin(), RollDice.back());
            RollDice.pop_back();
            RotateDice[0] = RollDice[0];
            RotateDice[2] = RollDice[2];
            break;
    }
    
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M >> X >> Y >> K;
    Map = vector<vector<int>>(N, vector<int>(M));
    Cmd = vector<int>(K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) { cin >> Map[i][j]; }
    }
    for (int i = 0; i < K; i++) { cin >> Cmd[i]; }
    
    for (int cmd: Cmd) {
        switch(cmd) {
            case EAST:
                if (!checkMove(X, Y + 1)) break;
                Y++;
                turnDice(cmd);
                cout << Dice[RollDice[0]] << endl;
                if (Map[X][Y] == 0) Map[X][Y] = Dice[RollDice[2]];
                else {
                    Dice[RollDice[2]] = Map[X][Y];
                    Map[X][Y] = 0;
                }
                break;
            case WEST:
                if (!checkMove(X, Y - 1)) break;
                
                Y--;
                turnDice(cmd);
                cout << Dice[RollDice[0]] << endl;
                if (Map[X][Y] == 0) Map[X][Y] = Dice[RollDice[2]];
                else {
                    Dice[RollDice[2]] = Map[X][Y];
                    Map[X][Y] = 0;
                }
                break;
            case NORTH:
                if (!checkMove(X - 1, Y)) break;
                
                X--;
                turnDice(cmd);
                cout << Dice[RollDice[0]] << endl;
                if (Map[X][Y] == 0) Map[X][Y] = Dice[RollDice[2]];
                else {
                    Dice[RollDice[2]] = Map[X][Y];
                    Map[X][Y] = 0;
                }
                break;
            case SOUTH:
                if (!checkMove(X + 1, Y)) break;
                
                X++;
                turnDice(cmd);
                cout << Dice[RollDice[0]] << endl;
                if (Map[X][Y] == 0) Map[X][Y] = Dice[RollDice[2]];
                else {
                    Dice[RollDice[2]] = Map[X][Y];
                    Map[X][Y] = 0;
                }
                break;
        }
        
    }
    
    
    
    return 0;
}

