#include <bits/stdc++.h>

using namespace std;

string a, b;
int n;

void f(string &temp, int idx)
{
    for (int i = -1; i <= 1; i++)
    {
        if (idx + i >= 0 && idx + i < n)
        {
            temp[idx + i] = '0' + ('1' - temp[idx + i]);
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    cin >> a >> b;
    string c = a;

    int answer1 = 0;
    int answer2 = 0;

    for (int i = 1; i < n; i++)
    {
        if (i - 1 >= 0 && a[i - 1] != b[i - 1])
        {
            answer1++;
            f(a, i);
        }
    }

    f(c, 0);
    answer2++;
    for (int i = 0; i < n; i++)
    {
        if (i - 1 >= 0 && c[i - 1] != b[i - 1])
        {
            answer2++;
            f(c, i);
        }
    }

    if (a == b && c == b)
    {
        cout << min(answer1, answer2) << '\n';
    }
    else if (a == b)
    {
        cout << answer1;
    }
    else if (c == b)
    {
        cout << answer2;
    }
    else
    {
        cout << -1 << '\n';
    }
}