include<iostream>
#include <cmath>
#include <algorithm>

    using namespace std;

int dp[11][(1 << 11)];
int can[11];
int avil[11][11];

int dfs(int num, int where)
{
    if (num == 11)
        return 0;

    int &ret = dp[num][where];
    if (ret != -1)
        return ret;
    int p = can[num] & (~where);
    ret = -987654321;
    if (p == 0)
        return -987654321;
    for (int i = 0; i < 11; i++)
    {
        if ((p & (1 << i)))
        {
            ret = max(ret, dfs(num + 1, where | (1 << i)) + avil[num][i]);
        }
    }

    return ret;
}

int main()
{

    cin.tie(0);
    ios_base ::sync_with_stdio(0);

    int C;
    cin >> C;
    while (C--)
    {
        fill(can, can + 11, 0);
        for (int i = 0; i < 11; i++)
        {
            fill(dp[i], dp[i] + (1 << 11), -1);
            fill(avil[i], avil[i] + 11, 0);
        }

        for (int i = 0; i < 11; i++)
            for (int j = 0; j < 11; j++)
            {
                cin >> avil[i][j];
                if (avil[i][j] > 0)
                    can[i] |= (1 << j);
            }

        cout << dfs(0, 0) << '\n';
    }
}