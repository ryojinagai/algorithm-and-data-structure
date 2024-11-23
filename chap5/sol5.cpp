#include <iostream>
#include <vector>
// N個の正の整数 a0, a1, ..., aN-1 と正の整数 W が与えられます。これらの整数をそれぞれについて何回足してもよいとき、総和を W に一致させることができるかどうかを O(NW) 時間で判定するアルゴリズムを設計してください。
using namespace std;

int main() {
  // 入力
  int N, W;
  cin >> N >> W;
  vector<int> a(N);
  for (int i = 0; i < N; ++i)
    cin >> a[i];

  // DP テーブル
  vector<vector<bool>> dp(N + 1, vector<bool>(W + 1, false));

  // 初期条件
  dp[0][0] = true;

  // ループ
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j <= W; ++j) {
      if (dp[i][j])
        dp[i + 1][j] = true;
      if (j >= a[i] && dp[i + 1][j - a[i]])
        dp[i + 1][j] = true;
    }
  }

  // 答え
  if (dp[N][W])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}