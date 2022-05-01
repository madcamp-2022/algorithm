#include <bits/stdc++.h>

using namespace std;

vector<string> v;

void flip(int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            v[i][j] = '0' + ('1' - v[i][j]);
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N, M;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }

    int answer = 0;

    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = M - 1; j >= 0; j--)
        {
            if (v[i][j] == '1')
            {
                flip(i + 1, j + 1);
                answer++;
            }
        }
    }

    cout << answer;
}