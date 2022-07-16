#include <bits/stdc++.h>

using namespace std;

int main()
{
    deque<pair<int, int>> dq;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp > 0)
        {
            temp--;
        }
        dq.push_back({temp, i + 1});
    };

    int current = 0;

    while (!dq.empty())
    {
        if (current == 0)
        {
            pair<int, int> temp = dq.front();
            dq.pop_front();

            int first = temp.first;
            int second = temp.second;

            current = first;
            cout << second << ' ';
        }
        else if (current < 0)
        {
            current++;
            auto temp = dq.back();
            dq.pop_back();
            dq.push_front(temp);
        }
        else
        {
            current--;
            auto temp = dq.front();
            dq.pop_front();
            dq.push_back(temp);
        }
    }
}