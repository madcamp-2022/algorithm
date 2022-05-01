#include <bits/stdc++.h>

using namespace std;

int sum = 0;

int dp[1001];

int calc2(int a)
{
    return a * (a + 1) / 2;
}

int calc(int a)
{
    int temp = a - 1;
    int ret = 0;
    return (temp) * (temp + 1) * (2 * temp + 1) / 6;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t = 0;

    int N;
    cin >> N;

    if (N < 4)
    {
        cout << 0;
        return 0;
    }

    int sum = 0;

    int temp = sqrt(N);
    int rest = N - temp * temp;
    int answer = calc(temp);
    rest--;
    int k1 = temp - 2;
    int s = 0;
    while (rest > 0 && k1 >= 0)
    {
        s++;
        k1--;
        rest--;
    }
    answer += calc2(s);

    rest--;
    int k2 = temp - 2;
    int s2 = 0;
    while (rest > 0 && k2 >= 0)
    {
        rest--;
        s2++;
        k2--;
    }
    answer += calc2(s2);
    cout << answer << '\n';
}