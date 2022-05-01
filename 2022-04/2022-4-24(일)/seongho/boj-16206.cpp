#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> v1;
    vector<int> v2;
    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        if (a < 10)
        {
            continue;
        }

        if (a == 10)
        {
            answer++;
            continue;
        }

        if (a % 10 == 0)
        {
            v1.push_back(a);
        }
        else
        {
            v2.push_back(a);
        }
    }

    sort(v1.begin(), v1.end());

    for (int temp : v1)
    {
        if (M == 0)
        {
            break;
        }
        int t = temp / 10;
        int m = min(t - 1, M);
        M -= m;
        answer += m + (temp - (m + 1) * 10 == 0);
    }

    for (int temp : v2)
    {
        if (M == 0)
        {
            break;
        }
        int t = temp / 10;
        int m = min(t, M);
        M -= m;
        answer += m;
    }

    cout << answer;
}
