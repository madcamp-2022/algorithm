#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        map<long long, int> m;
        int T;
        cin >> T;

        long long c = (T / 2) + 1;
        long long answer = -1;
        bool hasAnswer = false;
        for (int j = 0; j < T; j++)
        {
            long long k;
            cin >> k;
            long long temp = ++m[k];
            if (temp >= c)
            {
                answer = k;
                hasAnswer = true;
            }
        }

        if (!hasAnswer)
        {
            cout << "SYJKGW" << '\n';
            continue;
        }
        cout << answer << '\n';
    }
}