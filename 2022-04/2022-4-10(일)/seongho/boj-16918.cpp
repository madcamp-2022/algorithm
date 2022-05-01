#include <bits/stdc++.h>

using namespace std;

string m[201];
vector<vector<int>> v(201, vector<int>(201, -1));
int R, C, N;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void countDown()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            v[i][j] = max(-1, v[i][j] - 1);
        }
    }
}

void bomb()
{
    queue<pair<int, int>> q;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (v[i][j] == 0)
            {
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        auto hy = q.front().first;
        auto hx = q.front().second;
        q.pop();

        v[hy][hx] = -1;
        for (int i = 0; i < 4; i++)
        {
            int ny = hy + dy[i];
            int nx = hx + dx[i];

            if (ny >= 0 && ny < R && nx >= 0 && nx < C)
            {
                v[ny][nx] = -1;
            }
        }
    }
}

void setBomb()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (v[i][j] == -1)
            {
                v[i][j] = 3;
            }
        }
    }
}

void setInitBomb()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (m[i][j] == 'O')
            {
                v[i][j] = 3;
            }
        }
    }
}

void print()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << (v[i][j] == -1 ? '.' : 'O');
        }
        cout << '\n';
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> R >> C >> N;

    for (int i = 0; i < R; i++)
    {
        cin >> m[i];
    }

    for (int i = 0; i <= N; i++)
    {
        countDown();
        if (i == 0)
        {
            setInitBomb();
        }
        if (i % 2 == 0 && i != 0)
        {
            setBomb();
        }
        bomb();
    }
    print();
}