#include <iostream>
#include <vector>
using namespace std;

// N個の正の整数 a0, a1, ..., aN-1 と正の整数 W が与えられます。これらのうちいくつかの整数を選んで総和によって得られる1以上 W 以下の整数がすべて作れるかどうかを O(NW) 時間で判定するアルゴリズムを設計してください。
int main() {
  // 入力
  int N;
  cin >> N;
  vector<long long> a(N);
  for (int i = 0; i < N; ++i)
    cin >> a[i];

  // DP テーブル
  int W = 10000;
  vector<vector<bool>> dp(N + 1, vector<bool>(W + 1, false));
  dp[0][0] = true;

  // ループ
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j <= W; ++j) {
      if (!dp[i][j])
        continue;
      dp[i + 1][j] = true;
      if (j + a[i] <= W)
        dp[i + 1][j + a[i]] = true;
    }
  }

  // 答え
  int res = 0;
  for (int j = 0; j <= W; ++j) {
    if (dp[N][j])
      ++res;
  }
  cout << res << endl;
}