#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

int main()
{
   cin.tie(0);
   ios_base::sync_with_stdio(0);

   int N, K;
   cin >> N >> K;
   vector<pii> v(N + 1);
   for (int i = 1; i <= N; i++)
   {
      int a, b;
      cin >> a >> b;
      v[i] = {a, b};
   }

   vector<vector<int>> dp(N + 1, vector<int>(K + 1, -1));
   dp[0][0] = 0;
   int answer = 0;
   for (int i = 0; i < N; i++)
   {
      for (int j = 0; j <= K; j++)
      {
         int value = v[i + 1].second;
         int weight = v[i + 1].first;
         if (dp[i][j] != -1)
         {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            answer = max(dp[i + 1][j], answer);
            if (j + weight <= K)
            {
               dp[i + 1][j + weight] = max(dp[i + 1][j + weight], dp[i][j] + value);
               answer = max(answer, dp[i+1][j + weight]);
            }
         }
      }
   }
   cout << answer << '\n';
}