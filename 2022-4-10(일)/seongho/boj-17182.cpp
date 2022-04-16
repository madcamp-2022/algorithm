#include <bits/stdc++.h>

using namespace std;

int n, start;
int m[11][11];
int dp[11][11];
int answer = 987654321;
int visit[10];

void f(int start, int cur)
{
	visit[start] = 1;
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		if (visit[i] == 0)
		{
			flag = false;
			f(i, cur + dp[start][i]);
		}
	}

	if (flag)
	{
		answer = min(answer, cur);
	}
	visit[start] = 0;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> start;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> m[i][j];
			dp[i][j] = 987654321;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				dp[j][k] = min({dp[j][k], m[j][i] + m[i][k], m[j][k]});
			}
		}
	}

	f(start, 0);
	cout << answer;
}