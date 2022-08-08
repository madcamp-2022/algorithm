#include <bits/stdc++.h>

using namespace std;

int current = 1;

int visit[50001];

string f(string s, int start, int k)
{
    string nextStr = "";

    for (int i = 0; i < start; i++)
    {
        nextStr += s[i];
    }

    for (int i = 0; i < k; i++)
    {
        nextStr += s[start + (k - i - 1)];
    }

    for (int i = start + k; i < s.length(); i++)
    {
        nextStr += s[i];
    }

    return nextStr;
}

int main()
{
    map<string, int> m;

    int N;
    cin >> N;

    vector<int> v;
    int target = 0;
    for (int i = 0; i < N; i++)
    {
        v.push_back(i + 1);
    }

    do
    {
        int temp = 0;
        for (int i = 0; i < N; i++)
        {
            temp *= 10;
            temp += v[i];
        };
        m[to_string(temp)] = current++;
    } while (next_permutation(v.begin(), v.end()));

    int K;
    cin >> K;
    int startNum = 0;
    for (int i = 0; i < N; i++)
    {
        int c;
        cin >> c;
        startNum *= 10;
        startNum += c;
    }

    queue<pair<string, int>> q;
    q.push({to_string(startNum), 0});
    visit[m[to_string(startNum)]] = 1;

    while (!q.empty())
    {
        auto here = q.front();
        q.pop();
        string hereString = here.first;

        int hereNum = m[hereString];
        int depth = here.second;

        // cout << "hereString =" << hereString << '\n';
        // cout << "hereNum=" << hereNum << '\n';

        if (hereNum == 1)
        {
            cout << depth;
            return 0;
        }

        for (int i = 0; i <= N - K; i++)
        {
            string nextString = f(hereString, i, K);
            // cout << "nextString = " << nextString << '\n';
            int nextNum = m[nextString];

            if (visit[nextNum])
            {
                continue;
            }

            visit[nextNum] = 1;
            q.push({nextString, depth + 1});
        }
    }

    cout << -1 << '\n';
}