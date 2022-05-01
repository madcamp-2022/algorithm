#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int mxx = 0;
map<int, int> mx;
int myy = 0;
map<int, int> my;
map<int, set<int>> s;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<pair<int, int>> mv(N);

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        if (mx[b] == 0)
        {
            mx[b] = ++mxx;
        }
        if (my[a] == 0)
        {
            my[a] = ++myy;
        }
        int ma = my[a];
        int mb = mx[b];
        mv[i] = {ma, mb};
    }

    for (int i = 0; i < N; i++)
    {
        s[mv[i].first].insert(mv[i].second);
    }

    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            pii first = mv[i];
            pii second = mv[j];

            if (first.first != second.first && first.second != second.second)
            {
                int firstY = first.first;
                int firstX = first.second;
                int secondY = second.first;
                int secondX = second.second;

                if (s[firstY].find(secondX) != s[firstY].end() && s[secondY].find(firstX) != s[secondY].end())
                {
                    answer++;
                }
            }
        }
    }

    cout << answer / 2;
}