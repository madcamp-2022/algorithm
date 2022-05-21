#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll MOD = 1e9 + 7;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int N;
    cin >> N;

    long long sum = 0;
    long long answer = 0;

    for (int i = 0; i < N - 1; i++)
    {
        ll temp;
        cin >> temp;

        sum *= temp;
        sum %= MOD;
        sum += temp;
        sum %= MOD;
        answer += sum;
        answer %= MOD;
    }

    cout << answer;
}