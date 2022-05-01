#include <bits/stdc++.h>

using namespace std;

int dp[51][1001];

int N, M, S;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> S >> M;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    dp[0][S] = 1;
    for (int i = 1; i <= N; i++)
    {
        int current = v[i - 1];
        for (int j = 0; j <= M; j++)
        {
            if (dp[i - 1][j])
            {
                int before = j - current;
                int after = j + current;

                if (before >= 0)
                {
                    dp[i][before] = 1;
                }
                if (after <= M)
                {
                    dp[i][after] = 1;
                }
            }
        }
    }
    int answer = -1;

    for (int i = 0; i <= M; i++)
    {
        if (dp[N][i])
        {
            answer = max(answer, i);
        }
    }
    cout << answer;
}