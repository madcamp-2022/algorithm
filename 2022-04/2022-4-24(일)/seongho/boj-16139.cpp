#include <bits/stdc++.h>

using namespace std;

const int range = 'z' - 'a' + 1;

int arr[200'001][range];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string str;
    cin >> str;
    int temp = str[0] - 'a';
    arr[0][temp] = 1;
    for (int i = 1; i < str.size(); i++)
    {
        int cur = str[i] - 'a';
        for (int j = 0; j < range; j++)
        {
            arr[i][j] = arr[i - 1][j];
        }
        arr[i][cur]++;
    }

    for (int j = 0; j < range; j++)
    {
        arr[str.size()][j] = arr[str.size() - 1][j];
    }

    int q;
    cin >> q;
    while (q--)
    {
        char a;
        int b, c;
        cin >> a >> b >> c;
        int aa = a - 'a';
        cout << arr[c][aa] - (b != 0 ? arr[b - 1][aa] : 0) << '\n';
    }
}